#ifndef ADC_D_HH
#define ADC_D_HH

namespace hal {
    volatile adc_t * const adc1 = reinterpret_cast<adc_t *>(0x40012400);

    volatile adc_common_t * const adc1_common = reinterpret_cast<adc_common_t *>(0x40012400 + 0x300);
}

#endif // ADC_D_HH
