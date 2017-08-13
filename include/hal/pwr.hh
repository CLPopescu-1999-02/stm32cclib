#ifndef PWR_HH
#define PWR_HH

#include <stdint.h>

namespace hal {
    struct pwr_control_t {
        uint32_t lpsdsr:1;
        uint32_t pdds:1;
        uint32_t cwuf:1;
        uint32_t csbf:1;
        uint32_t pvde:1;
        uint32_t pls:3;
        uint32_t dbp:1;
        uint32_t ulp:1;
        uint32_t fwu:1;
        uint32_t vos:2;
        uint32_t _unused0:1;
        uint32_t lprun:1;
        uint32_t _unused1:17;
    };

    struct pwr_control_status_t {
        uint32_t wuf:1;
        uint32_t sbf:1;
        uint32_t pvdo:1;
        uint32_t vrefintrdyf:1;
        uint32_t vosf:1;
        uint32_t reglpf:1;
        uint32_t _unused0:2;
        uint32_t ewup1:1;
        uint32_t ewup2:1;
        uint32_t ewup3:1;
        uint32_t _unused1:21;
    };

    struct pwr_t {
        pwr_control_t control;
        pwr_control_status_t control_status;
    };
}

#include "hal/pwr_d.hh"

#endif // PWR_HH
