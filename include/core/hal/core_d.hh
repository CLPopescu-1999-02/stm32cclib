#ifndef CORE_D_HH
#define CORE_D_HH

namespace hal {
    volatile sys_tick_t * const sys_tick = reinterpret_cast<sys_tick_t *>(0xe000e000 + 0x10);

    volatile nvic_t * const nvic = reinterpret_cast<nvic_t *>(0xe000e000 + 0x100);
}

#endif // CORE_D_HH
