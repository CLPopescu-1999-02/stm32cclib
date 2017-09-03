#ifndef EXTI_HH
#define EXTI_HH

#include "lib/types.hh"

namespace hal {
    constexpr lib::u32 event_of(const lib::u32 pin) {
        return (1 << pin);
    }

    template <typename ...Pins>
    constexpr lib::u32 event_of(const lib::u32 pin, Pins ...pins) {
        return event_of(pin) | event_of(pins...);
    }

    struct exti_t {
        lib::u32 imr;
        lib::u32 emr;
        lib::u32 rtsr;
        lib::u32 ftsr;
        lib::u32 swier;
        lib::u32 pr;

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
}

#include "hal/exti_d.hh"

#endif // EXTI_HH
