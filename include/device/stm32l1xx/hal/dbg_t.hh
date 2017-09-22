#ifndef DBG_T_HH
#define DBG_T_HH

#include "hal/dbg_common_t.hh"

namespace hal {
    using dbg_config_sleep = lib::regbit<0>;
    using dbg_config_stop = lib::regbit<1>;
    using dbg_config_standby = lib::regbit<2>;
    using dbg_config_trace_ioen = lib::regbit<5>;
    using dbg_config_trace_mode =
        lib::regbit<6, lib::u8, 2, 0>;

    using dbg_apb1_fz_tim2_stop = lib::regbit<0>;
    using dbg_apb1_fz_tim3_stop = lib::regbit<1>;
    using dbg_apb1_fz_tim4_stop = lib::regbit<2>;
    using dbg_apb1_fz_tim5_stop = lib::regbit<3>;
    using dbg_apb1_fz_tim6_stop = lib::regbit<4>;
    using dbg_apb1_fz_tim7_stop = lib::regbit<5>;
    using dbg_apb1_fz_rtc_stop = lib::regbit<10>;
    using dbg_apb1_fz_wwdg_stop = lib::regbit<11>;
    using dbg_apb1_fz_iwdg_stop = lib::regbit<12>;
    using dbg_apb1_fz_i2c1_smbus_timeout = lib::regbit<21>;
    using dbg_apb1_fz_i2c2_smbus_timeout = lib::regbit<22>;

    using dbg_apb2_fz_tim9_stop = lib::regbit<2>;
    using dbg_apb2_fz_tim10_stop = lib::regbit<3>;
    using dbg_apb2_fz_tim11_stop = lib::regbit<4>;
}

#endif // DBG_T_HH
