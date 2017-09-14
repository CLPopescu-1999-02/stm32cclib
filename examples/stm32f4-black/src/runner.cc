#include "runner.hh"

#include "lib/types.hh"
#include "lib/in.hh"
#include "lib/out.hh"

#include "isr_base.hh"
#include "isr_extend.hh"
#include "hal/core.hh"
#include "hal/gpio.hh"
#include "hal/rcc.hh"
#include "hal/spi.hh"
#include "hal/usart.hh"

#include "bsp/ssd1306.hh"


namespace {
    const auto all_leds = 
        hal::bits32val<hal::p6, hal::p7>::mask;

    lib::s8 byte = '#';
    auto enable_echo = false;

    using sout = lib::out<hal::usart3>;
    using sin = lib::in<hal::usart3>;

    using oled_cs = hal::gpio_pin<hal::gpiod, hal::p6>;
    using oled_reset = hal::gpio_pin<hal::gpiod, hal::p5>;
    using oled_dc = hal::gpio_pin<hal::gpiod, hal::p4>;

    using oled = bsp::ssd1306<hal::spi1, oled_reset, oled_cs, oled_dc>;
}

extern "C" void isr::sys_tick_timer() {
    hal::gpioa::regs->odr ^= all_leds;

    if (enable_echo)
        sout::send(byte);
}

static void setup_gpio() {
    // enable led, usart ports
    hal::rcc::regs->ahb1_enable |=
        lib::regbits32<
            hal::rcc_ahb1_gpioa,
            hal::rcc_ahb1_gpiod,
            hal::rcc_ahb1_gpiob
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
    // enable lcd(spi1, gpio) pins
    // connect to output
    hal::gpiod::set_mode<hal::pin_mode::output,
        hal::p4, hal::p5, hal::p6>();
    // connect to alternative func 5 (spi)
    hal::gpiob::set_mode<hal::pin_mode::alt_func,
        hal::p3, hal::p5>();
    hal::gpiob::set_alt_func<hal::pin_alt::af5,
        hal::p3, hal::p5>();
}

static void setup_spi() {
    // enable spi1
    hal::rcc::regs->apb2_enable |=
        hal::rcc_apb2_spi1::clean<lib::u32>::mask;

    // spi1 setup
    hal::spi1::regs->control1 |=
        lib::regbits16<
            hal::spi_control1_br::val<
                hal::spi_control1_br_t::by2>,
            hal::spi_control1_mstr,
            hal::spi_control1_spe,
            hal::spi_control1_ssi,
            hal::spi_control1_ssm
        >::mask;
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
    setup_spi();
    oled::setup();

    for (volatile int i = 0; i < 128 * 64 / 8; i++)
        oled::send_data(0xaa);

    lib::u8 symbol[] = {0x0, 0x8, 0x8, 0x8, 0x8, 0x0};
    oled::send_data(symbol);

    // enable all leds
    hal::gpioa::reset_value<hal::p6, hal::p7>();

    // setup irq for sys_tick
    hal::sys_tick::config<8000000>();

    sout::send("\r\nHi, I'm echo repiter service\r\n");
    sout::send("My version is: ", 1, ".", 23, "\r\n");

    lib::s16 num;
    lib::s8 null;
    sout::send("Enter you num: ");
    sin::recv(num);
    sout::send("\r\nYou num is: ", num, "\r\n");

    sout::send("Push the any keys to start echo...\r\n");
    sin::recv(null);
    enable_echo = true;

    while (true) {
        sin::recv(byte);
    }
}
