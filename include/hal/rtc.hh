#ifndef RTC_HH
#define RTC_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using rtc_time_su = lib::regbit<0, lib::u8, 4, 0>;
    using rtc_time_st = lib::regbit<4, lib::u8, 3, 0>;
    using rtc_time_mnu = lib::regbit<8, lib::u8, 4, 0>;
    using rtc_time_mnt = lib::regbit<12, lib::u8, 3, 0>;
    using rtc_time_hu = lib::regbit<16, lib::u8, 4, 0>;
    using rtc_time_ht = lib::regbit<20, lib::u8, 2, 0>;
    using rtc_time_pm = lib::regbit<22>;

    using rtc_date_du = lib::regbit<0, lib::u8, 4, 0>;
    using rtc_date_dt = lib::regbit<4, lib::u8, 2, 0>;
    using rtc_date_mu = lib::regbit<8, lib::u8, 4, 0>;
    using rtc_date_mt = lib::regbit<12, lib::u8, 1, 0>;
    enum struct rtc_date_wdu_t : lib::u8 {
        monday = 0b001,
        tuesday = 0b010,
        wednesday = 0b011,
        thursday = 0b100,
        friday = 0b101,
        saturday = 0b110,
        sunday = 0b111
    };
    using rtc_date_wdu =
        lib::regbit<13,
        rtc_date_wdu_t,
        3,
        rtc_date_wdu_t::monday>;
    using rtc_date_yu = lib::regbit<16, lib::u8, 4, 0>;
    using rtc_date_yt = lib::regbit<20, lib::u8, 4, 0>;

    enum struct rtc_control_wucksel_t : lib::u8 {
        rtc_by16 = 0b000,
        rtc_by8 = 0b001,
        rtc_by4 = 0b010,
        rtc_by2 = 0b011,
        ck_spre = 0b100,
        ck_spre_wut_add = 0b110
    };
    using rtc_control_wucksel =
        lib::regbit<0,
        rtc_control_wucksel_t,
        3,
        rtc_control_wucksel_t::rtc_by16>;
    using rtc_control_tsedge = lib::regbit<3>;
    using rtc_control_refckon = lib::regbit<4>;
    using rtc_control_bypshad = lib::regbit<5>;
    using rtc_control_fmt = lib::regbit<6>;
    using rtc_control_dce = lib::regbit<7>;
    using rtc_control_alrae = lib::regbit<8>;
    using rtc_control_alrbe = lib::regbit<9>;
    using rtc_control_wute = lib::regbit<10>;
    using rtc_control_tse = lib::regbit<11>;
    using rtc_control_alraie = lib::regbit<12>;
    using rtc_control_alrbie = lib::regbit<13>;
    using rtc_control_wutie = lib::regbit<14>;
    using rtc_control_tsie = lib::regbit<15>;
    using rtc_control_add1h = lib::regbit<16>;
    using rtc_control_sub1h = lib::regbit<17>;
    using rtc_control_bkp = lib::regbit<18>;
    using rtc_control_cosel = lib::regbit<19>;
    using rtc_control_pol = lib::regbit<20>;
    enum struct rtc_control_osel_t : lib::u8 {
        disabled = 0b00,
        alarm_a = 0b01,
        alarm_b = 0b10,
        wakeup = 0b11,
    };
    using rtc_control_osel =
        lib::regbit<21,
        rtc_control_osel_t,
        2,
        rtc_control_osel_t::disabled>;
    using rtc_control_coe = lib::regbit<23>;

    using rtc_init_status_alrawf = lib::regbit<0>;
    using rtc_init_status_alrbwf = lib::regbit<1>;
    using rtc_init_status_wutwf = lib::regbit<2>;
    using rtc_init_status_shpf = lib::regbit<3>;
    using rtc_init_status_inits = lib::regbit<4>;
    using rtc_init_status_rsf = lib::regbit<5>;
    using rtc_init_status_initf = lib::regbit<6>;
    using rtc_init_status_init = lib::regbit<7>;
    using rtc_init_status_alraf = lib::regbit<8>;
    using rtc_init_status_alrbf = lib::regbit<9>;
    using rtc_init_status_wutf = lib::regbit<10>;
    using rtc_init_status_tsf = lib::regbit<11>;
    using rtc_init_status_tsovf = lib::regbit<12>;
    using rtc_init_status_tamp1f = lib::regbit<13>;
    using rtc_init_status_tamp2f = lib::regbit<14>;
    using rtc_init_status_tamp3f = lib::regbit<15>;
    using rtc_init_status_recalpf = lib::regbit<16>;

    using rtc_prescaler_prediv_s = lib::regbit<0, lib::u16, 15, 0>;
    using rtc_prescaler_prediv_a = lib::regbit<16, lib::u8, 7, 1>;

    struct rtc_wakeup_timer_t {
        uint16_t wut;
        uint16_t _unused0;
    };

    using rtc_calib_dc = lib::regbit<0, lib::u8, 5, 0>;
    using rtc_calib_dcs = lib::regbit<7>;

    using rtc_alarm_su = lib::regbit<0, lib::u8, 4, 0>;
    using rtc_alarm_st = lib::regbit<4, lib::u8, 3, 0>;
    using rtc_alarm_msk1 = lib::regbit<7>;
    using rtc_alarm_mnu = lib::regbit<8, lib::u8, 4, 0>;
    using rtc_alarm_mnt = lib::regbit<12, lib::u8, 3, 0>;
    using rtc_alarm_msk2 = lib::regbit<15>;
    using rtc_alarm_hu = lib::regbit<16, lib::u8, 4, 0>;
    using rtc_alarm_ht = lib::regbit<20, lib::u8, 2, 0>;
    using rtc_alarm_pm = lib::regbit<22>;
    using rtc_alarm_msk3 = lib::regbit<23>;
    using rtc_alarm_du = lib::regbit<24, lib::u8, 4, 0>;
    using rtc_alarm_wdu =
        lib::regbit<24,
        rtc_date_wdu_t,
        3,
        rtc_date_wdu_t::monday>;
    using rtc_alarm_dt = lib::regbit<28, lib::u8, 2, 0>;
    using rtc_alarm_wdsel = lib::regbit<30>;
    using rtc_alarm_msk4 = lib::regbit<31>;

    struct rtc_sub_second_t {
        uint16_t ss;
        uint16_t _unused0;
    };

    using rtc_shift_subfs = lib::regbit<0, lib::u16, 15, 0>;
    using rtc_shift_add1s = lib::regbit<31>;

    struct rtc_write_protect_t {
        uint8_t key;
        uint8_t _unused0[3];
    };

    using rtc_calib2_calm = lib::regbit<0, lib::u16, 9, 0>;
    using rtc_calib2_calw16 = lib::regbit<13>;
    using rtc_calib2_calw8 = lib::regbit<14>;
    using rtc_calib2_calp = lib::regbit<15>;

    using rtc_tamper_alt_func_tamp1e = lib::regbit<0>;
    using rtc_tamper_alt_func_tamp1trg = lib::regbit<1>;
    using rtc_tamper_alt_func_tampie = lib::regbit<2>;
    using rtc_tamper_alt_func_tamp2e = lib::regbit<3>;
    using rtc_tamper_alt_func_tamp2trg = lib::regbit<4>;
    using rtc_tamper_alt_func_tamp3e = lib::regbit<5>;
    using rtc_tamper_alt_func_tamp3trg = lib::regbit<6>;
    using rtc_tamper_alt_func_tampts = lib::regbit<7>;
    enum struct rtc_tamper_alt_func_tampfreq_t : lib::u8 {
        rtc_by32768 = 0x0,
        rtc_by16384 = 0x1,
        rtc_by8192 = 0x2,
        rtc_by4096 = 0x3,
        rtc_by2048 = 0x4,
        rtc_by1024 = 0x5,
        rtc_by512 = 0x6,
        rtc_by256 = 0x7,
    };
    using rtc_tamper_alt_func_tampfreq =
        lib::regbit<8,
        rtc_tamper_alt_func_tampfreq_t,
        3,
        rtc_tamper_alt_func_tampfreq_t::rtc_by32768>;
    enum struct rtc_tamper_alt_func_tampflt_t : lib::u8 {
        on_edge = 0x0,
        after2 = 0x1,
        after4 = 0x2,
        after8 = 0x3,
    };
    using rtc_tamper_alt_func_tampflt =
        lib::regbit<11,
        rtc_tamper_alt_func_tampflt_t,
        2,
        rtc_tamper_alt_func_tampflt_t::on_edge>;
    enum struct rtc_tamper_alt_func_tampprch_t : lib::u8 {
        each1 = 0x0,
        each2 = 0x1,
        each4 = 0x2,
        each8 = 0x3,
    };
    using rtc_tamper_alt_func_tampprch =
        lib::regbit<13,
        rtc_tamper_alt_func_tampprch_t,
        2,
        rtc_tamper_alt_func_tampprch_t::each1>;
    using rtc_tamper_alt_func_tamppudis = lib::regbit<15>;
    using rtc_tamper_alt_func_alarmouttype = lib::regbit<18>;

    using rtc_alarm_sub_second_ss = lib::regbit<0, lib::u16, 15, 0>;
    using rtc_alarm_sub_second_maskss = lib::regbit<24, lib::u8, 4, 0>;

    template <lib::u32 addr, lib::u8 backup_size>
    struct rtc_d {
        struct rtc_t {
            lib::u32 time;
            lib::u32 date;
            lib::u32 control;
            lib::u32 init_status;
            lib::u32 prescaler;
            rtc_wakeup_timer_t wakeup_timer;
            lib::u32 calib;
            lib::u32 alarma;
            lib::u32 alarmb;
            rtc_write_protect_t write_protect;
            rtc_sub_second_t sub_second;
            lib::u32 shift;
            lib::u32 ts_time;
            lib::u32 ts_date;
            rtc_sub_second_t ts_sub_second;
            lib::u32 calib2;
            lib::u32 tamper_alt_func;
            lib::u32 alarma_sub_second;
            lib::u32 alarmb_sub_second;
            lib::u32 bkpr[backup_size];
        };

        static constexpr volatile rtc_t * const regs =
            reinterpret_cast<rtc_t *>(addr);
    };
}

#include "hal/rtc_d.hh"

#endif // RTC_HH
