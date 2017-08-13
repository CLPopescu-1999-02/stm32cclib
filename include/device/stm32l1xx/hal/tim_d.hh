#ifndef TIM_D_HH
#define TIM_D_HH

namespace hal {
    volatile tim_t * const tim2 = reinterpret_cast<tim_t *>(0x40000000);
    volatile tim_t * const tim3 = reinterpret_cast<tim_t *>(0x40000400);
    volatile tim_t * const tim4 = reinterpret_cast<tim_t *>(0x40000800);
    volatile tim_t * const tim5 = reinterpret_cast<tim_t *>(0x40000c00);

    volatile tim_t * const tim6 = reinterpret_cast<tim_t *>(0x40001000);
    volatile tim_t * const tim7 = reinterpret_cast<tim_t *>(0x40001400);

    volatile tim_t * const tim9 = reinterpret_cast<tim_t *>(0x40010800);
    volatile tim_t * const tim10 = reinterpret_cast<tim_t *>(0x40010c00);
    volatile tim_t * const tim11 = reinterpret_cast<tim_t *>(0x40011000);
}

#endif // TIM_D_HH
