#ifndef RCC_HH
#define RCC_HH
#include <stdint.h>

namespace hal {
    struct ahb_devices_t {
        uint32_t gpioa:1;
        uint32_t gpiob:1;
        uint32_t gpioc:1;
        uint32_t gpiod:1;
        uint32_t gpioe:1;
        uint32_t gpioh:1;
        uint32_t gpiof:1;
        uint32_t gpiog:1;
        uint32_t _unused0:24;
    };
    
    struct apb1_device_t {
        uint32_t tim2:1;
        uint32_t tim3:1;
        uint32_t tim4:1;
        uint32_t tim5:1;
        uint32_t tim6:1;
        uint32_t tim7:1;
        uint32_t _unused0:3;
        uint32_t lcd:1;
        uint32_t _unused1:1;
        uint32_t wwdg:1;
        uint32_t _unused2:2;
        uint32_t spi2:1;
        uint32_t spi3:1;
        uint32_t _unused3:1;
        uint32_t usart2:1;
        uint32_t usart3:1;
        uint32_t uart4:1;
        uint32_t uart5:1;
        uint32_t i2c1:1;
        uint32_t i2c2:1;
        uint32_t usb:1;
        uint32_t _unused4:4;
        uint32_t pwr:1;
        uint32_t dac:1;
        uint32_t _unused5:1;
        uint32_t comp:1;
    };
    
    struct rcc_control_status_t {
        uint32_t lsion:1;
        uint32_t lsirdy:1;
        uint32_t _unused0:6;
        uint32_t lseon:1;
        uint32_t lserdy:1;
        uint32_t lsebyp:1;
        uint32_t lsecsson:1;
        uint32_t lsecssd:1;
        uint32_t _unused1:3;
        uint32_t rtcsel:2;
        uint32_t _unused2:4;
        uint32_t rtcen:1;
        uint32_t rtcrst:1;
        uint32_t rmvf:1;
        uint32_t oblrstf:1;
        uint32_t pinrstf:1;
        uint32_t porrstf:1;
        uint32_t sftrstf:1;
        uint32_t iwdgrstf:1;
        uint32_t wwdgrstf:1;
        uint32_t lpwrrstf:1;
    };

    struct rcc_t {
        uint32_t cr;
        uint32_t icscr;
        uint32_t cfgr;
        uint32_t cir;
        ahb_devices_t ahb_reset;
        uint32_t apb2rstr;
        apb1_device_t apb1_reset;
        ahb_devices_t ahb_enable;
        uint32_t apb2enr;
        apb1_device_t apb1_enable;
        uint32_t ahb_lpenr;
        uint32_t apb2_lpenr;
        uint32_t apb1_lpenr;
        rcc_control_status_t control_status;
    };

    volatile rcc_t * const rcc = reinterpret_cast<rcc_t *>(0x40023800);
} // namespace Hal
#endif // RCC_HH
