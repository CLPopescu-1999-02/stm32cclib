#ifndef CORE_T_HH
#define CORE_T_HH

#include "lib/regbit.hh"

namespace hal {
    template <lib::u32 addr>
    struct nvic_d {
        struct nvic_t {
            lib::u32 iser[8];
            lib::u32 __reserved0[24];
            lib::u32 icer[8];
            lib::u32 __reserved1[24];
            lib::u32 ispr[8];
            lib::u32 __reserved2[24];
            lib::u32 icpr[8];
            lib::u32 __reserved3[24];
            lib::u32 iabr[8];
            lib::u32 __reserved4[56];
            lib::u32 ip[240];
            lib::u32 __reserved5[644];
            lib::u32 stir;
        };

        template <typename Irq_t, Irq_t irq_n>
        static void enable_irq() {
            regs->iser[(lib::u32)((lib::s32)irq_n) >> 5] =
                1 << ((lib::u32)irq_n & 0x1f);
        }

        static constexpr volatile nvic_t * const regs =
            reinterpret_cast<nvic_t *>(addr);
    };

    namespace sys_tick_int {
        const lib::u32 load_reload_msk = 0xffffff;
    }

    using sys_tick_control_enable = lib::regbit<0>;
    using sys_tick_control_tickint = lib::regbit<1>;
    using sys_tick_control_clksource = lib::regbit<2>;
    using sys_tick_control_countf = lib::regbit<16>;

    template <lib::u32 addr>
    struct sys_tick_d {
        struct sys_tick_t {
            lib::u32 control;
            lib::u32 load;
            lib::u32 value;
            lib::u32 calib;
        };

        template <lib::u32 ticks>
        static bool config() {
            if (ticks > sys_tick_int::load_reload_msk)
                return false;

            regs->load =
                (ticks & sys_tick_int::load_reload_msk) - 1;

            regs->value = 0;

            regs->control |=
                lib::regbits<lib::u32,
                    sys_tick_control_clksource,
                    sys_tick_control_tickint,
                    sys_tick_control_enable
                >::mask;

            return true;
        }

        static constexpr volatile sys_tick_t * const regs =
            reinterpret_cast<sys_tick_t *>(addr);
    };
} // namespace Hal

#endif // CORE_T_HH
