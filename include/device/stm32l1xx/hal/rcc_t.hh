#ifndef RCC_T_HH
#define RCC_T_HH

#include "lib/types.hh"

namespace hal {
    struct rcc_control_t {
        lib::u32 hsion:1;
        lib::u32 hsirdy:1;
        lib::u32 _unused0:6;
        lib::u32 msion:1;
        lib::u32 msirdy:1;
        lib::u32 _unused1:6;
        lib::u32 hseon:1;
        lib::u32 hserdy:1;
        lib::u32 hsebyp:1;
        lib::u32 _unused2:5;
        lib::u32 pllon:1;
        lib::u32 pllrdy:1;
        lib::u32 _unused3:2;
        lib::u32 csson:1;
        lib::u32 rtcpre:2;
        lib::u32 _unused4:1;
    };

    struct rcc_clock_config_t {
        lib::u32 sw:2;
        lib::u32 sws:2;
        lib::u32 hpre:4;
        lib::u32 ppre1:3;
        lib::u32 ppre2:3;
        lib::u32 _unused0:2;
        lib::u32 pllsrc:1;
        lib::u32 _unused1:1;
        lib::u32 pllmul:4;
        lib::u32 plldiv:2;
        lib::u32 mcosel:3;
        lib::u32 _unused2:1;
        lib::u32 mcopre:3;
        lib::u32 _unused3:1;
    };

    struct ahb_devices_t {
        lib::u32 gpioa:1;
        lib::u32 gpiob:1;
        lib::u32 gpioc:1;
        lib::u32 gpiod:1;
        lib::u32 gpioe:1;
        lib::u32 gpioh:1;
        lib::u32 gpiof:1;
        lib::u32 gpiog:1;
        lib::u32 _unused0:4;
        lib::u32 crc:1;
        lib::u32 _unused1:2;
        lib::u32 flitf:1;
        lib::u32 _unused2:8;
        lib::u32 dma1:1;
        lib::u32 dma2:1;
        lib::u32 _unused3:1;
        lib::u32 aes:1;
        lib::u32 _unused4:2;
        lib::u32 fsmc:1;
        lib::u32 _unused5:1;
    };

    struct apb2_device_t {
        lib::u32 syscfgr:1;
        lib::u32 _unused0:1;
        lib::u32 tim9:1;
        lib::u32 tim10:1;
        lib::u32 tim11:1;
        lib::u32 _unused1:4;
        lib::u32 adc1:1;
        lib::u32 _unused2:1;
        lib::u32 sdio:1;
        lib::u32 spi1:1;
        lib::u32 _unused3:1;
        lib::u32 usart1:1;
        lib::u32 _unused4:17;
    };

    struct apb1_device_t {
        lib::u32 tim2:1;
        lib::u32 tim3:1;
        lib::u32 tim4:1;
        lib::u32 tim5:1;
        lib::u32 tim6:1;
        lib::u32 tim7:1;
        lib::u32 _unused0:3;
        lib::u32 lcd:1;
        lib::u32 _unused1:1;
        lib::u32 wwdg:1;
        lib::u32 _unused2:2;
        lib::u32 spi2:1;
        lib::u32 spi3:1;
        lib::u32 _unused3:1;
        lib::u32 usart2:1;
        lib::u32 usart3:1;
        lib::u32 uart4:1;
        lib::u32 uart5:1;
        lib::u32 i2c1:1;
        lib::u32 i2c2:1;
        lib::u32 usb:1;
        lib::u32 _unused4:4;
        lib::u32 pwr:1;
        lib::u32 dac:1;
        lib::u32 _unused5:1;
        lib::u32 comp:1;
    };

    struct rcc_control_status_t {
        lib::u32 lsion:1;
        lib::u32 lsirdy:1;
        lib::u32 _unused0:6;
        lib::u32 lseon:1;
        lib::u32 lserdy:1;
        lib::u32 lsebyp:1;
        lib::u32 lsecsson:1;
        lib::u32 lsecssd:1;
        lib::u32 _unused1:3;
        lib::u32 rtcsel:2;
        lib::u32 _unused2:4;
        lib::u32 rtcen:1;
        lib::u32 rtcrst:1;
        lib::u32 rmvf:1;
        lib::u32 oblrstf:1;
        lib::u32 pinrstf:1;
        lib::u32 porrstf:1;
        lib::u32 sftrstf:1;
        lib::u32 iwdgrstf:1;
        lib::u32 wwdgrstf:1;
        lib::u32 lpwrrstf:1;
    };

    struct rcc_t {
        rcc_control_t control;
        lib::u32 icscr;
        rcc_clock_config_t clock_config;
        lib::u32 cir;
        ahb_devices_t ahb_reset;
        apb2_device_t apb2_reset;
        apb1_device_t apb1_reset;
        ahb_devices_t ahb_enable;
        apb2_device_t apb2_enable;
        apb1_device_t apb1_enable;
        lib::u32 ahb_lpenr;
        lib::u32 apb2_lpenr;
        lib::u32 apb1_lpenr;
        rcc_control_status_t control_status;
    };
} // namespace Hal

#endif // RCC_T_HH
