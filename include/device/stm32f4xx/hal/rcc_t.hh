#ifndef RCC_T_HH
#define RCC_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using rcc_ahb1_gpioa = lib::regbit<0>;
    using rcc_ahb1_gpiob = lib::regbit<1>;
    using rcc_ahb1_gpioc = lib::regbit<2>;
    using rcc_ahb1_gpiod = lib::regbit<3>;
    using rcc_ahb1_gpioe = lib::regbit<4>;
    using rcc_ahb1_gpiof = lib::regbit<5>;
    using rcc_ahb1_gpiog = lib::regbit<6>;
    using rcc_ahb1_gpioh = lib::regbit<7>;
    using rcc_ahb1_gpioi = lib::regbit<8>;
    using rcc_ahb1_crc = lib::regbit<12>;
    using rcc_ahb1_dma1 = lib::regbit<21>;
    using rcc_ahb1_dma2 = lib::regbit<22>;
    using rcc_ahb1_ethmac = lib::regbit<25>;
    using rcc_ahb1_otghs = lib::regbit<29>;

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
