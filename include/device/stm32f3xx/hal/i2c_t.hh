#ifndef I2C_T_HH
#define I2C_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using i2c_control1_pe = lib::regbit<0>;
    using i2c_control1_txie = lib::regbit<1>;
    using i2c_control1_rxie = lib::regbit<2>;
    using i2c_control1_addrie = lib::regbit<3>;
    using i2c_control1_nackie = lib::regbit<4>;
    using i2c_control1_stopie = lib::regbit<5>;
    using i2c_control1_tcie = lib::regbit<6>;
    using i2c_control1_errie = lib::regbit<7>;
    using i2c_control1_dnf =
        lib::regbit<8, lib::u8, 4, 0>;
    using i2c_control1_anfoff = lib::regbit<12>;
    using i2c_control1_txdmaen = lib::regbit<14>;
    using i2c_control1_rxdmaen = lib::regbit<15>;
    using i2c_control1_sbc = lib::regbit<16>;
    using i2c_control1_nostretch = lib::regbit<17>;
    using i2c_control1_wupen = lib::regbit<18>;
    using i2c_control1_gcen = lib::regbit<19>;
    using i2c_control1_smbhen = lib::regbit<20>;
    using i2c_control1_smbden = lib::regbit<21>;
    using i2c_control1_alerten = lib::regbit<22>;
    using i2c_control1_pecen = lib::regbit<23>;

    using i2c_control2_sadd =
        lib::regbit<0, lib::u16, 10, 0>;
    using i2c_control2_rd_wrn = lib::regbit<10>;
    using i2c_control2_add10 = lib::regbit<11>;
    using i2c_control2_head10r = lib::regbit<12>;
    using i2c_control2_start = lib::regbit<13>;
    using i2c_control2_stop = lib::regbit<14>;
    using i2c_control2_nack = lib::regbit<15>;
    using i2c_control2_nbytes =
        lib::regbit<16, lib::u8, 8, 0>;
    using i2c_control2_reload = lib::regbit<24>;
    using i2c_control2_autoend = lib::regbit<25>;
    using i2c_control2_pecbyte = lib::regbit<26>;

    using i2c_own_address1_add7 =
        lib::regbit<1, lib::u8, 7, 0>;
    using i2c_own_address1_add10 =
        lib::regbit<0, lib::u16, 10, 0>;
    using i2c_own_address1_addmode = lib::regbit<10>;
    using i2c_own_address1_add1en = lib::regbit<15>;

    using i2c_own_address2_endual = lib::regbit<15>;
    using i2c_own_address2_add2 =
        lib::regbit<1, lib::u8, 7, 0>;
    using i2c_own_address2_msk =
        lib::regbit<8, lib::u8, 3, 0>;

    using i2c_timing_scll =
        lib::regbit<0, lib::u8, 8, 0>;
    using i2c_timing_sclh =
        lib::regbit<8, lib::u8, 8, 0>;
    using i2c_timing_sdadel =
        lib::regbit<16, lib::u8, 4, 0>;
    using i2c_timing_scldel =
        lib::regbit<20, lib::u8, 4, 0>;
    using i2c_timing_presc =
        lib::regbit<28, lib::u8, 4, 0>;

    using i2c_timeout_timeouta =
        lib::regbit<0, lib::u16, 12, 0>;
    using i2c_timeout_tidle = lib::regbit<12>;
    using i2c_timeout_timeouten = lib::regbit<15>;
    using i2c_timeout_timeoutb =
        lib::regbit<16, lib::u16, 12, 0>;
    using i2c_timeout_texten = lib::regbit<31>;

    using i2c_status_txe = lib::regbit<0>;
    using i2c_status_txis = lib::regbit<1>;
    using i2c_status_rxne = lib::regbit<2>;
    using i2c_status_addr = lib::regbit<3>;
    using i2c_status_nackf = lib::regbit<4>;
    using i2c_status_stopf = lib::regbit<5>;
    using i2c_status_tc = lib::regbit<6>;
    using i2c_status_tcr = lib::regbit<7>;
    using i2c_status_berr = lib::regbit<8>;
    using i2c_status_arlo = lib::regbit<9>;
    using i2c_status_ovr = lib::regbit<10>;
    using i2c_status_pecerr = lib::regbit<11>;
    using i2c_status_timeout = lib::regbit<12>;
    using i2c_status_alert = lib::regbit<13>;
    using i2c_status_busy = lib::regbit<15>;
    using i2c_status_dir = lib::regbit<16>;
    using i2c_status_addcode =
        lib::regbit<17, lib::u8, 7, 0>;

    template <lib::u32 addr>
    struct i2c_d {
        struct i2c_t {
            lib::u32 control1;
            lib::u32 control2;
            lib::u32 own_address1;
            lib::u32 own_address2;
            lib::u32 timing;
            lib::u32 timeout;
            lib::u32 status;
            lib::u32 clear;
            lib::u8 pecr;
            lib::u8 _unused0;
            lib::u8 _unused1;
            lib::u8 _unused2;
            lib::u8 rxdr;
            lib::u8 _unused3;
            lib::u8 _unused4;
            lib::u8 _unused5;
            lib::u8 txdr;
            lib::u8 _unused6;
            lib::u8 _unused7;
            lib::u8 _unused8;
        };

        static constexpr volatile i2c_t * const regs =
            reinterpret_cast<i2c_t *>(addr);
    };
}

#endif // I2C_T_HH
