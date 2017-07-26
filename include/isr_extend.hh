#ifndef ISR_EXTEND_HH
#define ISR_EXTEND_HH

#include <stdint.h>

extern "C" {
    namespace isr {
        struct device_vectors { // Table of pointer to interrupt vectors - STM32L152xC specific interrupts
            void (*WWDG)            (); /*!%0 Window WatchDog */
            void (*PVD)             (); /*!%1 PVD through EXTI Line detection */
            void (*tamp_stamp)      (); /*!%2 Tamper and TimeStamps through the EXTI line */
            void (*rtc_wkup)        (); /*!%3 RTC Wakeup through the EXTI line */
            void (*flash)           (); /*!%4 FLASH */
            void (*RCC)             (); /*!%5 RCC */
            void (*EXTI0)           (); /*!%6 EXTI Line0 */
            void (*EXTI1)           (); /*!%7 EXTI Line1 */
            void (*EXTI2)           (); /*!%8 EXTI Line2 */
            void (*EXTI3)           (); /*!%9 EXTI Line3 */
            void (*EXTI4)           (); /*!%10 EXTI Line4 */
            void (*DMA1_channel1)   (); /*!%11 DMA1 channel 1 */
            void (*DMA1_channel2)   (); /*!%12 DMA1 channel 2 */
            void (*DMA1_channel3)   (); /*!%13 DMA1 channel 3 */
            void (*DMA1_channel4)   (); /*!%14 DMA1 channel 4 */
            void (*DMA1_channel5)   (); /*!%15 DMA1 channel 5 */
            void (*DMA1_channel6)   (); /*!%16 DMA1 channel 6 */
            void (*DMA1_channel7)   (); /*!%17 DMA1 channel 7 */
            void (*ADC1)            (); /*!%18 ADC1 */
            void (*USB_HP)          (); /*!%19 USB HP */
            void (*USB_LP)          (); /*!%20 USB LP */
            void (*DAC)             (); /*!%21 DAC */
            void (*COMP_TSC)        (); /*!%22 Comparator wakeup, Touch sensor */
            void (*EXTI9_5_IRQ)     (); /*!%23 External Line[9:5]s */
            void (*LCD)             (); /*!%24 LCD */
            void (*TIM9)            (); /*!%25 TIM9 */
            void (*TIM10)           (); /*!%26 TIM10 */
            void (*TIM11)           (); /*!%27 TIM11 */
            void (*TIM2)            (); /*!%28 TIM2 */
            void (*TIM3)            (); /*!%29 TIM3 */
            void (*TIM4)            (); /*!%30 TIM4 */
            void (*I2C1_EV)         (); /*!%31 I2C1 Event */
            void (*I2C1_ER)         (); /*!%32 I2C1 Error */
            void (*I2C2_EV)         (); /*!%33 I2C2 Event */
            void (*I2C2_ER)         (); /*!%34 I2C2 Error */
            void (*SPI1)            (); /*!%35 SPI1 */
            void (*SPI2)            (); /*!%36 SPI2 */
            void (*USART1)          (); /*!%37 USART1 */
            void (*USART2)          (); /*!%38 USART2 */
            void (*USART3)          (); /*!%39 USART3 */
            void (*EXTI15_10)       (); /*!%40 External Line[15:10]s */
            void (*RTC_Alarm)       (); /*!%41 RTC Alarm (A and B) through EXTI Line */
            void (*USB_WKUP)        (); /*!%42 USB OTG FS Wakeup through EXTI line */
            void (*TIM6)            (); /*!%43 TIM6 */
            void (*TIM7)            (); /*!%44 TIM7 */
        };

        void WWDG();
        void PVD();
        void tamp_stamp();
        void rtc_wkup();
        void flash();
        void RCC();
        void EXTI0();
        void EXTI1();
        void EXTI2();
        void EXTI3();
        void EXTI4();
        void DMA1_channel1();
        void DMA1_channel2();
        void DMA1_channel3();
        void DMA1_channel4();
        void DMA1_channel5();
        void DMA1_channel6();
        void DMA1_channel7();
        void ADC1();
        void USB_HP();
        void USB_LP();
        void DAC();
        void COMP_TSC();
        void EXTI9_5_IRQ();
        void LCD();
        void TIM9();
        void TIM10();
        void TIM11();
        void TIM2();
        void TIM3();
        void TIM4();
        void I2C1_EV();
        void I2C1_ER();
        void I2C2_EV();
        void I2C2_ER();
        void SPI1();
        void SPI2();
        void USART1();
        void USART2();
        void USART3();
        void EXTI15_10();
        void RTC_Alarm();
        void USB_WKUP();
        void TIM6();
        void TIM7();
    }
}
#endif // ISR_EXTEND_HH
