#include "runner.hh"

#include "hal/gpio.hh"
#include "hal/rcc.hh"

void runner::run() {
    const hal::gpio::pin_mode_t current_mode{hal::gpio::pin_mode_t::output};
    const hal::gpio::pin_t ld3_green{7, current_mode};
    const hal::gpio::pin_t ld4_blue{6, current_mode};
    const uint32_t all_leds = value_of(ld3_green, ld4_blue);
    // enable led port
    hal::rcc_r->ahb_enable.gpiob = 1;

    // set led pins to output state
    hal::gpio_b->mode |= mode_of(
        ld3_green,
        ld4_blue
    );

    // enable leds
    hal::gpio_b->odr |= all_leds;

    while (true) {
        volatile int cnt = 1 * 100 * 1000;
        while (cnt--);
        hal::gpio_b->odr ^= all_leds;
    }
}
