#ifndef CORE_IRQ_HH
#define CORE_IRQ_HH

#include "lib/types.hh"

namespace hal {
    enum struct irq_n_t : lib::s32 {
        NMI = -14,
        mem_manage = -12,
        bus_fault = -11,
        usage_fault = -10,
        SVC = -5,
        debug_mon = -4,
        pend_SV = -2,
        sys_tick_timer = -1,
    };
}

#endif // CORE_IRQ_HH
