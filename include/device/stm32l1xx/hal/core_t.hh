#ifndef CORE_T_HH
#define CORE_T_HH

#include "lib/regbit.hh"

namespace hal {
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

        template <typename Irq_t, Irq_t irq_n>
        void enable_irq() volatile {
            iser[((lib::u32)(irq_n) >> 5)] =
                1 << ((lib::u32)(irq_n) & 0x1f);
        }
    };

    namespace sys_tick_int {
        const lib::u32 load_reload_msk = 0xffffff;
    }

    using sys_tick_control_enable = lib::regbit<bool, 0, 1>;
    using sys_tick_control_tickint = lib::regbit<bool, 1, 1>;
    using sys_tick_control_clksource = lib::regbit<bool, 2, 1>;
    using sys_tick_control_countf = lib::regbit<bool, 16, 1>;

    struct sys_tick_t {
        lib::u32 control;
        lib::u32 load;
        lib::u32 value;
        lib::u32 calib;

        template <lib::u32 ticks>
        bool config() volatile {
            if (ticks > sys_tick_int::load_reload_msk)
                return false;

            load = (ticks & sys_tick_int::load_reload_msk) - 1;

            value = 0;

            control |= lib::regbits<lib::u32,
                sys_tick_control_clksource::val<true>,
                sys_tick_control_tickint::val<true>,
                sys_tick_control_enable::val<true>
            >::mask;

            return true;
        }
    };
} // namespace Hal

#endif // CORE_T_HH
