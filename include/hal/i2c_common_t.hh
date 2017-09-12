#ifndef I2C_COMMON_T_HH
#define I2C_COMMON_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using i2c_control1_pe = lib::regbit<0>;
    using i2c_control1_smbus = lib::regbit<1>;
    using i2c_control1_smbtype = lib::regbit<3>;
    using i2c_control1_enarp = lib::regbit<4>;
    using i2c_control1_enpec = lib::regbit<5>;
    using i2c_control1_engc = lib::regbit<6>;
    using i2c_control1_nostretch = lib::regbit<7>;
    using i2c_control1_start = lib::regbit<8>;
    using i2c_control1_stop = lib::regbit<9>;
    using i2c_control1_ack = lib::regbit<10>;
    using i2c_control1_pos = lib::regbit<11>;
    using i2c_control1_pec = lib::regbit<12>;
    using i2c_control1_alert = lib::regbit<13>;
    using i2c_control1_swrst = lib::regbit<15>;

    using i2c_control2_freq =
        lib::regbit<0, lib::u8, 6, 2>;
    using i2c_control2_iterren = lib::regbit<8>;
    using i2c_control2_itevten = lib::regbit<9>;
    using i2c_control2_itbufen = lib::regbit<10>;
    using i2c_control2_dmaen = lib::regbit<11>;
    using i2c_control2_last = lib::regbit<12>;

    using i2c_own_address1_add7 =
        lib::regbit<1, lib::u8, 7, 0>;
    using i2c_own_address1_add10 =
        lib::regbit<0, lib::u16, 10, 0>;
    using i2c_own_address1_addmode = lib::regbit<15>;

    using i2c_own_address2_endual = lib::regbit<0>;
    using i2c_own_address2_add2 =
        lib::regbit<1, lib::u8, 7, 0>;

    using i2c_status1_sb = lib::regbit<0>;
    using i2c_status1_addr = lib::regbit<1>;
    using i2c_status1_btf = lib::regbit<2>;
    using i2c_status1_add10 = lib::regbit<3>;
    using i2c_status1_stopf = lib::regbit<4>;
    using i2c_status1_rxne = lib::regbit<6>;
    using i2c_status1_txe = lib::regbit<7>;
    using i2c_status1_berr = lib::regbit<8>;
    using i2c_status1_arlo = lib::regbit<9>;
    using i2c_status1_af = lib::regbit<10>;
    using i2c_status1_ovr = lib::regbit<11>;
    using i2c_status1_pecerr = lib::regbit<12>;
    using i2c_status1_timeout = lib::regbit<14>;
    using i2c_status1_smbalert = lib::regbit<15>;

    using i2c_status2_msl = lib::regbit<0>;
    using i2c_status2_busy = lib::regbit<1>;
    using i2c_status2_tra = lib::regbit<2>;
    using i2c_status2_gencall = lib::regbit<4>;
    using i2c_status2_smbdefault = lib::regbit<5>;
    using i2c_status2_smbhost = lib::regbit<6>;
    using i2c_status2_dualf = lib::regbit<7>;

    using i2c_clock_control_ccr =
        lib::regbit<0, lib::u16, 12, 1>;
    using i2c_clock_control_duty = lib::regbit<14>;
    using i2c_clock_control_f_s = lib::regbit<15>;

    using i2c_trise_trise =
        lib::regbit<0, lib::u8, 6, 0>;

    template <lib::u32 addr>
    struct i2c_d {
        struct i2c_t {
            lib::u32 control1;
            lib::u32 control2;
            lib::u32 own_address1;
            lib::u32 own_address2;
            lib::u8 dr;
            lib::u8 _unused0;
            lib::u8 _unused1;
            lib::u8 _unused2;
            lib::u32 status1;
            lib::u32 status2;
            lib::u32 clock_control;
            lib::u32 trise;
        };

        static constexpr volatile i2c_t * const regs =
            reinterpret_cast<i2c_t *>(addr);
    };
}

#endif // I2C_COMMON_T_HH
