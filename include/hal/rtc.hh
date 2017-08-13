#ifndef RTC_HH
#define RTC_HH

#include <stdint.h>

namespace hal {
    struct rtc_time_t {
        uint32_t su:4;
        uint32_t st:3;
        uint32_t _unused0:1;
        uint32_t mnu:4;
        uint32_t mnt:3;
        uint32_t _unused1:1;
        uint32_t hu:4;
        uint32_t ht:2;
        uint32_t pm:1;
        uint32_t _unused2:9;
    };

    struct rtc_date_t {
        uint32_t du:4;
        uint32_t dt:2;
        uint32_t _unused0:2;
        uint32_t mu:4;
        uint32_t mt:1;
        uint32_t wdu:3;
        uint32_t yu:4;
        uint32_t yt:4;
        uint32_t _unused1:8;
    };

    struct rtc_control_t {
        uint32_t wucksel:3;
        uint32_t tsedge:1;
        uint32_t refckon:1;
        uint32_t bypshad:1;
        uint32_t fmt:1;
        uint32_t dce:1;
        uint32_t alrae:1;
        uint32_t alrbe:1;
        uint32_t wute:1;
        uint32_t tse:1;
        uint32_t alraie:1;
        uint32_t alrbie:1;
        uint32_t wutie:1;
        uint32_t tsie:1;
        uint32_t add1h:1;
        uint32_t sub1h:1;
        uint32_t bkp:1;
        uint32_t cosel:1;
        uint32_t pol:1;
        uint32_t osel:2;
        uint32_t coe:1;
        uint32_t _unused0:8;
    };

    struct rtc_init_status_t {
        uint32_t alrawf:1;
        uint32_t alrbwf:1;
        uint32_t wutwf:1;
        uint32_t shpf:1;
        uint32_t inits:1;
        uint32_t rsf:1;
        uint32_t initf:1;
        uint32_t init:1;
        uint32_t alraf:1;
        uint32_t alrbf:1;
        uint32_t wutf:1;
        uint32_t tsf:1;
        uint32_t tsovf:1;
        uint32_t tamp1f:1;
        uint32_t tamp2f:1;
        uint32_t tamp3f:1;
        uint32_t recalpf:1;
        uint32_t _unused0:15;
    };

    struct rtc_prescaler_t {
        uint32_t prediv_s:15;
        uint32_t _unused0:1;
        uint32_t prediv_a:7;
        uint32_t _unused1:9;
    };

    struct rtc_wakeup_timer_t {
        uint32_t wut:16;
        uint32_t _unused0:16;
    };

    struct rtc_calib_t {
        uint32_t dc:5;
        uint32_t _unused0:2;
        uint32_t dcs:1;
        uint32_t _unused1:24;
    };

    struct rtc_alarm_t {
        uint32_t su:4;
        uint32_t st:3;
        uint32_t msk1:1;
        uint32_t mnu:4;
        uint32_t mnt:3;
        uint32_t msk2:1;
        uint32_t hu:4;
        uint32_t ht:2;
        uint32_t pm:1;
        uint32_t msk3:1;
        uint32_t du:4;
        uint32_t dt:2;
        uint32_t wdsel:1;
        uint32_t msk4:1;
    };

    struct rtc_write_protect_t {
        uint8_t key;
        uint8_t _unused0[3];
    };

    struct rtc_sub_second_t {
        uint32_t ss:16;
        uint32_t _unused0:16;
    };

    struct rtc_shift_t {
        uint32_t subfs:15;
        uint32_t _unused0:16;
        uint32_t add1s:1;
    };

    struct rtc_calib2_t {
        uint32_t calm:9;
        uint32_t _unused0:4;
        uint32_t calw16:1;
        uint32_t calw8:1;
        uint32_t calp:1;
        uint32_t _unused1:16;
    };

    struct rtc_tamper_alt_func_t {
        uint32_t tamp1e:1;
        uint32_t tamp1trg:1;
        uint32_t tampie:1;
        uint32_t tamp2e:1;
        uint32_t tamp2trg:1;
        uint32_t tamp3e:1;
        uint32_t tamp3trg:1;
        uint32_t tampts:1;
        uint32_t tampfreq:3;
        uint32_t tampflt:2;
        uint32_t tampprch:2;
        uint32_t tamppudis:1;
        uint32_t _unused0:2;
        uint32_t alarmouttype:1;
        uint32_t _unused1:13;
    };

    struct rtc_alarm_sub_second_t {
        uint32_t ss:15;
        uint32_t _unused0:9;
        uint32_t maskss:4;
        uint32_t _unused1:4;
    };

    struct rtc_t {
        rtc_time_t time;
        rtc_date_t date;
        rtc_control_t control;
        rtc_init_status_t init_status;
        rtc_prescaler_t prescaler;
        rtc_wakeup_timer_t wakeup_timer;
        rtc_calib_t calib;
        rtc_alarm_t alarma;
        rtc_alarm_t alarmb;
        rtc_write_protect_t write_protect;
        rtc_sub_second_t sub_second;
        rtc_shift_t shift;
        rtc_time_t ts_time;
        rtc_date_t ts_date;
        rtc_sub_second_t ts_sub_second;
        rtc_calib2_t calib2;
        rtc_tamper_alt_func_t tamper_alt_func;
        rtc_alarm_sub_second_t alarma_sub_second;
        rtc_alarm_sub_second_t alarmb_sub_second;
        uint32_t bkpr[32];
    };
}

#include "hal/rtc_d.hh"

#endif // RTC_HH
