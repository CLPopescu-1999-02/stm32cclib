#ifndef ADC_D_HH
#define ADC_D_HH

namespace hal {
    using adc1 = adc_d<0x40012400>;

    using adc1_common = adc_common_d<0x40012400 + 0x300>;
}

#endif // ADC_D_HH
