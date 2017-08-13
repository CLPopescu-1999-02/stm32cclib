#ifndef EXTI_D_HH
#define EXTI_D_HH

namespace hal {
    volatile exti_t * const exti = reinterpret_cast<exti_t *>(0x40010400);
}

#endif // EXTI_D_HH
