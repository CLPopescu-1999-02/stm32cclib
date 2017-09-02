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
        hal::p8, hal::p9, hal::p10, hal::p11,
        hal::p12, hal::p13, hal::p14, hal::p15>::mask;
}

extern "C" void isr::sys_tick_timer() {
    hal::gpioe::regs->odr ^= all_leds;
}

static void setup_gpio() {
    // enable led port
    hal::rcc->ahb_enable.gpioe = 1;

    // enable led pins, connect to output
    hal::gpioe::set_mode<hal::pin_mode::output,
        hal::p8, hal::p9, hal::p10, hal::p11,
        hal::p12, hal::p13, hal::p14, hal::p15>();
}


void runner::run() {
    setup_gpio();

    // enable all leds
    hal::gpioe::set_value<
        hal::p8, hal::p9, hal::p10, hal::p11,
        hal::p12, hal::p13, hal::p14, hal::p15>();

    // setup irq for sys_tick
    hal::sys_tick::config<8000000>();

    while (true);
}
