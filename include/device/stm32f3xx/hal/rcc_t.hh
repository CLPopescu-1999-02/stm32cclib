#ifndef RCC_T_HH
#define RCC_T_HH

#include "lib/types.hh"

namespace hal {
    struct ahb_devices_t {
        lib::u32 dma1:1;
        lib::u32 dma2:1;
        lib::u32 sram:1;
        lib::u32 _unused0:1;
        lib::u32 flitf:1;
        lib::u32 _unused1:1;
        lib::u32 crc:1;
        lib::u32 _unused2:10;
        lib::u32 gpioa:1;
        lib::u32 gpiob:1;
        lib::u32 gpioc:1;
        lib::u32 gpiod:1;
        lib::u32 gpioe:1;
        lib::u32 gpiof:1;
        lib::u32 _unused3:1;
        lib::u32 tsc:1;
        lib::u32 _unused4:3;
        lib::u32 adc12:1;
        lib::u32 adc32:1;
        lib::u32 _unused5:2;
    };

    struct rcc_t {
        lib::u32 cr;
        lib::u32 cfgr;
        lib::u32 cir;
        lib::u32 apb2rstr;
        lib::u32 apb1rstr;
        ahb_devices_t ahb_enable;
        lib::u32 apb2enr;
        lib::u32 apb1enr;
        lib::u32 bdcr;
        lib::u32 csr;
        ahb_devices_t ahb_reset;
        lib::u32 cfgr2;
        lib::u32 cfgr3;
    };
} // namespace Hal

#endif // RCC_T_HH
