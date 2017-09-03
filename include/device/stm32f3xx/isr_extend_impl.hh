#ifndef ISR_EXTEND_IMPL_HH
#define ISR_EXTEND_IMPL_HH

extern "C" {
    namespace isr {
        void default_handler_extend(); // default handler for undefined device handlers

        void WWDG() __attribute__ ((weak, alias ("default_handler_extend")));
        void PVD() __attribute__ ((weak, alias ("default_handler_extend")));
        void TAMP_stamp() __attribute__ ((weak, alias ("default_handler_extend")));
        void RTC_wkup() __attribute__ ((weak, alias ("default_handler_extend")));
        void FLASH() __attribute__ ((weak, alias ("default_handler_extend")));
        void RCC() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI0() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI1() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI2_TS() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI3() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI4() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel1() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel2() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel3() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel4() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel5() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel6() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel7() __attribute__ ((weak, alias ("default_handler_extend")));
        void ADC1_2() __attribute__ ((weak, alias ("default_handler_extend")));
        void USB_HP_CAN_TX() __attribute__ ((weak, alias ("default_handler_extend")));
        void USB_LP_CAN_RX0() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN_RX1() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN_SCE() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI9_5() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM1_BRK_TIM15() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM1_UP_TIM16() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM1_TRG_COM_TIM17() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM1_CC() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM2() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM3() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM4() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C1_EV_EXTI23() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C1_ER() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C2_EV_EXTI24() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C2_ER() __attribute__ ((weak, alias ("default_handler_extend")));
        void SPI1() __attribute__ ((weak, alias ("default_handler_extend")));
        void SPI2() __attribute__ ((weak, alias ("default_handler_extend")));
        void USART1_EXTI25() __attribute__ ((weak, alias ("default_handler_extend")));
        void USART2_EXTI26() __attribute__ ((weak, alias ("default_handler_extend")));
        void USART3_EXTI28() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI15_10() __attribute__ ((weak, alias ("default_handler_extend")));
        void RTC_Alarm() __attribute__ ((weak, alias ("default_handler_extend")));
        void USB_wkup() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM8_BRK() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM8_UP_TIM13() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM8_TRG_COM() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM8_CC() __attribute__ ((weak, alias ("default_handler_extend")));
        void ADC3() __attribute__ ((weak, alias ("default_handler_extend")));
        void SPI3() __attribute__ ((weak, alias ("default_handler_extend")));
        void UART4_EXTI34() __attribute__ ((weak, alias ("default_handler_extend")));
        void UART5_EXTI35() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM6_DAC() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM7() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel1() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel2() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel3() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel4() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel5() __attribute__ ((weak, alias ("default_handler_extend")));
        void ADC4() __attribute__ ((weak, alias ("default_handler_extend")));
        void COMP_1_2_3() __attribute__ ((weak, alias ("default_handler_extend")));
        void COMP_4_5_6() __attribute__ ((weak, alias ("default_handler_extend")));
        void COMP_7() __attribute__ ((weak, alias ("default_handler_extend")));
        void USB_HP() __attribute__ ((weak, alias ("default_handler_extend")));
        void USB_LP() __attribute__ ((weak, alias ("default_handler_extend")));
        void USB_WKUP_RMP() __attribute__ ((weak, alias ("default_handler_extend")));
        void FPU() __attribute__ ((weak, alias ("default_handler_extend")));
    }
}
#endif // ISR_EXTEND_IMPL_HH
