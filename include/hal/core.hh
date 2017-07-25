#ifndef CORE_HH
#define CORE_HH
#include <stdint.h>

namespace hal {
    enum struct irq_n_t : int32_t {
        NMI = -14,
        mem_manage = -12,
        bus_fault = -11,
        usage_fault = -10,
        SVC = -5,
        debug_mon = -4,
        pend_SV = -2,
        sys_tick_timer = -1
    };

    struct nvic_t {
        uint32_t iser[8];
        uint32_t __reserved0[24];
        uint32_t icer[8];
        uint32_t __reserved1[24];
        uint32_t ispr[8];
        uint32_t __reserved2[24];
        uint32_t icpr[8];
        uint32_t __reserved3[24];
        uint32_t iabr[8];
        uint32_t __reserved4[56];
        uint32_t ip[240];
        uint32_t __reserved5[644];
        uint32_t stir;
        
        void enable_irq(irq_n_t irq_n) volatile {
            iser[((uint32_t)(irq_n) >> 5)] =
                (1 << ((uint32_t)(irq_n) & 0x1f));
        }
    };

    namespace sys_tick_int {
        const uint32_t load_reload_msk = 0xffffff;
        const uint32_t clock_src_msk = 1 << 2;
        const uint32_t tick_int_msk = 1 << 1;
        const uint32_t enable_msk = 1;
    }

    struct sys_tick_t {
        uint32_t control;
        uint32_t load;
        uint32_t value;
        uint32_t calib;
        
        bool config(uint32_t ticks) volatile {
            if (ticks > sys_tick_int::load_reload_msk)
                return false;
            load = (ticks & sys_tick_int::load_reload_msk) - 1;
            value = 0;
            control = sys_tick_int::clock_src_msk |
                sys_tick_int::tick_int_msk |
                sys_tick_int::enable_msk;

            return true;
        }
    };

    volatile sys_tick_t * const sys_tick = reinterpret_cast<sys_tick_t *>(0xe000e000 + 0x10);
    volatile nvic_t * const nvic = reinterpret_cast<nvic_t *>(0xe000e000 + 0x100);
} // namespace Hal

#endif // CORE_HH

