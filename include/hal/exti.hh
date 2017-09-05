#ifndef EXTI_HH
#define EXTI_HH

#include "lib/types.hh"
#include "lib/bit.hh"
#include "hal/bit_operations.hh"

namespace hal {
    using p16 = lib::bit<16>;
    using p17 = lib::bit<17>;
    using p18 = lib::bit<18>;
    using p19 = lib::bit<19>;
    using p20 = lib::bit<20>;
    using p21 = lib::bit<21>;
    using p22 = lib::bit<22>;
    using p23 = lib::bit<23>;
    using p24 = lib::bit<24>;
    using p25 = lib::bit<25>;
    using p26 = lib::bit<26>;
    using p27 = lib::bit<27>;
    using p28 = lib::bit<28>;
    using p29 = lib::bit<29>;
    using p30 = lib::bit<30>;
    using p31 = lib::bit<31>;

    template <lib::u32 addr>
    struct exti_d {
        struct exti_t {
            lib::u32 imr;
            lib::u32 emr;
            lib::u32 rtsr;
            lib::u32 ftsr;
            lib::u32 swier;
            lib::u32 pr;
        };

        template <typename ...Pins>
        static void unmask_int() {
            regs->imr |=
                bits32val<Pins...>::mask;
        }

        template <typename ...Pins>
        static void mask_int() {
            regs->imr &=
                bits32val<Pins...>::mask;
        }

        template <typename ...Pins>
        static void unmask_event() {
            regs->emr |=
                bits32val<Pins...>::mask;
        }

        template <typename ...Pins>
        static void mask_event() {
            regs->emr &=
                bits32val<Pins...>::mask;
        }

        template <typename ...Pins>
        static void rising_edge_en() {
            regs->rtsr |=
                bits32val<Pins...>::mask;
        }

        template <typename ...Pins>
        static void rising_edge_dis() {
            regs->rtsr &=
                bits32val<Pins...>::mask;
        }

        template <typename ...Pins>
        static void faling_edge_en() {
            regs->ftsr |=
                bits32val<Pins...>::mask;
        }

        template <typename ...Pins>
        static void failng_edge_dis() {
            regs->ftsr &=
                bits32val<Pins...>::mask;
        }

        template <typename ...Pins>
        static void sw_event_en() {
            regs->swier |=
                bits32val<Pins...>::mask;
        }

        template <typename ...Pins>
        static void sw_event_dis() {
            regs->swier &=
                bits32val<Pins...>::mask;
        }

        template <typename ...Pins>
        static void pend_occurred() {
            regs->pr |=
                bits32val<Pins...>::mask;
        }

        static constexpr volatile exti_t * const regs =
            reinterpret_cast<exti_t *>(addr);
    };
}

#include "hal/exti_d.hh"

#endif // EXTI_HH
