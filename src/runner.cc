#include "runner.hh"

#include "isr_base.hh"
#include "hal/gpio.hh"
#include "hal/rcc.hh"
#include "hal/core.hh"

namespace {
    const uint32_t ld3_green{7};
    const uint32_t ld4_blue{6};
    const uint32_t all_leds = hal::value_of(ld3_green, ld4_blue);
}

extern "C" void isr::sys_tick_timer() {
    hal::gpio_b->odr ^= all_leds;
}


void runner::run() {
    // enable led and lcd port
    hal::rcc->ahb_enable.gpioa = 1;
    hal::rcc->ahb_enable.gpiob = 1;
    hal::rcc->ahb_enable.gpioc = 1;

    // set led pins to output state
    hal::gpio_b->set_mode(hal::pin_mode_t::output,
        ld3_green,
        ld4_blue
    );

    // enable leds
    hal::gpio_b->set_value(
        ld3_green,
        ld4_blue
    );

    // enable lcd
    hal::gpio_a->set_mode(hal::pin_mode_t::alt_func,
        1, 2, 3, 8, 9, 10, 15);
    hal::gpio_a->set_alt_func(11,
        1, 2, 3, 8, 9, 10, 15);

    hal::gpio_b->set_mode(hal::pin_mode_t::alt_func,
        3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 15);
    hal::gpio_a->set_alt_func(11,
        3, 4, 5, 8, 9, 10, 11, 12, 13, 14, 15);

    hal::gpio_c->set_mode(hal::pin_mode_t::alt_func,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);
    hal::gpio_a->set_alt_func(11,
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11);

    // setup irq for sys_tick and enable it irq
    hal::nvic->enable_irq(hal::irq_n_t::sys_tick_timer);
    hal::sys_tick->config(2000000);
}
