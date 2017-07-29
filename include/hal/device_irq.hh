#ifndef DEVICE_IRQ_HH
#define DEVICE_IRQ_HH

#include <stdint.h>

namespace hal {
    enum struct irq_dev_n_t : int32_t {
        WWDG = 0,
        PVD = 1,
        tamp_stamp = 2,
        rtc_wkup = 3,
        flash = 4,
        RCC = 5,
        EXTI0 = 6,
        EXTI1 = 7,
        EXTI2 = 8,
        EXTI3 = 9,
        EXTI4 = 10,
        DMA1_channel1 = 11,
        DMA1_channel2 = 12,
        DMA1_channel3 = 13,
        DMA1_channel4 = 14,
        DMA1_channel5 = 15,
        DMA1_channel6 = 16,
        DMA1_channel7 = 17,
        ADC1 = 18,
        USB_HP = 19,
        USB_LP = 20,
        DAC = 21,
        COMP_TSC = 22,
        EXTI9_5_IRQ = 23,
        LCD = 24,
        TIM9 = 25,
        TIM10 = 26,
        TIM11 = 27,
        TIM2 = 28,
        TIM3 = 29,
        TIM4 = 30,
        I2C1_EV = 31,
        I2C1_ER = 32,
        I2C2_EV = 33,
        I2C2_ER = 34,
        SPI1 = 35,
        SPI2 = 36,
        USART1 = 37,
        USART2 = 38,
        USART3 = 39,
        EXTI15_10 = 40,
        RTC_Alarm = 41,
        USB_WKUP = 42,
        TIM6 = 43,
        TIM7 = 44,
        TIM5 = 45,
        SPI3 = 46,
        DMA2_channel1 = 47,
        DMA2_channel2 = 48,
        DMA2_channel3 = 49,
        DMA2_channel4 = 50,
        DMA2_channel5 = 51,
        AES = 52,
        COMP_ACQ = 53
    };
}

#endif // DEVICE_IRQ_HH
