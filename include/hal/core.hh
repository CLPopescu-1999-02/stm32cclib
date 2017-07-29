#ifndef CORE_HH
#define CORE_HH
#include <stdint.h>

namespace hal {
    enum struct irq_n_t : int32_t {
        NMI = -14,
        mem_manage = -12,
        bus_fault = -11,
        usage_fault = -10,
        SVC = -5,
        debug_mon = -4,
        pend_SV = -2,
        sys_tick_timer = -1,
    };

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

    struct nvic_t {
        uint32_t iser[8];
        uint32_t __reserved0[24];
        uint32_t icer[8];
        uint32_t __reserved1[24];
        uint32_t ispr[8];
        uint32_t __reserved2[24];
        uint32_t icpr[8];
        uint32_t __reserved3[24];
        uint32_t iabr[8];
        uint32_t __reserved4[56];
        uint32_t ip[240];
        uint32_t __reserved5[644];
        uint32_t stir;

        template <typename Irq_t>
        void enable_irq(Irq_t irq_n) volatile {
            iser[((uint32_t)(irq_n) >> 5)] =
                (1 << ((uint32_t)(irq_n) & 0x1f));
        }
    };

    namespace sys_tick_int {
        const uint32_t load_reload_msk = 0xffffff;
        const uint32_t clock_src_msc = 1 << 2;
        const uint32_t tick_int = 1 << 1;
        const uint32_t enable = 1;
    }

    struct sys_tick_t {
        uint32_t control;
        uint32_t load;
        uint32_t value;
        uint32_t calib;

        bool config(uint32_t ticks) volatile {
            if (ticks > sys_tick_int::load_reload_msk)
                return false;
            load = (ticks & sys_tick_int::load_reload_msk) - 1;
            value = 0;
            control = sys_tick_int::clock_src_msc |
                sys_tick_int::tick_int |
                sys_tick_int::enable;

            return true;
        }
    };

    volatile sys_tick_t * const sys_tick = reinterpret_cast<sys_tick_t *>(0xe000e000 + 0x10);
    volatile nvic_t * const nvic = reinterpret_cast<nvic_t *>(0xe000e000 + 0x100);
} // namespace Hal

#endif // CORE_HH

