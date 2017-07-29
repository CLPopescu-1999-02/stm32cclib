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

    constexpr uint32_t mode_of(const pin_mode_t mode, const uint32_t pin) {
        return (static_cast<uint32_t>(mode) << (pin * 2));
    }

    template <typename ...Pins>
    constexpr uint32_t mode_of(const pin_mode_t mode, const uint32_t pin, Pins ...pins) {
        return mode_of(mode, pin) | mode_of(mode, pins...);
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
        void set_mode(const pin_mode_t _mode, Pins ...pins) volatile {
            moder |= mode_of(_mode, pins...);
        }

        template <typename ...Pins>
        void set_alt_func(const uint32_t alt_func, Pins ...pins) volatile {
            afr |= alt_func_of(alt_func, pins...);
        }

        template <typename ...Pins>
        void set_value(Pins ...pins) volatile {
            bsrr = value_of(pins...);
        }

        template <typename ...Pins>
        void reset_value(Pins ...pins) volatile {
            bsrr = value_of(pins...) << 16;
        }
    };

    volatile gpio_t * const gpioa = reinterpret_cast<gpio_t *>(0x40020000);
    volatile gpio_t * const gpiob = reinterpret_cast<gpio_t *>(0x40020400);
    volatile gpio_t * const gpioc = reinterpret_cast<gpio_t *>(0x40020800);
} // namespace Hal
#endif // GPIO_HH
