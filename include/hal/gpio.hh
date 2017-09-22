#ifndef GPIO_HH
#define GPIO_HH

#include "lib/types.hh"
#include "lib/bit.hh"
#include "hal/common/bit_operations.hh"

namespace hal {
    enum struct pin_mode : lib::u32 {
        input = 0b00,
        output = 0b01,
        alt_func = 0b10,
        analog = 0b11
    };

    enum struct pin_speed : lib::u32 {
        very_low = 0b00,
        low = 0b01,
        medium = 0b10,
        high = 0b11
    };

    enum struct pin_pull : lib::u32 {
        none = 0b00,
        up = 0b01,
        dow = 0b10,
        _reserved = 0b11
    };

    enum struct pin_alt : lib::u32 {
        af0 = 0,
        af1 = 1,
        af2 = 2,
        af3 = 3,
        af4 = 4,
        af5 = 5,
        af6 = 6,
        af7 = 7,
        af8 = 8,
        af9 = 9,
        af10 = 10,
        af11 = 11,
        af12 = 12,
        af13 = 13,
        af14 = 14,
        af15 = 15
    };

    using p0 = lib::bit<0>;
    using p1 = lib::bit<1>;
    using p2 = lib::bit<2>;
    using p3 = lib::bit<3>;
    using p4 = lib::bit<4>;
    using p5 = lib::bit<5>;
    using p6 = lib::bit<6>;
    using p7 = lib::bit<7>;
    using p8 = lib::bit<8>;
    using p9 = lib::bit<9>;
    using p10 = lib::bit<10>;
    using p11 = lib::bit<11>;
    using p12 = lib::bit<12>;
    using p13 = lib::bit<13>;
    using p14 = lib::bit<14>;
    using p15 = lib::bit<15>;

    template <lib::u32 addr>
    struct gpio_d {
        struct gpio_t {
            lib::u32 moder;
            lib::u32 otyper;
            lib::u32 ospeedr;
            lib::u32 pupdr;
            lib::u32 idr; 
            lib::u32 odr; 
            lib::u32 bsrr;
            lib::u32 lckr;
            lib::u64 afr;
            lib::u32 brr;
        };

        template <pin_mode mode, typename ...Pins>
        static void set_mode() {
            regs->moder |=
                lib::bits32<pin_mode, mode, 1, Pins...>::mask;
        }

        template <typename ...Pins>
        static void set_open_drain() {
            regs->otyper |=
                bits32val<Pins...>::mask;
        }

        template <typename ...Pins>
        static void set_push_pull() {
            regs->otyper &=
                ~bits32val<Pins...>::mask;
        }

        template <pin_speed speed, typename ...Pins>
        static void set_speed() {
            regs->ospeedr |=
                lib::bits32<pin_speed, speed, 1, Pins...>::mask;
        }

        template <pin_pull pull, typename ...Pins>
        static void set_pull() {
            regs->pupdr |=
                lib::bits32<pin_pull, pull, 1, Pins...>::mask;
        }

        template <typename ...Pins>
        static void set_value() {
            regs->bsrr =
                bits32val<Pins...>::mask;
        }

        template <typename ...Pins>
        static void reset_value() {
            regs->bsrr =
                bits32val<Pins...>::mask << 16;
        }

        template <typename ...Pins>
        static void lock() {
            regs->lckr |=
                bits32val<Pins...>::mask;
        }

        template <typename ...Pins>
        static void unlock() {
            regs->lckr &=
                ~bits32val<Pins...>::mask;
        }

        template <pin_alt alt_func, typename ...Pins>
        static void set_alt_func() {
            regs->afr |=
                lib::bits<lib::u64, pin_alt, alt_func, 2, Pins...>::mask;
        }

        template <typename ...Pins>
        static void reset(Pins ...pins) {
            regs->brr |=
                bits32val<Pins...>::mask;
        }

        static constexpr volatile gpio_t * const regs =
            reinterpret_cast<gpio_t *>(addr);
    };

    template <typename Port, typename Pin>
    struct gpio_pin {
        static void set() {
            Port::template set_value<Pin>();
        }

        static void reset() {
            Port::template reset_value<Pin>();
        }
    };
} // namespace Hal

#include "hal/gpio_d.hh"

#endif // GPIO_HH
