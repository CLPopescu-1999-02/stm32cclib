#include "runner.hh"

#include "lib/types.hh"

#include "isr_base.hh"
#include "isr_extend.hh"
#include "hal/core.hh"
#include "hal/gpio.hh"
#include "hal/rcc.hh"
#include "hal/usart.hh"


namespace {
    const auto all_leds = 
        hal::bits32val<
            hal::p8, hal::p9, hal::p10, hal::p11,
            hal::p12, hal::p13, hal::p14, hal::p15
        >::mask;

    lib::u8 byte = '#';
}

extern "C" void isr::sys_tick_timer() {
    hal::gpioe::regs().odr ^= all_leds;

    hal::usart1::send_w(byte);
}

static void setup_gpio() {
    // enable led port
    hal::rcc::regs().ahb1_enable |=
        lib::regbits32<
            hal::rcc_ahb1_gpioe,
            hal::rcc_ahb1_gpioa
        >::mask;

    // enable led pins, connect to output
    hal::gpioe::set_mode<hal::pin_mode::output,
        hal::p8, hal::p9, hal::p10, hal::p11,
        hal::p12, hal::p13, hal::p14, hal::p15>();

    // enable usart1 pins,
    // connect to alternative func 7 (usart)
    hal::gpioa::set_mode<hal::pin_mode::alt_func,
        hal::p9, hal::p10>();
    hal::gpioa::set_alt_func<hal::pin_alt::af7,
        hal::p9, hal::p10>();
}

static void setup_usart() {
    // enable usart 3
    hal::rcc::regs().apb2_enable |=
        hal::rcc_apb2_usart1::clean<lib::u32>::mask;

    // usart1 setup baudrate 115200 bps
    // 8MHz/16/115200 = 4.34
    hal::usart1::regs().baudrate =
        lib::regbits32<
            hal::usart_baudrate_fraction::val<3>,
            hal::usart_baudrate_mantissa::val<4>
        >::mask;

    // usart1 enable block and enable tx, rx lines
    hal::usart1::regs().control1 |=
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
    hal::gpioe::set_value<
        hal::p8, hal::p9, hal::p10, hal::p11,
        hal::p12, hal::p13, hal::p14, hal::p15>();

    // setup irq for sys_tick
    hal::sys_tick::config<8000000>();

    while (true) {
        byte = hal::usart1::recv_w();
    }
}
