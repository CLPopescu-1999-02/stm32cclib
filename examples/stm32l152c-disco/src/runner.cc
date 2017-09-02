#include "runner.hh"

#include "lib/types.hh"
#include "lib/bit.hh"

#include "isr_base.hh"
#include "isr_extend.hh"
#include "hal/adc.hh"
#include "hal/core.hh"
#include "hal/dma.hh"
#include "hal/exti.hh"
#include "hal/gpio.hh"
#include "hal/pwr.hh"
#include "hal/rcc.hh"
#include "hal/rtc.hh"
#include "hal/tim.hh"

#include "bsp/st_hex_lcd.hh"

namespace {
    using ld3_green = hal::p7;
    using ld4_blue = hal::p6;
    const lib::u32 all_leds = lib::bits<lib::u32, lib::u32, 1, 0,
        ld3_green, ld4_blue>::mask;

    volatile bool foward = true;
    const int add_value = 10;

    volatile int mode = 0;

    volatile uint16_t adc_values[2];
}

extern "C" void isr::sys_tick_timer() {
    hal::tim4->capt_comp_mode1.oc2m ^= 0b001;

    mode++;
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
        runner::view_current_state();

        hal::rtc->init_status.wutf = 0;
    }
}

static void setup_gpio() {
    // enable led and lcd port
    hal::rcc->ahb_enable.gpioa = 1;
    hal::rcc->ahb_enable.gpiob = 1;
    hal::rcc->ahb_enable.gpioc = 1;

    // enable lcd pins
    hal::gpioa::set_mode<hal::pin_mode::alt_func,
        hal::p1, hal::p2, hal::p3, hal::p8, hal::p9, hal::p10, hal::p15>();
    hal::gpioa::set_alt_func<hal::pin_alt::af11,
        hal::p1, hal::p2, hal::p3, hal::p8, hal::p9, hal::p10, hal::p15>();
    hal::gpiob::set_mode<hal::pin_mode::alt_func,
        hal::p3, hal::p4, hal::p5, hal::p8,
        hal::p9, hal::p10, hal::p11, hal::p12,
        hal::p13, hal::p14, hal::p15>();
    hal::gpiob::set_alt_func<hal::pin_alt::af11,
        hal::p3, hal::p4, hal::p5, hal::p8,
        hal::p9, hal::p10, hal::p11, hal::p12,
        hal::p13, hal::p14, hal::p15>();
    hal::gpioc::set_mode<hal::pin_mode::alt_func,
        hal::p0, hal::p1, hal::p2, hal::p3,
        hal::p6, hal::p7, hal::p8, hal::p9,
        hal::p10, hal::p11>();
    hal::gpioc::set_alt_func<hal::pin_alt::af11,
        hal::p0, hal::p1, hal::p2, hal::p3,
        hal::p6, hal::p7, hal::p8, hal::p9,
        hal::p10, hal::p11>();

    // enable led pins, connect to tim4 output
    hal::gpiob::set_mode<hal::pin_mode::alt_func,
        ld3_green, ld4_blue>();
    hal::gpiob::set_alt_func<hal::pin_alt::af2,
        ld3_green, ld4_blue>();
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
    hal::rtc->date.yt = 1;
    hal::rtc->date.yu = 7;
    hal::rtc->date.mt = 0;
    hal::rtc->date.mu = 8;
    hal::rtc->date.dt = 1;
    hal::rtc->date.du = 0;
    hal::rtc->date.wdu = 0b100; // Thursday

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

void setup_dma() {
    // enable dma1 power
    hal::rcc->ahb_enable.dma1 = 1;
    // config dma1 channel 1 (ADC1)
    // disable dma conversion
    hal::dma1_channel1->config.en = 0;
    // memory increment
    hal::dma1_channel1->config.minc = 1;
    // peripheral size 16 bit
    hal::dma1_channel1->config.psize = 0b01;
    // memory size 16 bit
    hal::dma1_channel1->config.msize = 0b01;
    // priority medium
    hal::dma1_channel1->config.pl = 0b01;
    // circular mode
    hal::dma1_channel1->config.circ = 1;
    // setup memory address
    hal::dma1_channel1->memory_address = (lib::u32)adc_values;
    // setup peripheral address
    hal::dma1_channel1->peripheral_address = (lib::u32)&(hal::adc1->dr);
    // setup number conversions
    hal::dma1_channel1->number_of_data = 2;
    // enable dma conversion
    hal::dma1_channel1->config.en = 1;
}

void setup_adc() {
    // enable hsi clock for adc1
    hal::rcc->control.hsion = 1;
    while (hal::rcc->control.hsirdy == 0);
    // reset adc module
    hal::rcc->apb2_reset.adc1 = 1;
    hal::rcc->apb2_reset.adc1 = 0;
    // enable adc module
    hal::rcc->apb2_enable.adc1 = 1;
    // setup clock to HSI / 4
    hal::adc1_common->control.adcpre = 0b11;
    // enable Temperature sensor (channel 16), Vrefint (channel 17)
    hal::adc1_common->control.tsvrefe = 1;
    // wait for enable Vrefint
    while (hal::pwr->control_status.vrefintrdyf == 0);
    // scan mode enabled
    hal::adc1->control1.scan = 1;
    // continuous conversion
    hal::adc1->control2.cont = 1;
    // dma mode enable
    hal::adc1->control2.dma = 1;
    // dma disable selection
    hal::adc1->control2.dds = 1;
    // disable adc low power mode
    hal::adc1->control2.adon = 1;
    // switch to bank A
    hal::adc1->control2.adc_cfg = 0;
    // wait for setup adc1 hw
    while (hal::adc1->status.adons == 0);
    // setup 17 channel - vref internal, 16 channel - Temperature
    hal::adc1->set_regular_sequence(17, 0);
    hal::adc1->set_sample_time(7, 17);
    hal::adc1->set_regular_sequence(16, 1);
    hal::adc1->set_sample_time(7, 16);
    hal::adc1->set_regular_sequence(1, 28);
    // wait for setup regular channel
    while (hal::adc1->status.rcnr == 1);

    // clear eoc
    hal::adc1->status.eoc = 0;
    // start conversion
    hal::adc1->control2.swstart = 1;
}

void runner::view_current_state() {
    bsp::st_hex_lcd lcd;

    switch (mode) {
        case 0:
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
                break;
        case 1:
            lcd.wait_update()
                .clear(0)
                .write_digit(0, hal::rtc->date.yt)
                .clear(1)
                .write_digit(1, hal::rtc->date.yu)
                .write_dp(1)
                .clear(2)
                .write_digit(2, hal::rtc->date.mt)
                .clear(3)
                .write_digit(3, hal::rtc->date.mu)
                .write_dp(3)
                .clear(4)
                .write_digit(4, hal::rtc->date.dt)
                .clear(5)
                .write_digit(5, hal::rtc->date.du)
                .update();
                break;
        case 2:
        {
            lib::u32 adc_value = *(uint16_t *)0x1ff800f8 * 3000;
            // get data
            adc_value /= adc_values[0];

            lcd.wait_update()
                .clear(0)
                .write_digit(0, adc_value / 1000 % 10)
                .write_dp(0)
                .clear(1)
                .write_digit(1, adc_value / 100 % 10)
                .clear(2)
                .write_digit(2, adc_value / 10 % 10)
                .clear(3)
                .write_digit(3, adc_value % 10)
                .clear(4)
                .write_char(4, 'V')
                .clear(5)
                .write_char(5, 'R')
                .update();
            break;
        }
        case 3:
        {
            int32_t adc_value = (110 - 30) * 100 / (*(uint16_t *)0x1ff800fe - *(uint16_t *)0x1ff800fa);
            // get data
            adc_value = adc_value * (adc_values[1] - *(uint16_t *)0x1ff800fa) + 3000;

            lcd.wait_update()
                .clear(0)
                .write_digit(0, adc_value / 1000 % 10)
                .clear(1)
                .write_digit(1, adc_value / 100 % 10)
                .write_dp(1)
                .clear(2)
                .write_digit(2, adc_value / 10 % 10)
                .clear(3)
                .write_digit(3, adc_value % 10)
                .clear(4)
                .write_char(4, 'T')
                .clear(5)
                .write_char(5, 'R')
                .update();
            break;
        }
        default:
            mode = 0;
            break;
    }
}

void runner::run() {
    bsp::st_hex_lcd lcd;

    setup_gpio();
    setup_timer4();
    setup_lcd_pwr();
    setup_rtc();
    setup_dma();
    setup_adc();
    lcd.setup();

    view_current_state();

    // setup irq for sys_tick and enable it irq
    hal::nvic->enable_irq<hal::irq_n_t, hal::irq_n_t::sys_tick_timer>();
    hal::sys_tick->config<8000000>();
    // setup irq for tim4
    hal::nvic->enable_irq<hal::irq_dev_n_t, hal::irq_dev_n_t::TIM4>();
    // setup irq for rtc wakeup
    hal::nvic->enable_irq<hal::irq_dev_n_t, hal::irq_dev_n_t::RTC_wkup>();
}
