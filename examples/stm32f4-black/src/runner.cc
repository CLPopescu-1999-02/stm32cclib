#include "runner.hh"

#include "lib/types.hh"

#include "isr_base.hh"
#include "isr_extend.hh"
#include "hal/core.hh"
#include "hal/gpio.hh"
#include "hal/rcc.hh"


namespace {
    const lib::u32 all_leds = 
       lib::bits<lib::u32, lib::u32, 1, 0,
        hal::p6, hal::p7>::mask;
}

extern "C" void isr::sys_tick_timer() {
    hal::gpioa->odr ^= all_leds;
}

static void setup_gpio() {
    // enable led port
    hal::rcc->ahb1_enable |=
        lib::regbits<lib::u32, hal::rcc_ahb1_gpioa::val<true>>::mask;

    // enable led pins, connect to output
    hal::gpioa->set_mode<hal::pin_mode::output,
        hal::p6, hal::p7>();
}


void runner::run() {
    setup_gpio();

    // enable all leds
    hal::gpioa->set_value<hal::p6, hal::p7>();

    // setup irq for sys_tick
    hal::sys_tick->config<8000000>();

    while (true);
}
