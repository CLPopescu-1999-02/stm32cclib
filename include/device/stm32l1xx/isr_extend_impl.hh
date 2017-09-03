#ifndef ISR_EXTEND_IMPL_HH
#define ISR_EXTEND_IMPL_HH

extern "C" {
    namespace isr {
        void default_handler_extend(); // default handler for undefined device handlers

        void WWDG() __attribute__ ((weak, alias ("default_handler_extend")));
        void PVD() __attribute__ ((weak, alias ("default_handler_extend")));
        void TAMP_stamp() __attribute__ ((weak, alias ("default_handler_extend")));
        void RTC_wkup() __attribute__ ((weak, alias ("default_handler_extend")));
        void flash() __attribute__ ((weak, alias ("default_handler_extend")));
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
        void ADC1() __attribute__ ((weak, alias ("default_handler_extend")));
        void USB_HP() __attribute__ ((weak, alias ("default_handler_extend")));
        void USB_LP() __attribute__ ((weak, alias ("default_handler_extend")));
        void DAC() __attribute__ ((weak, alias ("default_handler_extend")));
        void COMP_TSC() __attribute__ ((weak, alias ("default_handler_extend")));
        void EXTI9_5_IRQ() __attribute__ ((weak, alias ("default_handler_extend")));
        void LCD() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM9() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM10() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM11() __attribute__ ((weak, alias ("default_handler_extend")));
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
        void USB_wkup() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM6() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM7() __attribute__ ((weak, alias ("default_handler_extend")));
        void TIM5() __attribute__ ((weak, alias ("default_handler_extend")));
        void SPI3() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel1() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel2() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel3() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel4() __attribute__ ((weak, alias ("default_handler_extend")));
        void DMA2_channel5() __attribute__ ((weak, alias ("default_handler_extend")));
        void AES() __attribute__ ((weak, alias ("default_handler_extend")));
        void COMP_ACQ() __attribute__ ((weak, alias ("default_handler_extend")));
    }
}
#endif // ISR_EXTEND_IMPL_HH
