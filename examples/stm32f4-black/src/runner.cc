#include "runner.hh"

#include "lib/types.hh"
#include "lib/out.hh"

#include "isr_base.hh"
#include "isr_extend.hh"
#include "hal/core.hh"
#include "hal/gpio.hh"
#include "hal/rcc.hh"
#include "hal/usart.hh"


namespace {
    const auto all_leds = 
        hal::bits32val<hal::p6, hal::p7>::mask;

    lib::s8 byte = '#';
    using sout = lib::out<hal::usart3>;
}

extern "C" void isr::sys_tick_timer() {
    hal::gpioa::regs->odr ^= all_leds;

    sout::send(byte);
}

static void setup_gpio() {
    // enable led, usart ports
    hal::rcc::regs->ahb1_enable |=
        lib::regbits32<
            hal::rcc_ahb1_gpioa,
            hal::rcc_ahb1_gpiod
        >::mask;

    // enable led pins, connect to output
    hal::gpioa::set_mode<hal::pin_mode::output,
        hal::p6, hal::p7>();
    // enable usart3 pins,
    // connect to alternative func 7 (usart)
    hal::gpiod::set_mode<hal::pin_mode::alt_func,
        hal::p8, hal::p9>();
    hal::gpiod::set_alt_func<hal::pin_alt::af7,
        hal::p8, hal::p9>();
}

static void setup_usart() {
    // enable usart 3
    hal::rcc::regs->apb1_enable |=
        hal::rcc_apb1_usart3::clean<lib::u32>::mask;

    // usart3 setup baudrate 115200 bps
    // 16MHz/16/115200 = 8.68
    hal::usart3::regs->baudrate =
        lib::regbits32<
            hal::usart_baudrate_fraction::val<5>,
            hal::usart_baudrate_mantissa::val<8>
        >::mask;

    // usart3 enable block and enable tx, rx lines
    hal::usart3::regs->control1 |=
        lib::regbits32<
            hal::usart_control1_ue,
            hal::usart_control1_te,
            hal::usart_control1_re
        >::mask;
}

void runner::run() {
    setup_gpio();
    setup_usart();

    // enable all leds
    hal::gpioa::reset_value<hal::p6, hal::p7>();

    // setup irq for sys_tick
    hal::sys_tick::config<8000000>();

    sout::send("\r\nHi, I'm echo repiter service\r\n");
    sout::send("My version is: ", 1, ".", 23, "\r\n");

    while (true) {
        byte = hal::usart3::recv_w();
    }
}
