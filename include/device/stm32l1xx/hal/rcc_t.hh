#ifndef RCC_T_HH
#define RCC_T_HH

namespace hal {
    struct rcc_control_t {
        uint32_t hsion:1;
        uint32_t hsirdy:1;
        uint32_t _unused0:6;
        uint32_t msion:1;
        uint32_t msirdy:1;
        uint32_t _unused1:6;
        uint32_t hseon:1;
        uint32_t hserdy:1;
        uint32_t hsebyp:1;
        uint32_t _unused2:5;
        uint32_t pllon:1;
        uint32_t pllrdy:1;
        uint32_t _unused3:2;
        uint32_t csson:1;
        uint32_t rtcpre:2;
        uint32_t _unused4:1;
    };

    struct rcc_clock_config_t {
        uint32_t sw:2;
        uint32_t sws:2;
        uint32_t hpre:4;
        uint32_t ppre1:3;
        uint32_t ppre2:3;
        uint32_t _unused0:2;
        uint32_t pllsrc:1;
        uint32_t _unused1:1;
        uint32_t pllmul:4;
        uint32_t plldiv:2;
        uint32_t mcosel:3;
        uint32_t _unused2:1;
        uint32_t mcopre:3;
        uint32_t _unused3:1;
    };

    struct ahb_devices_t {
        uint32_t gpioa:1;
        uint32_t gpiob:1;
        uint32_t gpioc:1;
        uint32_t gpiod:1;
        uint32_t gpioe:1;
        uint32_t gpioh:1;
        uint32_t gpiof:1;
        uint32_t gpiog:1;
        uint32_t _unused0:4;
        uint32_t crc:1;
        uint32_t _unused1:2;
        uint32_t flitf:1;
        uint32_t _unused2:8;
        uint32_t dma1:1;
        uint32_t dma2:1;
        uint32_t _unused3:1;
        uint32_t aes:1;
        uint32_t _unused4:2;
        uint32_t fsmc:1;
        uint32_t _unused5:1;
    };

    struct apb2_device_t {
        uint32_t syscfgr:1;
        uint32_t _unused0:1;
        uint32_t tim9:1;
        uint32_t tim10:1;
        uint32_t tim11:1;
        uint32_t _unused1:4;
        uint32_t adc1:1;
        uint32_t _unused2:1;
        uint32_t sdio:1;
        uint32_t spi1:1;
        uint32_t _unused3:1;
        uint32_t usart1:1;
        uint32_t _unused4:17;
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
        rcc_control_t control;
        uint32_t icscr;
        rcc_clock_config_t clock_config;
        uint32_t cir;
        ahb_devices_t ahb_reset;
        apb2_device_t apb2_reset;
        apb1_device_t apb1_reset;
        ahb_devices_t ahb_enable;
        apb2_device_t apb2_enable;
        apb1_device_t apb1_enable;
        uint32_t ahb_lpenr;
        uint32_t apb2_lpenr;
        uint32_t apb1_lpenr;
        rcc_control_status_t control_status;
    };
} // namespace Hal

#endif // RCC_T_HH