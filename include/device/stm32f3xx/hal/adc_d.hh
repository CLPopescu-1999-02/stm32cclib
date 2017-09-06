#ifndef ADC_D_HH
#define ADC_D_HH

namespace hal {
    using adc1 = adc_d<0x50000000>;
    using adc2 = adc_d<0x50000000 + 0x100>;

    using adc12_common = adc_common_d<0x50000000 + 0x300>;

    using adc3 = adc_d<0x50000400>;
    using adc4 = adc_d<0x50000400 + 0x100>;

    using adc34_common = adc_common_d<0x50000400 + 0x300>;
}

#endif // ADC_D_HH
