#include "runner.hh"

#include "isr_base.hh"
#include "isr_extend.hh"
#include "hal/core.hh"
#include "hal/exti.hh"
#include "hal/gpio.hh"
#include "hal/pwr.hh"
#include "hal/rcc.hh"
#include "hal/rtc.hh"
#include "hal/tim.hh"

#include "bsp/st_hex_lcd.hh"

namespace {
    const uint32_t ld3_green{7};
    const uint32_t ld4_blue{6};
    const uint32_t all_leds = hal::value_of(ld3_green, ld4_blue);
    static bool foward = true;
    const int add_value = 10;
}

extern "C" void isr::sys_tick_timer() {
    hal::tim4->capt_comp_mode1.oc2m ^= 0b001;
}

extern "C" void isr::TIM4() {
    if (hal::tim4->status.uif) {
        if (foward) {
            if (hal::tim4->ccr1 < 10)
                foward = false;
            else {
                hal::tim4->ccr1 -= add_value;
                hal::tim4->ccr2 -= add_value;
            }
        } else {
            if (hal::tim4->ccr1 > 1000)
                foward = true;
            else {
                hal::tim4->ccr1 += add_value;
                hal::tim4->ccr2 += add_value;
            }
        }
        hal::tim4->status.uif = 0;
    }
}

extern "C" void isr::RTC_wkup() {
    if (hal::rtc->init_status.wutf) {
        runner::view_rtc_time();

        hal::rtc->init_status.wutf = 0;
    }
}

static void setup_gpio() {
    // enable led and lcd port
    hal::rcc->ahb_enable.gpioa = 1;
    hal::rcc->ahb_enable.gpiob = 1;
    hal::rcc->ahb_enable.gpioc = 1;

    // enable lcd pins
    hal::gpioa->set_mode(hal::pin_mode_t::alt_func,
        1, 2, 3, 8, 9, 10, 15);
    hal::gpioa->set_alt_func(11,
        1, 2, 3, 8, 9, 10, 15);
    hal::gpiob->set_mode(hal::pin_mode_t::alt_func,
        3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 15);
    hal::gpiob->set_alt_func(11,
        3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 15);
    hal::gpioc->set_mode(hal::pin_mode_t::alt_func,
        0, 1, 2, 3, 6, 7, 8, 9, 10, 11);
    hal::gpioc->set_alt_func(11,
        0, 1, 2, 3, 6, 7, 8, 9, 10, 11);

    // enable led pins, connect to tim4 output
    hal::gpiob->set_mode(hal::pin_mode_t::alt_func,
        ld3_green, ld4_blue);
    hal::gpiob->set_alt_func(2,
        ld3_green, ld4_blue);
}

static void setup_lcd_pwr() {
    // enable lcd and pwr module
    hal::rcc->apb1_enable.pwr = 1;
    hal::rcc->apb1_enable.lcd = 1;

    // disable clock protection for rtc/lcd
    hal::pwr->control.dbp = 1;

    // reset clock rtc/lcd
    hal::rcc->control_status.rtcrst = 1;
    hal::rcc->control_status.rtcrst = 0;

    // enable LSE and wait it stable
    hal::rcc->control_status.lseon = 1;
    while (hal::rcc->control_status.lserdy != 1);

    // set LSE for clocking rtc/lcd
    hal::rcc->control_status.rtcsel = 0b01;
}

static void setup_timer4() {
    // setup tim4
    hal::rcc->apb1_enable.tim4 = 1;
    // setup tim4 counter block
    hal::tim4->psc = 40 - 1;
    hal::tim4->arr = 1000;
    // setup tim4 compare blocks 1, 2

    // setup tim4 compare blocks to output
    hal::tim4->capt_comp_mode1.cc1s = 0b00;
    hal::tim4->capt_comp_mode1.cc2s = 0b00;
    // setup tim4 compare blocks to pwm mode 1
    hal::tim4->capt_comp_mode1.oc1m = 0b110;
    hal::tim4->capt_comp_mode1.oc2m = 0b110;
    // setup value to tim4 compare registers
    hal::tim4->ccr1 = 500;
    hal::tim4->ccr2 = 500;
    // setup tim4 channels 1, 2 to corresponding output pin
    hal::tim4->capt_comp_enable.cc1e = 1;
    hal::tim4->capt_comp_enable.cc2e = 1;
    // enable tim4 interrupt for update
    hal::tim4->dma_interrupt_enable.uie = 1;
    // enable tim4
    hal::tim4->control1.cen = 1;
}

void setup_rtc() {
    // enable rtc clock
    hal::rcc->control_status.rtcen = 1;

    // disable protection
    hal::rtc->write_protect.key = 0xca;
    hal::rtc->write_protect.key = 0x53;

    // enter initialization mode
    hal::rtc->init_status.init = 1;
    // wait to enter init
    while (hal::rtc->init_status.initf == 0);

    // setup prescaler value
    hal::rtc->prescaler.prediv_s = 255; // 32768
    hal::rtc->prescaler.prediv_a = 127;
    // setup 24h hour/day format
    hal::rtc->control.fmt = 0;
    // enable direction take value from registers
    hal::rtc->control.bypshad = 1;
    // setup time & date
    hal::rtc->time.ht = 1;
    hal::rtc->time.hu = 2;
    hal::rtc->date.wdu = 0b001; // Sunday

    // setup wakeup timer
    hal::rtc->wakeup_timer.wut = 2048; // rtcclk/16/2048 -> 1s event
    // enable wakeup timer
    hal::rtc->control.wute = 1;
    // enable wakeup timer interrupt
    hal::rtc->control.wutie = 1;

    // exit initialization mode
    hal::rtc->init_status.init = 0;

    // enable protection
    hal::rtc->write_protect.key = 0xff;

    // setup EXTI20 -> RTC_wkup to rising edge
    hal::exti->rising_edge_en(20);
    // enable interrupt for EXTI20 -> RTC_wkup
    hal::exti->unmask_int(20);
}

void runner::view_rtc_time() {
    bsp::st_hex_lcd lcd;

    lcd.wait_update()
        .clear(0)
        .write_digit(0, hal::rtc->time.ht)
        .clear(1)
        .write_digit(1, hal::rtc->time.hu)
        .write_col(1)
        .clear(2)
        .write_digit(2, hal::rtc->time.mnt)
        .clear(3)
        .write_digit(3, hal::rtc->time.mnu)
        .write_col(3)
        .clear(4)
        .write_digit(4, hal::rtc->time.st)
        .clear(5)
        .write_digit(5, hal::rtc->time.su)
        .update();
}

void runner::run() {
    bsp::st_hex_lcd lcd;

    setup_gpio();
    setup_timer4();
    setup_lcd_pwr();
    setup_rtc();
    lcd.setup();

    lcd.wait_update();
    lcd.write_char(0, '1');
    lcd.write_char(1, '2');
    lcd.write_col(1);
    lcd.write_char(2, '3');
    lcd.write_char(3, '4');
    lcd.write_col(3);
    lcd.write_char(4, '5');
    lcd.write_dp(4);
    lcd.write_char(5, '6');
    lcd.write_col(5);
    lcd.update();

    view_rtc_time();

    // setup irq for sys_tick and enable it irq
    hal::nvic->enable_irq(hal::irq_n_t::sys_tick_timer);
    hal::sys_tick->config(8000000);
    // setup irq for tim4
    hal::nvic->enable_irq(hal::irq_dev_n_t::TIM4);
    // setup irq for rtc wakeup
    hal::nvic->enable_irq(hal::irq_dev_n_t::RTC_wkup);
}
