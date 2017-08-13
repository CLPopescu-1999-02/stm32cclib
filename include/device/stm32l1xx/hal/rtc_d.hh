#ifndef RTC_D_HH
#define RTC_D_HH

namespace hal {
    volatile rtc_t * const rtc = reinterpret_cast<rtc_t *>(0x40002800);
}

#endif // RTC_D_HH
