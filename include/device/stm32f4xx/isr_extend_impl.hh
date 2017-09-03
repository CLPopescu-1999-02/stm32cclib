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
        void EXTI2() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI3() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI4() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel1() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel2() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel3() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel4() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel5() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel6() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel7() __attribute__ ((weak, alias ("default_handler_extend")));
        void ADC() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN1_TX() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN1_RX0() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN1_RX1() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN1_SCE() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI9_5() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM1_BRK_TIM9() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM1_UP_TIM10() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM1_TRG_COM_TIM11() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM1_CC() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM2() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM3() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM4() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C1_EV() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C1_ER() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C2_EV() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C2_ER() __attribute__ ((weak, alias ("default_handler_extend")));
        void SPI1() __attribute__ ((weak, alias ("default_handler_extend")));
        void SPI2() __attribute__ ((weak, alias ("default_handler_extend")));
        void USART1() __attribute__ ((weak, alias ("default_handler_extend")));
        void USART2() __attribute__ ((weak, alias ("default_handler_extend")));
        void USART3() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI15_10() __attribute__ ((weak, alias ("default_handler_extend")));
        void RTC_Alarm() __attribute__ ((weak, alias ("default_handler_extend")));
        void OTG_FS_wkup() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM8_BRK_TIM12() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM8_UP_TIM13() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM8_TRG_COM_TIM14() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM8_CC() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA1_channel8() __attribute__ ((weak, alias ("default_handler_extend")));
        void FSMC() __attribute__ ((weak, alias ("default_handler_extend")));
        void SDIO() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM5() __attribute__ ((weak, alias ("default_handler_extend")));
        void SPI3() __attribute__ ((weak, alias ("default_handler_extend")));
        void UART4() __attribute__ ((weak, alias ("default_handler_extend")));
        void UART5() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM6_DAC() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM7() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel1() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel2() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel3() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel4() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel5() __attribute__ ((weak, alias ("default_handler_extend")));
        void ETH() __attribute__ ((weak, alias ("default_handler_extend")));
        void ETH_wkup() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN2_TX() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN2_RX0() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN2_RX1() __attribute__ ((weak, alias ("default_handler_extend")));
        void CAN2_SCE() __attribute__ ((weak, alias ("default_handler_extend")));
        void OTG_FS() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel6() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel7() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel8() __attribute__ ((weak, alias ("default_handler_extend")));
        void USART6() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C3_EV() __attribute__ ((weak, alias ("default_handler_extend")));
        void I2C3_ER() __attribute__ ((weak, alias ("default_handler_extend")));
        void OTG_HS_EP1_OUT() __attribute__ ((weak, alias ("default_handler_extend")));
        void OTG_HS_EP1_IN() __attribute__ ((weak, alias ("default_handler_extend")));
        void OTG_HS_WKUP() __attribute__ ((weak, alias ("default_handler_extend")));
        void OTG_HS() __attribute__ ((weak, alias ("default_handler_extend")));
        void DCMI() __attribute__ ((weak, alias ("default_handler_extend")));
        void CRYP() __attribute__ ((weak, alias ("default_handler_extend")));
        void HASH_RNG() __attribute__ ((weak, alias ("default_handler_extend")));
        void FPU() __attribute__ ((weak, alias ("default_handler_extend")));
    }
}

#endif // ISR_EXTEND_IMPL_HH
