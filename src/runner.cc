#include "runner.hh"

#include "isr_base.hh"
#include "hal/core.hh"
#include "hal/gpio.hh"
#include "hal/lcd.hh"
#include "hal/pwr.hh"
#include "hal/rcc.hh"

namespace {
    const uint32_t ld3_green{7};
    const uint32_t ld4_blue{6};
    const uint32_t all_leds = hal::value_of(ld3_green, ld4_blue);
}

extern "C" void isr::sys_tick_timer() {
    hal::gpiob->odr ^= all_leds;
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

void runner::run() {
    setup_gpio();

    setup_lcd();
    // wait for final update display
    while (hal::lcd->status.udr == 1);

    hal::lcd->ram[0] = 0x02200b00;
    hal::lcd->ram[2] = 0x07340d00;
    hal::lcd->ram[4] = 0x00001004;
    hal::lcd->ram[6] = 0x04040000;

    hal::lcd->status.udr = 1;

    // set led pins to output state
    hal::gpiob->set_mode(hal::pin_mode_t::output,
        ld3_green,
        ld4_blue
    );

    // enable leds
    hal::gpiob->set_value(
        ld3_green,
        ld4_blue
    );

    // setup irq for sys_tick and enable it irq
    hal::nvic->enable_irq(hal::irq_n_t::sys_tick_timer);
    hal::sys_tick->config(2000000);
}
