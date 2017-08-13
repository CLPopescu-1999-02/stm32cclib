#include "runner.hh"

#include "hal/gpio.hh"
#include "hal/rcc.hh"

static void setup_gpio() {
    // enable led port
    hal::rcc->ahb_enable.gpioe = 1;

    // enable led pins, connect to output
    hal::gpioe->set_mode(hal::pin_mode_t::output,
        8, 9, 10, 11, 12, 13, 14, 15);
}

void runner::run() {
    setup_gpio();

    // enable all leds
    hal::gpioe->set_value(
        8, 9, 10, 11, 12, 13, 14, 15);

    while (true);
}
