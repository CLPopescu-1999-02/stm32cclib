#ifndef ISR_EXTEND_HH
#define ISR_EXTEND_HH

#include <stdint.h>

extern "C" {
    namespace isr {
        struct device_vectors { // Table of pointer to interrupt vectors - STM32F303xC specific interrupts
            void (*WWDG)                (); /*!%0 Window WatchDog              */
            void (*PVD)                 (); /*!%1 PVD through EXTI Line detection */
            void (*TAMP_stamp)          (); /*!%2 Tamper and TimeStamps through the EXTI line */
            void (*RTC_wkup)            (); /*!%3 RTC Wakeup through the EXTI line */
            void (*FLASH)               (); /*!%4 FLASH                        */
            void (*RCC)                 (); /*!%5 RCC                          */
            void (*EXTI0)               (); /*!%6 EXTI Line0                   */
            void (*EXTI1)               (); /*!%7 EXTI Line1                   */
            void (*EXTI2_TS)            (); /*!%8 EXTI Line2                   */
            void (*EXTI3)               (); /*!%9 EXTI Line3                   */
            void (*EXTI4)               (); /*!%10 EXTI Line4                  */
            void (*DMA1_channel1)        (); /*!%11 DMA1 channel 1             */
            void (*DMA1_channel2)        (); /*!%12 DMA1 channel 2             */
            void (*DMA1_channel3)        (); /*!%13 DMA1 channel 3             */
            void (*DMA1_channel4)        (); /*!%14 DMA1 channel 4             */
            void (*DMA1_channel5)        (); /*!%15 DMA1 channel 5             */
            void (*DMA1_channel6)        (); /*!%16 DMA1 channel 6             */
            void (*DMA1_channel7)        (); /*!%17 DMA1 channel 7             */
            void (*ADC1_2)              (); /*!%18 ADC1, ADC2                  */
            void (*USB_HP_CAN_TX)       (); /*!%19 USB HP, CAN1 TX             */
            void (*USB_LP_CAN_RX0)      (); /*!%20 USB HP, CAN1 RX0            */
            void (*CAN_RX1)             (); /*!%21 CAN1 RX1                    */
            void (*CAN_SCE)             (); /*!%22 CAN1 SCE                    */
            void (*EXTI9_5)             (); /*!%23 External Line[9:5]s         */
            void (*TIM1_BRK_TIM15)      (); /*!%24 TIM1 Break and TIM15        */
            void (*TIM1_UP_TIM16)       (); /*!%25 TIM1 Update and TIM16       */
            void (*TIM1_TRG_COM_TIM17)  (); /*!%26 TIM1 Trigger and Commutation and TIM17 */
            void (*TIM1_CC)             (); /*!%27 TIM1 Capture Compare        */
            void (*TIM2)                (); /*!%28 TIM2                        */
            void (*TIM3)                (); /*!%29 TIM3                        */
            void (*TIM4)                (); /*!%30 TIM4                        */
            void (*I2C1_EV_EXTI23)      (); /*!%31 I2C1 Event & EXTI Line 23   */
            void (*I2C1_ER)             (); /*!%32 I2C1 Error                  */
            void (*I2C2_EV_EXTI24)      (); /*!%33 I2C2 Event & EXTI Line 24   */
            void (*I2C2_ER)             (); /*!%34 I2C2 Error                  */
            void (*SPI1)                (); /*!%35 SPI1                        */
            void (*SPI2)                (); /*!%36 SPI2                        */
            void (*USART1_EXTI25)       (); /*!%37 USART1 & EXTI Line 25       */
            void (*USART2_EXTI26)       (); /*!%38 USART2 & EXTI Line 26       */
            void (*USART3_EXTI28)       (); /*!%39 USART3 & EXTI Line 27       */
            void (*EXTI15_10)           (); /*!%40 External Line[15:10]s       */
            void (*RTC_Alarm)           (); /*!%41 RTC Alarm (A and B) through EXTI Line */
            void (*USB_wkup)            (); /*!%42 USB OTG FS Wakeup through EXTI line */
            void (*TIM8_BRK)            (); /*!%43 TIM8 Break and TIM12        */
            void (*TIM8_UP_TIM13)       (); /*!%44 TIM8 Update and TIM13       */
            void (*TIM8_TRG_COM)        (); /*!%45 TIM8 Trigger and Commutation and TIM14 */
            void (*TIM8_CC)             (); /*!%46 TIM8 Capture Compare        */
            void (*ADC3)                (); /*!%47 ADC3                        */
            void (*__unused0[3])        (); /*!%48,49,50 unused                */
            void (*SPI3)                (); /*!%51 SPI3                        */
            void (*UART4_EXTI34)        (); /*!%52 UART4 & EXTI Line 34        */
            void (*UART5_EXTI35)        (); /*!%53 UART5 & EXTI Line 35        */
            void (*TIM6_DAC)            (); /*!%54 TIM6 and DAC1&2 underrun errors */
            void (*TIM7)                (); /*!%55 TIM7                        */
            void (*DMA2_channel1)       (); /*!%56 DMA2 channel 1              */
            void (*DMA2_channel2)       (); /*!%57 DMA2 channel 2              */
            void (*DMA2_channel3)       (); /*!%58 DMA2 channel 3              */
            void (*DMA2_channel4)       (); /*!%59 DMA2 channel 4              */
            void (*DMA2_channel5)       (); /*!%60 DMA2 channel 5              */
            void (*ADC4)                (); /*!%61 ADC4                        */
            void (*__unused1[2])        (); /*!%62,63 unused                   */
            void (*COMP_1_2_3)          (); /*!%64 Comparator 1, 2, 3          */
            void (*COMP_4_5_6)          (); /*!%65 Comparator 4, 5, 6          */
            void (*COMP_7)              (); /*!%66 Comparator 7                */
            void (*__unused2[7])        (); /*!%67-73 unused                   */
            void (*USB_HP)              (); /*!%74 USB HP                      */
            void (*USB_LP)              (); /*!%75 USB LP                      */
            void (*USB_WKUP_RMP)        (); /*!%76 USB OTG HS Wakeup through EXTI */
            void (*__unused3[4])        (); /*!%77,78,79,80 unused             */
            void (*FPU)                 (); /*!%81 FPU                         */
        };

        void WWDG();
        void PVD();
        void TAMP_stamp();
        void RTC_wkup();
        void FLASH();
        void RCC();
        void EXTI0();
        void EXTI1();
        void EXTI2_TS();
        void EXTI3();
        void EXTI4();
        void DMA1_channel1();
        void DMA1_channel2();
        void DMA1_channel3();
        void DMA1_channel4();
        void DMA1_channel5();
        void DMA1_channel6();
        void DMA1_channel7();
        void ADC1_2();
        void USB_HP_CAN_TX();
        void USB_LP_CAN_RX0();
        void CAN_RX1();
        void CAN_SCE();
        void EXTI9_5();
        void TIM1_BRK_TIM15();
        void TIM1_UP_TIM16();
        void TIM1_TRG_COM_TIM17();
        void TIM1_CC();
        void TIM2();
        void TIM3();
        void TIM4();
        void I2C1_EV_EXTI23();
        void I2C1_ER();
        void I2C2_EV_EXTI24();
        void I2C2_ER();
        void SPI1();
        void SPI2();
        void USART1_EXTI25();
        void USART2_EXTI26();
        void USART3_EXTI28();
        void EXTI15_10();
        void RTC_Alarm();
        void USB_wkup();
        void TIM8_BRK();
        void TIM8_UP_TIM13();
        void TIM8_TRG_COM();
        void TIM8_CC();
        void ADC3();
        void SPI3();
        void UART4_EXTI34();
        void UART5_EXTI35();
        void TIM6_DAC();
        void TIM7();
        void DMA2_channel1();
        void DMA2_channel2();
        void DMA2_channel3();
        void DMA2_channel4();
        void DMA2_channel5();
        void ADC4();
        void COMP_1_2_3();
        void COMP_4_5_6();
        void COMP_7();
        void USB_HP();
        void USB_LP();
        void USB_WKUP_RMP();
        void FPU();
    }
}
#endif // ISR_EXTEND_HH
