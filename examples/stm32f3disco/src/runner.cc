#include "runner.hh"

#include "isr_base.hh"
#include "isr_extend.hh"
#include "hal/core.hh"
#include "hal/gpio.hh"
#include "hal/rcc.hh"

namespace {
    const uint32_t all_leds = hal::value_of(
        8, 9, 10, 11, 12, 13, 14, 15);
}

extern "C" void isr::sys_tick_timer() {
    hal::gpioe->odr ^= all_leds;
}

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

    // setup irq for sys_tick
    hal::sys_tick->config(8000000);

    while (true);
}
