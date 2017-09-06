#ifndef ADC_D_HH
#define ADC_D_HH

namespace hal {
    using adc1 = adc_d<0x40012000>;
    using adc2 = adc_d<0x40012000 + 0x100>;
    using adc3 = adc_d<0x40012000 + 0x200>;

    using adc1_common = adc_common_d<0x40012000 + 0x300>;
}

#endif // ADC_D_HH
