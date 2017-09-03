#ifndef PWR_HH
#define PWR_HH

#include "lib/types.hh"

namespace hal {
    struct pwr_control_t {
        lib::u32 lpsdsr:1;
        lib::u32 pdds:1;
        lib::u32 cwuf:1;
        lib::u32 csbf:1;
        lib::u32 pvde:1;
        lib::u32 pls:3;
        lib::u32 dbp:1;
        lib::u32 ulp:1;
        lib::u32 fwu:1;
        lib::u32 vos:2;
        lib::u32 _unused0:1;
        lib::u32 lprun:1;
        lib::u32 _unused1:17;
    };

    struct pwr_control_status_t {
        lib::u32 wuf:1;
        lib::u32 sbf:1;
        lib::u32 pvdo:1;
        lib::u32 vrefintrdyf:1;
        lib::u32 vosf:1;
        lib::u32 reglpf:1;
        lib::u32 _unused0:2;
        lib::u32 ewup1:1;
        lib::u32 ewup2:1;
        lib::u32 ewup3:1;
        lib::u32 _unused1:21;
    };

    struct pwr_t {
        pwr_control_t control;
        pwr_control_status_t control_status;
    };
}

#include "hal/pwr_d.hh"

#endif // PWR_HH
