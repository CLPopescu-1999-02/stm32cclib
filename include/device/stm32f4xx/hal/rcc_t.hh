#ifndef RCC_T_HH
#define RCC_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using rcc_ahb1_gpioa = lib::regbit<0>;

    struct rcc_t {
        lib::u32 cr;
        lib::u32 pllcfgr;
        lib::u32 cfgr;
        lib::u32 cir;
        lib::u32 ahb1_reset;
        lib::u32 ahb2_reset;
        lib::u32 ahb3_reset;
        lib::u32 _unused0;
        lib::u32 apb1_reset;
        lib::u32 apb2_reset;
        lib::u32 _unused1;
        lib::u32 _unused2;
        lib::u32 ahb1_enable;
        lib::u32 ahb2_enable;
        lib::u32 ahb3_enable;
        lib::u32 _unused3;
        lib::u32 apb1_enable;
        lib::u32 apb2_enable;
        lib::u32 _unused4;
        lib::u32 _unused5;
        lib::u32 ahb1lp_enable;
        lib::u32 ahb2lp_enable;
        lib::u32 ahb3lp_enable;
        lib::u32 _unused6;
        lib::u32 apb1lp_enable;
        lib::u32 apb2lp_enable;
        lib::u32 _unused7;
        lib::u32 _unused8;
        lib::u32 bdcr;
        lib::u32 csr;
        lib::u32 _unused9;
        lib::u32 _unused10;
        lib::u32 sscgr;
        lib::u32 plli2scfgr;
    };
} // namespace Hal

#endif // RCC_T_HH
