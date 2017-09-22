#ifndef DBG_T_HH
#define DBG_T_HH

#include "hal/common/dbg_common_t.hh"

namespace hal {
    using dbg_config_sleep = lib::regbit<0>;
    using dbg_config_stop = lib::regbit<1>;
    using dbg_config_standby = lib::regbit<2>;
    using dbg_config_trace_ioen = lib::regbit<5>;
    using dbg_config_trace_mode =
        lib::regbit8<6, 2>;

    using dbg_apb1_fz_tim2_stop = lib::regbit<0>;
    using dbg_apb1_fz_tim3_stop = lib::regbit<1>;
    using dbg_apb1_fz_tim4_stop = lib::regbit<2>;
    using dbg_apb1_fz_tim5_stop = lib::regbit<3>;
    using dbg_apb1_fz_tim6_stop = lib::regbit<4>;
    using dbg_apb1_fz_tim7_stop = lib::regbit<5>;
    using dbg_apb1_fz_tim12_stop = lib::regbit<6>;
    using dbg_apb1_fz_tim13_stop = lib::regbit<7>;
    using dbg_apb1_fz_tim14_stop = lib::regbit<8>;
    using dbg_apb1_fz_rtc_stop = lib::regbit<10>;
    using dbg_apb1_fz_wwdg_stop = lib::regbit<11>;
    using dbg_apb1_fz_iwdg_stop = lib::regbit<12>;
    using dbg_apb1_fz_i2c1_smbus_timeout = lib::regbit<21>;
    using dbg_apb1_fz_i2c2_smbus_timeout = lib::regbit<22>;
    using dbg_apb1_fz_i2c3_smbus_timeout = lib::regbit<23>;
    using dbg_apb1_fz_can1_stop = lib::regbit<25>;
    using dbg_apb1_fz_can2_stop = lib::regbit<26>;

    using dbg_apb2_fz_tim1_stop = lib::regbit<0>;
    using dbg_apb2_fz_tim8_stop = lib::regbit<1>;
    using dbg_apb2_fz_tim9_stop = lib::regbit<16>;
    using dbg_apb2_fz_tim10_stop = lib::regbit<17>;
    using dbg_apb2_fz_tim11_stop = lib::regbit<18>;
}

#endif // DBG_T_HH
