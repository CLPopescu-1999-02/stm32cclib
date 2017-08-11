#ifndef ADC_HH
#define ADC_HH

#include <stdint.h>

namespace hal {
    struct adc_status_t {
        uint32_t awd:1;
        uint32_t eoc:1;
        uint32_t jeoc:1;
        uint32_t jstrt:1;
        uint32_t strt:1;
        uint32_t ovr:1;
        uint32_t adons:1;
        uint32_t _unused0:1;
        uint32_t rcnr:1;
        uint32_t jcnr:1;
        uint32_t _unused1:22;
    };

    struct adc_control1_t {
        uint32_t awdch:5;
        uint32_t eocie:1;
        uint32_t awdie:1;
        uint32_t jeocie:1;
        uint32_t scan:1;
        uint32_t awdsgl:1;
        uint32_t jauto:1;
        uint32_t discen:1;
        uint32_t jdiscen:1;
        uint32_t discnum:3;
        uint32_t pdd:1;
        uint32_t pdi:1;
        uint32_t _unused0:4;
        uint32_t jawden:1;
        uint32_t awden:1;
        uint32_t res:2;
        uint32_t ovrie:1;
        uint32_t _unused1:5;
    };

    struct adc_control2_t {
        uint32_t adon:1;
        uint32_t cont:1;
        uint32_t adc_cfg:1;
        uint32_t _unused0:1;
        uint32_t dels:3;
        uint32_t _unused1:1;
        uint32_t dma:1;
        uint32_t dds:1;
        uint32_t eocs:1;
        uint32_t align:1;
        uint32_t _unused2:4;
        uint32_t jextsel:4;
        uint32_t jexten:2;
        uint32_t jswstart:1;
        uint32_t _unused3:1;
        uint32_t extsel:4;
        uint32_t exten:2;
        uint32_t swstart:1;
        uint32_t _unused4:1;
    };

    struct adc_inject_ch_data_off_t {
        uint32_t joffset:12;
        uint32_t _unused0:20;
    };

    struct adc_watchdog_higher_threshold_t {
        uint32_t ht:12;
        uint32_t _unused0:20;
    };

    struct adc_watchdog_lower_threshold_t {
        uint32_t lt:12;
        uint32_t _unused0:20;
    };

    struct inject_sequence_t {
        uint32_t jsq1:5;
        uint32_t jsq2:5;
        uint32_t jsq3:5;
        uint32_t jsq4:5;
        uint32_t jl:2;
        uint32_t _unused0:10;
    };

    struct adc_t {
        adc_status_t status;
        adc_control1_t control1;
        adc_control2_t control2;
        uint32_t smpr[3];
        adc_inject_ch_data_off_t inject_ch_data_off1;
        adc_inject_ch_data_off_t inject_ch_data_off2;
        adc_inject_ch_data_off_t inject_ch_data_off3;
        adc_inject_ch_data_off_t inject_ch_data_off4;
        adc_watchdog_higher_threshold_t higher_threshold;
        adc_watchdog_lower_threshold_t lower_threshold;
        uint32_t sqr[5];
        inject_sequence_t inject_sequence;
        uint16_t jdr1;
        uint16_t _unused0;
        uint16_t jdr2;
        uint16_t _unused1;
        uint16_t jdr3;
        uint16_t _unused2;
        uint16_t jdr4;
        uint16_t _unused3;
        uint16_t dr;
        uint16_t _unused4;
        uint32_t smpr0;

        void set_sample_time(uint32_t time, uint32_t channel) volatile {
            if (channel < 30) {
                smpr[2 - channel / 10] |= time << (channel % 10 * 3);
            } else {
                smpr0 |= time << (channel % 10 * 3);
            }
        }

        template <typename ...Channels>
        void set_sample_time(uint32_t time, uint32_t channel, Channels ...channels) volatile {
            set_sample_time(time, channel);
            set_sample_time(time, channels...);
        }

        void reset_sample_time(uint32_t channel) volatile {
            if (channel < 30) {
                smpr[2 - channel / 10] &= ~(7 << (channel % 10 * 3));
            } else {
                smpr0 &= ~(7 << (channel % 10 * 3));
            }
        }

        template <typename ...Channels>
        void reset_sample_time(uint32_t channel, Channels ...channels) volatile {
            reset_sample_time(channel);
            reset_sample_time(channels...);
        }

        void set_regular_sequence(uint32_t channel, uint32_t seq) volatile {
            sqr[4 - seq / 6] |= channel << (seq % 6 * 5);
        }

        template <typename ...Seqs>
        void set_regular_sequence(uint32_t channel, uint32_t seq, Seqs ...seqs) volatile {
            set_regular_sequence(channel, seq);
            set_regular_sequence(channel, seqs...);
        }

        void reset_regular_sequence(uint32_t seq) volatile {
            sqr[4 - seq / 6] &= 0b11111 << (seq % 6 * 5);
        }

        template <typename ...Seqs>
        void reset_regular_sequence(uint32_t seq, Seqs ...seqs) volatile {
            reset_regular_sequence(seq);
            reset_regular_sequence(seqs...);
        }
    };

    struct adc_common_status_t {
        uint32_t awd:1;
        uint32_t eoc1:1;
        uint32_t jeoc1:1;
        uint32_t jstrt1:1;
        uint32_t strt1:1;
        uint32_t ovr1:1;
        uint32_t adons1:1;
        uint32_t _unused0:25;
    };

    struct adc_common_control_t {
        uint32_t _unused0:16;
        uint32_t adcpre:2;
        uint32_t _unused1:5;
        uint32_t tsvrefe:1;
        uint32_t _unused2:8;
    };

    struct adc_common_t {
        adc_common_status_t status;
        adc_common_control_t control;
    };

    volatile adc_t * const adc1 = reinterpret_cast<adc_t *>(0x40012400);

    volatile adc_common_t * const adc1_common = reinterpret_cast<adc_common_t *>(0x40012400 + 0x300);
}

#endif // ADC_HH
