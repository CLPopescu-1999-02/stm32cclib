#ifndef GPIO_HH
#define GPIO_HH
#include <stdint.h>

namespace hal {
    enum struct pin_mode_t : uint32_t {
        input = 0b00,
        output = 0b01,
        alt_func = 0b10,
        analog = 0b11
    };

    enum struct pin_speed_t : uint32_t {
        very_low = 0b00,
        low = 0b01,
        medium = 0b10,
        high = 0b11
    };

    enum struct pin_pull_t : uint32_t {
        none = 0b00,
        up = 0b01,
        dow = 0b10,
        _reserved = 0b11
    };

    template <typename Type>
    constexpr uint32_t mode_of(const Type type, const uint32_t pin) {
        return (static_cast<uint32_t>(type) << (pin * 2));
    }

    template <typename Type, typename ...Pins>
    constexpr uint32_t mode_of(const Type type, const uint32_t pin, Pins ...pins) {
        return mode_of(type, pin) | mode_of(type, pins...);
    }

    constexpr uint64_t alt_func_of(const uint32_t alt_func, const uint32_t pin) {
        return ((uint64_t)alt_func << (pin * 4));
    }

    template <typename ...Pins>
    constexpr uint64_t alt_func_of(const uint32_t alt_func, const uint32_t pin, Pins ...pins) {
        return alt_func_of(alt_func, pin) | alt_func_of(alt_func, pins...);
    }

    constexpr uint32_t value_of(const uint32_t pin) {
        return (1 << pin);
    }

    template <typename ...Pins>
    constexpr uint32_t value_of(const uint32_t pin, Pins ...pins) {
        return value_of(pin) | value_of(pins...);
    }

    struct gpio_t {
        uint32_t moder;
        uint32_t otyper;
        uint32_t ospeedr;
        uint32_t pupdr;
        uint32_t idr; 
        uint32_t odr; 
        uint32_t bsrr;
        uint32_t lckr;
        uint64_t afr;
        uint32_t brr;

        template <typename ...Pins>
        void set_mode(const pin_mode_t mode, Pins ...pins) volatile {
            moder |= mode_of(mode, pins...);
        }

        template <typename ...Pins>
        void set_open_drain(Pins ...pins) volatile {
            otyper |= value_of(pins...);
        }

        template <typename ...Pins>
        void set_push_pull(Pins ...pins) volatile {
            otyper &= ~value_of(pins...);
        }

        template <typename ...Pins>
        void set_speed(const pin_speed_t speed, Pins ...pins) volatile {
            ospeedr |= mode_of(speed, pins...);
        }

        template <typename ...Pins>
        void set_pull(const pin_pull_t pull, Pins ...pins) volatile {
            pupdr |= mode_of(pull, pins...);
        }

        template <typename ...Pins>
        void set_value(Pins ...pins) volatile {
            bsrr = value_of(pins...);
        }

        template <typename ...Pins>
        void reset_value(Pins ...pins) volatile {
            bsrr = value_of(pins...) << 16;
        }

        template <typename ...Pins>
        void lock(Pins ...pins) volatile {
            lckr |= value_of(pins...);
        }

        template <typename ...Pins>
        void unlock(Pins ...pins) volatile {
            lckr &= ~value_of(pins...);
        }

        template <typename ...Pins>
        void set_alt_func(const uint32_t alt_func, Pins ...pins) volatile {
            afr |= alt_func_of(alt_func, pins...);
        }

        template <typename ...Pins>
        void reset(Pins ...pins) volatile {
            brr |= value_of(pins...);
        }
    };

    volatile gpio_t * const gpioa = reinterpret_cast<gpio_t *>(0x40020000);
    volatile gpio_t * const gpiob = reinterpret_cast<gpio_t *>(0x40020400);
    volatile gpio_t * const gpioc = reinterpret_cast<gpio_t *>(0x40020800);
} // namespace Hal
#endif // GPIO_HH
