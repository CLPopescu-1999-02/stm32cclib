#ifndef RCC_T_HH
#define RCC_T_HH

namespace hal {
    struct ahb_devices_t {
        uint32_t dma1:1;
        uint32_t dma2:1;
        uint32_t sram:1;
        uint32_t _unused0:1;
        uint32_t flitf:1;
        uint32_t _unused1:1;
        uint32_t crc:1;
        uint32_t _unused2:10;
        uint32_t gpioa:1;
        uint32_t gpiob:1;
        uint32_t gpioc:1;
        uint32_t gpiod:1;
        uint32_t gpioe:1;
        uint32_t gpiof:1;
        uint32_t _unused3:1;
        uint32_t tsc:1;
        uint32_t _unused4:3;
        uint32_t adc12:1;
        uint32_t adc32:1;
        uint32_t _unused5:2;
    };

    struct rcc_t {
        uint32_t cr;
        uint32_t cfgr;
        uint32_t cir;
        uint32_t apb2rstr;
        uint32_t apb1rstr;
        ahb_devices_t ahb_enable;
        uint32_t apb2enr;
        uint32_t apb1enr;
        uint32_t bdcr;
        uint32_t csr;
        ahb_devices_t ahb_reset;
        uint32_t cfgr2;
        uint32_t cfgr3;
    };
} // namespace Hal

#endif // RCC_T_HH
