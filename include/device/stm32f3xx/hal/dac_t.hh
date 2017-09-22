#ifndef DAC_T_HH
#define DAC_T_HH

#include "hal/common/dac_common_t.hh"

namespace hal {
    enum struct dac_control_tsel_t : lib::u8 {
        tim6_trgo = 0,
        tim3_8_trgo = 1,
        tim7_trgo = 2,
        tim15_trgo = 3,
        tim2_trgo = 4,
        tim4_trgo = 5,
        ext_line9 = 6,
        sw_trigger = 7
    };
    using dac_control_tsel1 =
        lib::regbit<3,
            dac_control_tsel_t,
            3,
            dac_control_tsel_t::tim6_trgo>;
    using dac_control_tsel2 =
        lib::regbit<19,
            dac_control_tsel_t,
            3,
            dac_control_tsel_t::tim6_trgo>;
}

#endif // DAC_T_HH
