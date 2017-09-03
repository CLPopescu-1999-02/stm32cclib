#ifndef ADC_HH
#define ADC_HH

#include "lib/types.hh"

namespace hal {
    struct adc_status_t {
        lib::u32 awd:1;
        lib::u32 eoc:1;
        lib::u32 jeoc:1;
        lib::u32 jstrt:1;
        lib::u32 strt:1;
        lib::u32 ovr:1;
        lib::u32 adons:1;
        lib::u32 _unused0:1;
        lib::u32 rcnr:1;
        lib::u32 jcnr:1;
        lib::u32 _unused1:22;
    };

    struct adc_control1_t {
        lib::u32 awdch:5;
        lib::u32 eocie:1;
        lib::u32 awdie:1;
        lib::u32 jeocie:1;
        lib::u32 scan:1;
        lib::u32 awdsgl:1;
        lib::u32 jauto:1;
        lib::u32 discen:1;
        lib::u32 jdiscen:1;
        lib::u32 discnum:3;
        lib::u32 pdd:1;
        lib::u32 pdi:1;
        lib::u32 _unused0:4;
        lib::u32 jawden:1;
        lib::u32 awden:1;
        lib::u32 res:2;
        lib::u32 ovrie:1;
        lib::u32 _unused1:5;
    };

    struct adc_control2_t {
        lib::u32 adon:1;
        lib::u32 cont:1;
        lib::u32 adc_cfg:1;
        lib::u32 _unused0:1;
        lib::u32 dels:3;
        lib::u32 _unused1:1;
        lib::u32 dma:1;
        lib::u32 dds:1;
        lib::u32 eocs:1;
        lib::u32 align:1;
        lib::u32 _unused2:4;
        lib::u32 jextsel:4;
        lib::u32 jexten:2;
        lib::u32 jswstart:1;
        lib::u32 _unused3:1;
        lib::u32 extsel:4;
        lib::u32 exten:2;
        lib::u32 swstart:1;
        lib::u32 _unused4:1;
    };

    struct adc_inject_ch_data_off_t {
        lib::u32 joffset:12;
        lib::u32 _unused0:20;
    };

    struct adc_watchdog_higher_threshold_t {
        lib::u32 ht:12;
        lib::u32 _unused0:20;
    };

    struct adc_watchdog_lower_threshold_t {
        lib::u32 lt:12;
        lib::u32 _unused0:20;
    };

    struct inject_sequence_t {
        lib::u32 jsq1:5;
        lib::u32 jsq2:5;
        lib::u32 jsq3:5;
        lib::u32 jsq4:5;
        lib::u32 jl:2;
        lib::u32 _unused0:10;
    };

    struct adc_t {
        adc_status_t status;
        adc_control1_t control1;
        adc_control2_t control2;
        lib::u32 smpr[3];
        adc_inject_ch_data_off_t inject_ch_data_off1;
        adc_inject_ch_data_off_t inject_ch_data_off2;
        adc_inject_ch_data_off_t inject_ch_data_off3;
        adc_inject_ch_data_off_t inject_ch_data_off4;
        adc_watchdog_higher_threshold_t higher_threshold;
        adc_watchdog_lower_threshold_t lower_threshold;
        lib::u32 sqr[5];
        inject_sequence_t inject_sequence;
        lib::u16 jdr1;
        lib::u16 _unused0;
        lib::u16 jdr2;
        lib::u16 _unused1;
        lib::u16 jdr3;
        lib::u16 _unused2;
        lib::u16 jdr4;
        lib::u16 _unused3;
        lib::u16 dr;
        lib::u16 _unused4;
        lib::u32 smpr0;

        void set_sample_time(lib::u32 time, lib::u32 channel) volatile {
            if (channel < 30) {
                smpr[2 - channel / 10] |= time << (channel % 10 * 3);
            } else {
                smpr0 |= time << (channel % 10 * 3);
            }
        }

        template <typename ...Channels>
        void set_sample_time(lib::u32 time, lib::u32 channel, Channels ...channels) volatile {
            set_sample_time(time, channel);
            set_sample_time(time, channels...);
        }

        void reset_sample_time(lib::u32 channel) volatile {
            if (channel < 30) {
                smpr[2 - channel / 10] &= ~(7 << (channel % 10 * 3));
            } else {
                smpr0 &= ~(7 << (channel % 10 * 3));
            }
        }

        template <typename ...Channels>
        void reset_sample_time(lib::u32 channel, Channels ...channels) volatile {
            reset_sample_time(channel);
            reset_sample_time(channels...);
        }

        void set_regular_sequence(lib::u32 channel, lib::u32 seq) volatile {
            sqr[4 - seq / 6] |= channel << (seq % 6 * 5);
        }

        template <typename ...Seqs>
        void set_regular_sequence(lib::u32 channel, lib::u32 seq, Seqs ...seqs) volatile {
            set_regular_sequence(channel, seq);
            set_regular_sequence(channel, seqs...);
        }

        void reset_regular_sequence(lib::u32 seq) volatile {
            sqr[4 - seq / 6] &= 0b11111 << (seq % 6 * 5);
        }

        template <typename ...Seqs>
        void reset_regular_sequence(lib::u32 seq, Seqs ...seqs) volatile {
            reset_regular_sequence(seq);
            reset_regular_sequence(seqs...);
        }
    };

    struct adc_common_status_t {
        lib::u32 awd:1;
        lib::u32 eoc1:1;
        lib::u32 jeoc1:1;
        lib::u32 jstrt1:1;
        lib::u32 strt1:1;
        lib::u32 ovr1:1;
        lib::u32 adons1:1;
        lib::u32 _unused0:25;
    };

    struct adc_common_control_t {
        lib::u32 _unused0:16;
        lib::u32 adcpre:2;
        lib::u32 _unused1:5;
        lib::u32 tsvrefe:1;
        lib::u32 _unused2:8;
    };

    struct adc_common_t {
        adc_common_status_t status;
        adc_common_control_t control;
    };
}

#include "hal/adc_d.hh"

#endif // ADC_HH
