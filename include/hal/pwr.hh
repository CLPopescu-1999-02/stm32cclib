#ifndef PWR_HH
#define PWR_HH

#include <stdint.h>

namespace hal {
    struct pwr_ctr_t {
        uint32_t _unused0:8;
        uint32_t dbp:1;
        uint32_t _unused1:23;
    };

    struct pwr_t {
        pwr_ctr_t control;
        uint32_t csr;
    };

    volatile pwr_t * const pwr = reinterpret_cast<pwr_t *>(0x40007000);
}

#endif // PWR_HH
