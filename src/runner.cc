#include "runner.hh"

#include "isr_base.hh"
#include "isr_extend.hh"
#include "hal/core.hh"
#include "hal/gpio.hh"
#include "hal/lcd.hh"
#include "hal/pwr.hh"
#include "hal/rcc.hh"
#include "hal/tim.hh"

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
}

static void setup_lcd() {
    // enable lcd and pwr module
    hal::rcc->apb1_enable.pwr = 1;
    hal::rcc->apb1_enable.lcd = 1;

    // disable clock protection for rtc/lcd
    hal::pwr->control.dbp = 1;

    // reset clock rtc/lcd
    hal::rcc->control_status.rtcrst = 1;
    hal::rcc->control_status.rtcrst = 0;

    // enable LSI and wait it stable
    hal::rcc->control_status.lseon = 1;
    while (hal::rcc->control_status.lserdy != 1);

    // set LSI for clocking rtc/lcd
    hal::rcc->control_status.rtcsel = 0b01;

    // set BIAS to 1/3
    hal::lcd->control.bias = 0b10;

    // set DUTY to 1/4
    hal::lcd->control.duty = 0b011;

    // enable lcd remaping
    hal::lcd->control.mux_seg = 1;

    // setup lcd clock
    hal::lcd->frame_control.ps = 0b0100;
    hal::lcd->frame_control.div = 0b0001;

    // setup lcd contrast
    hal::lcd->frame_control.cc = 0b010;

    // wait for synchro lcd frame control
    while (hal::lcd->status.fcrsf == 0);

    // internal step-up converter
    hal::lcd->control.vsel = 0;

    // enable lcd controller
    hal::lcd->control.lcden = 1;

    // wait for ready step-up converter
    while (hal::lcd->status.rdy != 1);

    // wait for ready lcd controller
    while (hal::lcd->status.ens != 1);
}

static void setup_timer() {
    // enable led pins, connect to tim4 output
    hal::gpiob->set_mode(hal::pin_mode_t::alt_func,
        ld3_green, ld4_blue);
    hal::gpiob->set_alt_func(2,
        ld3_green, ld4_blue);

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

void runner::run() {
    setup_gpio();

    setup_lcd();

    setup_timer();
    // wait for final update display
    while (hal::lcd->status.udr == 1);

    // write TEST to lcd ram buffer
    hal::lcd->ram[0] = 0x02200b00;
    hal::lcd->ram[2] = 0x07340d00;
    hal::lcd->ram[4] = 0x00001004;
    hal::lcd->ram[6] = 0x04040000;

    hal::lcd->status.udr = 1;

    // enable leds
    hal::gpiob->set_value(
        ld3_green,
        ld4_blue
    );

    // setup irq for sys_tick and enable it irq
    hal::nvic->enable_irq(hal::irq_n_t::sys_tick_timer);
    hal::sys_tick->config(8000000);
    // setup irq for tim4
    hal::nvic->enable_irq(hal::irq_dev_n_t::TIM4);
}
