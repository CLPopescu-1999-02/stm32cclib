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

    struct pin_t {
        const uint32_t number;
        const pin_mode_t mode;
    };

    constexpr uint32_t mode_of(const pin_t pin) {
        return (static_cast<uint32_t>(pin.mode) << (pin.number * 2));
    }

    template <typename Pin, typename ...Pins>
    constexpr uint32_t mode_of(Pin pin, Pins ...pins) {
        return mode_of(pin) | mode_of(pins...);
    }

    constexpr uint32_t value_of(const pin_t pin) {
        return (1 << pin.number);
    }

    template <typename Pin, typename ...Pins>
    constexpr uint32_t value_of(Pin pin, Pins ...pins) {
        return value_of(pin) | value_of(pins...);
    }

    struct gpio_t {
        uint32_t mode;
        uint32_t otyper;
        uint32_t ospeedr;
        uint32_t pupdr;
        uint32_t idr; 
        uint32_t odr; 
        uint32_t bsrr;
        uint32_t lckr;
        uint32_t afr[2];
        uint32_t brr;

        template <typename ...Pins>
        void set_mode(Pins ...pins) volatile {
            mode |= mode_of(pins...);
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

    volatile gpio_t * const gpio_b = reinterpret_cast<gpio_t *>(0x40020400);
} // namespace Hal
#endif // GPIO_HH
