#include "runner.hh"

#include "hal/gpio.hh"
#include "hal/rcc.hh"

void runner::run() {
    const hal::pin_mode_t current_mode{hal::pin_mode_t::output};
    const hal::pin_t ld3_green{7, current_mode};
    const hal::pin_t ld4_blue{6, current_mode};
    const uint32_t all_leds = value_of(ld3_green, ld4_blue);
    // enable led port
    hal::rcc->ahb_enable.gpiob = 1;

    // set led pins to output state
    hal::gpio_b->set_mode(
        ld3_green,
        ld4_blue
    );

    // enable leds
    hal::gpio_b->set_value(
        ld3_green,
        ld4_blue
    );

    while (true) {
        volatile int cnt = 1 * 100 * 1000;
        while (cnt--);
        hal::gpio_b->odr ^= all_leds;
    }
}
