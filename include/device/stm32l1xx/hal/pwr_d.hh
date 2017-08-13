#ifndef PWR_D_HH
#define PWR_D_HH

namespace hal {
    volatile pwr_t * const pwr = reinterpret_cast<pwr_t *>(0x40007000);
}

#endif // PWR_D_HH
