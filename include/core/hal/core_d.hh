#ifndef CORE_D_HH
#define CORE_D_HH

namespace hal {
    using sys_tick = sys_tick_d<0xe000e000 + 0x10>;

    using nvic = nvic_d<0xe000e000 + 0x100>;
}

#endif // CORE_D_HH
