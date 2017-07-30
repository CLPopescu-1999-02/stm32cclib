#ifndef TIM_HH
#define TIM_HH

#include <stdint.h>

namespace hal {
    struct tim_control1_t {
        uint16_t cen:1;
        uint16_t udis:1;
        uint16_t urs:1;
        uint16_t opm:1;
        uint16_t dir:1;
        uint16_t cms:2;
        uint16_t arpe:1;
        uint16_t ckd:2;
        uint16_t _unused0:6;
    };

    struct tim_control2_t {
        uint16_t _unused0:3;
        uint16_t ccds:1;
        uint16_t mms:3;
        uint16_t ti1s:1;
        uint16_t _unused1:8;
    };

    struct tim_slave_mode_control_t {
        uint16_t sms:3;
        uint16_t occs:1;
        uint16_t ts:3;
        uint16_t msm:1;
        uint16_t etf:4;
        uint16_t etps:2;
        uint16_t ece:1;
        uint16_t etp:1;
    };

    struct tim_dma_interrupt_enable_t {
        uint16_t uie:1;
        uint16_t cc1ie:1;
        uint16_t cc2ie:1;
        uint16_t cc3ie:1;
        uint16_t cc4ie:1;
        uint16_t _unused0:1;
        uint16_t tie:1;
        uint16_t _unused1:1;
        uint16_t ude:1;
        uint16_t cc1de:1;
        uint16_t cc2de:1;
        uint16_t cc3de:1;
        uint16_t cc4de:1;
        uint16_t _unused2:1;
        uint16_t tde:1;
        uint16_t _unused3:1;
    };

    struct tim_status_t {
        uint16_t uif:1;
        uint16_t cc1if:1;
        uint16_t cc2if:1;
        uint16_t cc3if:1;
        uint16_t cc4if:1;
        uint16_t _unused0:1;
        uint16_t tif:1;
        uint16_t _unused1:2;
        uint16_t cc1of:1;
        uint16_t cc2of:1;
        uint16_t cc3of:1;
        uint16_t cc4of:1;
        uint16_t _unused2:3;
    };

    struct tim_event_generation_t {
        uint16_t ug:1;
        uint16_t cc1g:1;
        uint16_t cc2g:1;
        uint16_t cc3g:1;
        uint16_t cc4g:1;
        uint16_t _unused0:1;
        uint16_t tg:1;
        uint16_t _unused1:9;
    };

    union tim_capt_comp_mode_t {
        struct {
            uint16_t cc1s:2;
            uint16_t ic1psc:2;
            uint16_t ic1f:4;
            uint16_t cc2s:2;
            uint16_t ic2psc:2;
            uint16_t ic2f:4;
        };
        struct {
            uint16_t _same0:2;
            uint16_t oc1fe:1;
            uint16_t oc1pe:1;
            uint16_t oc1m:3;
            uint16_t oc1ce:1;
            uint16_t _same2:2;
            uint16_t oc2fe:1;
            uint16_t oc2pe:1;
            uint16_t oc2m:3;
            uint16_t oc2ce:1;
        };
    };

    struct tim_capt_comp_enable_t {
        uint16_t cc1e:1;
        uint16_t cc1p:1;
        uint16_t _unused0:1;
        uint16_t cc1np:1;
        uint16_t cc2e:1;
        uint16_t cc2p:1;
        uint16_t _unused1:1;
        uint16_t cc2np:1;
        uint16_t cc3e:1;
        uint16_t cc3p:1;
        uint16_t _unused2:1;
        uint16_t cc3np:1;
        uint16_t cc4e:1;
        uint16_t cc4p:1;
        uint16_t _unused3:1;
        uint16_t cc4np:1;
    };

    struct tim_dma_control_t {
        uint16_t dba:5;
        uint16_t _unused0:3;
        uint16_t dbl:5;
        uint16_t _unused1:3;
    };

    struct tim_t {
        tim_control1_t control1;
        uint16_t _reserved0;
        tim_control2_t control2;
        uint16_t _reserved1;
        tim_slave_mode_control_t slave_mode_control;
        uint16_t _reserved2;
        tim_dma_interrupt_enable_t dma_interrupt_enable;
        uint16_t _reserved3;
        tim_status_t status;
        uint16_t _reserved4;
        tim_event_generation_t event_generation;
        uint16_t _reserved5;
        tim_capt_comp_mode_t capt_comp_mode1;
        uint16_t _reserved6;
        tim_capt_comp_mode_t capt_comp_mode2;
        uint16_t _reserved7;
        tim_capt_comp_enable_t capt_comp_enable;
        uint16_t _reserved8;
        uint16_t cnt;
        uint16_t _reserved9;
        uint16_t psc;
        uint16_t _reserved10;
        uint16_t arr;
        uint16_t _reserved11;
        uint32_t _reserved12;
        uint16_t ccr1;
        uint16_t _reserved13;
        uint16_t ccr2;
        uint16_t _reserved14;
        uint16_t ccr3;
        uint16_t _reserved15;
        uint16_t ccr4;
        uint16_t _reserved16;
        uint32_t _reserved17;
        tim_dma_control_t dma_control;
        uint16_t _reserved18;
        uint16_t dmar;
        uint16_t _reserved19;
    };

    volatile tim_t * const tim4 = reinterpret_cast<tim_t *>(0x40000800);
}

#endif // TIM_HH
