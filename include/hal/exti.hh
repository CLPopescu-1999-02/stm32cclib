#ifndef EXTI_HH
#define EXTI_HH

#include <stdint.h>

namespace hal {
    constexpr uint32_t event_of(const uint32_t pin) {
        return (1 << pin);
    }

    template <typename ...Pins>
    constexpr uint32_t event_of(const uint32_t pin, Pins ...pins) {
        return event_of(pin) | event_of(pins...);
    }

    struct exti_t {
        uint32_t imr;
        uint32_t emr;
        uint32_t rtsr;
        uint32_t ftsr;
        uint32_t swier;
        uint32_t pr;

        template <typename ...Pins>
        void unmask_int(Pins ...pins) volatile {
            imr |= event_of(pins...);
        }

        template <typename ...Pins>
        void mask_int(Pins ...pins) volatile {
            imr &= ~event_of(pins...);
        }

        template <typename ...Pins>
        void unmask_event(Pins ...pins) volatile {
            emr |= event_of(pins...);
        }

        template <typename ...Pins>
        void mask_event(Pins ...pins) volatile {
            emr &= ~event_of(pins...);
        }

        template <typename ...Pins>
        void rising_edge_en(Pins ...pins) volatile {
            rtsr |= event_of(pins...);
        }

        template <typename ...Pins>
        void rising_edge_dis(Pins ...pins) volatile {
            rtsr &= ~event_of(pins...);
        }

        template <typename ...Pins>
        void faling_edge_en(Pins ...pins) volatile {
            ftsr |= event_of(pins...);
        }

        template <typename ...Pins>
        void failng_edge_dis(Pins ...pins) volatile {
            ftsr &= ~event_of(pins...);
        }

        template <typename ...Pins>
        void sw_event_en(Pins ...pins) volatile {
            swier |= event_of(pins...);
        }

        template <typename ...Pins>
        void sw_event_dis(Pins ...pins) volatile {
            swier &= ~event_of(pins...);
        }

        template <typename ...Pins>
        void pend_occurred(Pins ...pins) volatile {
            pr |= event_of(pins...);
        }
    };

    volatile exti_t * const exti = reinterpret_cast<exti_t *>(0x40010400);
}

#endif // EXTI_HH
