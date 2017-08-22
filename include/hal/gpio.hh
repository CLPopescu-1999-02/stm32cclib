#ifndef GPIO_HH
#define GPIO_HH

#include "lib/types.hh"
#include "lib/bit.hh"

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

        template <pin_mode mode, typename ...Pins>
        void set_mode() volatile {
            moder |= lib::bits<lib::u32, pin_mode, mode, 1, Pins...>::mask;
        }

        template <typename ...Pins>
        void set_open_drain() volatile {
            otyper |= lib::bits<lib::u32, lib::u32, 1, 0, Pins...>::mask;
        }

        template <typename ...Pins>
        void set_push_pull() volatile {
            otyper &= ~lib::bits<lib::u32, lib::u32, 1, 0, Pins...>::mask;
        }

        template <pin_speed speed, typename ...Pins>
        void set_speed() volatile {
            ospeedr |= lib::bits<lib::u32, pin_speed, speed, 1, Pins...>::mask;
        }

        template <pin_pull pull, typename ...Pins>
        void set_pull() volatile {
            pupdr |= lib::bits<lib::u32, pin_pull, pull, 1, Pins...>::mask;
        }

        template <typename ...Pins>
        void set_value() volatile {
            bsrr = lib::bits<lib::u32, lib::u32, 1, 0, Pins...>::mask;
        }

        template <typename ...Pins>
        void reset_value() volatile {
            bsrr = lib::bits<lib::u32, lib::u32, 1, 0, Pins...>::mask << 16;
        }

        template <typename ...Pins>
        void lock() volatile {
            lckr |= lib::bits<lib::u32, lib::u32, 1, 0, Pins...>::mask;
        }

        template <typename ...Pins>
        void unlock() volatile {
            lckr &= ~lib::bits<lib::u32, lib::u32, 1, 0, Pins...>::mask;
        }

        template <lib::u32 alt_func, typename ...Pins>
        void set_alt_func() volatile {
            afr |= lib::bits<lib::u64, lib::u32, alt_func, 2, Pins...>::mask;
        }

        template <typename ...Pins>
        void reset(Pins ...pins) volatile {
            brr |= lib::bits<lib::u32, lib::u32, 1, 0, Pins...>::mask;
        }
    };
} // namespace Hal

#include "hal/gpio_d.hh"

#endif // GPIO_HH
