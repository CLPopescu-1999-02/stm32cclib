#ifndef TIM_HH
#define TIM_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using tim_control1_cen = lib::regbit<0>;
    using tim_control1_udis = lib::regbit<1>;
    using tim_control1_urs = lib::regbit<2>;
    using tim_control1_opm = lib::regbit<3>;
    using tim_control1_dir = lib::regbit<4>;
    enum struct tim_control1_cms_t : lib::u8 {
        edge_aligned = 0b00,
        center_aligned1 = 0b01,
        center_aligned2 = 0b10,
        center_aligned3 = 0b11
    };
    using tim_control1_cms =
        lib::regbit<5,
            tim_control1_cms_t,
            2,
            tim_control1_cms_t::edge_aligned>;
    using tim_control1_arpe = lib::regbit<7>;
    enum struct tim_control1_ckd_t : lib::u8 {
        ck_int = 0b00,
        x2ck_int = 0b01,
        x4ck_int = 0b10
    };
    using tim_control1_ckd =
        lib::regbit<8,
            tim_control1_ckd_t,
            2,
            tim_control1_ckd_t::ck_int>;

    using tim_control2_ccds = lib::regbit<3>;
    enum struct tim_control2_mms_t : lib::u8 {
        reset = 0b000,
        enable = 0b001,
        update = 0b010,
        compare_pulse = 0b011,
        compare_oc1ref = 0b100,
        compare_oc2ref = 0b101,
        compare_oc3ref = 0b110,
        compare_oc4ref = 0b111
    };
    using tim_control2_mms =
        lib::regbit<4,
            tim_control2_mms_t,
            3,
            tim_control2_mms_t::reset>;
    using tim_control2_ti1s = lib::regbit<7>;

    enum struct tim_slave_mode_sms_t : lib::u8 {
        disabled = 0b000,
        encoder1 = 0b001,
        encoder2 = 0b010,
        encoder3 = 0b011,
        reset = 0b100,
        gated = 0b101,
        trigger = 0b110,
        ext_clock = 0b111
    };
    using tim_slave_mode_sms =
        lib::regbit<0,
            tim_slave_mode_sms_t,
            3,
            tim_slave_mode_sms_t::disabled>;
    enum struct tim_slave_mode_ts_t : lib::u8 {
        itr1 = 0b001,
        itr2 = 0b010,
        ti1f_ed = 0b100,
        ti1fp1 = 0b101,
        ti2fp2 = 0b110,
        etrf = 0b111
    };
    using tim_slave_mode_ts =
        lib::regbit<4,
        tim_slave_mode_ts_t,
        3,
        tim_slave_mode_ts_t::itr1>;
    using tim_slave_mode_msm = lib::regbit<7>;
    using tim_slave_mode_etf = lib::regbit<8, lib::u8, 4, 0>;
    using tim_slave_mode_etps = lib::regbit<12, lib::u8, 2, 0>;
    using tim_slave_mode_ece = lib::regbit<14>;
    using tim_slave_mode_etp = lib::regbit<15>;

    using tim_dma_interrupt_uie = lib::regbit<0>;
    using tim_dma_interrupt_cc1ie = lib::regbit<1>;
    using tim_dma_interrupt_cc2ie = lib::regbit<2>;
    using tim_dma_interrupt_cc3ie = lib::regbit<3>;
    using tim_dma_interrupt_cc4ie = lib::regbit<4>;
    using tim_dma_interrupt_tie = lib::regbit<6>;
    using tim_dma_interrupt_ude = lib::regbit<8>;
    using tim_dma_interrupt_cc1de = lib::regbit<9>;
    using tim_dma_interrupt_cc2de = lib::regbit<10>;
    using tim_dma_interrupt_cc3de = lib::regbit<11>;
    using tim_dma_interrupt_cc4de = lib::regbit<12>;
    using tim_dma_interrupt_tde = lib::regbit<14>;

    using tim_status_uif = lib::regbit<0>;
    using tim_status_cc1if = lib::regbit<1>;
    using tim_status_cc2if = lib::regbit<2>;
    using tim_status_cc3if = lib::regbit<3>;
    using tim_status_cc4if = lib::regbit<4>;
    using tim_status_tif = lib::regbit<6>;
    using tim_status_cc1of = lib::regbit<9>;
    using tim_status_cc2of = lib::regbit<10>;
    using tim_status_cc3of = lib::regbit<11>;
    using tim_status_cc4of = lib::regbit<12>;

    using tim_event_generation_ug = lib::regbit<0>;
    using tim_event_generation_cc1g = lib::regbit<1>;
    using tim_event_generation_cc2g = lib::regbit<2>;
    using tim_event_generation_cc3g = lib::regbit<3>;
    using tim_event_generation_cc4g = lib::regbit<4>;
    using tim_event_generation_tg = lib::regbit<6>;

    enum struct tim_capt_comp_mode_ccs_t : lib::u8 {
        output = 0b00,
        ic1t1 = 0b01,
        ic1t2 = 0b10,
        ic1trc = 0b11
    };
    using tim_capt_comp_mode_cc1s =
        lib::regbit<0,
            tim_capt_comp_mode_ccs_t,
            2,
            tim_capt_comp_mode_ccs_t::output>;
    using tim_capt_comp_mode_ic1psc = lib::regbit<2, lib::u8, 2, 0>;
    using tim_capt_comp_mode_ic1f = lib::regbit<4, lib::u8, 4, 0>;
    using tim_capt_comp_mode_cc2s =
        lib::regbit<8,
            tim_capt_comp_mode_ccs_t,
            2,
            tim_capt_comp_mode_ccs_t::output>;
    using tim_capt_comp_mode_ic2psc = lib::regbit<10, lib::u8, 2, 0>;
    using tim_capt_comp_mode_ic2f = lib::regbit<12, lib::u8, 4, 0>;

    using tim_capt_comp_mode_oc1fe = lib::regbit<2>;
    using tim_capt_comp_mode_oc1pe = lib::regbit<3>;
    enum struct tim_capt_comp_mode_ocm_t : lib::u8 {
        frozen = 0b000,
        active = 0b001,
        inactive = 0b010,
        toggle = 0b011,
        force_inactive = 0b100,
        force_active = 0b101,
        pwm1 = 0b110,
        pwm2 = 0b111
    };
    using tim_capt_comp_mode_oc1m =
        lib::regbit<4,
            tim_capt_comp_mode_ocm_t,
            3,
            tim_capt_comp_mode_ocm_t::frozen>;
    using tim_capt_comp_mode_oc1ce = lib::regbit<7>;
    using tim_capt_comp_mode_oc2fe = lib::regbit<10>;
    using tim_capt_comp_mode_oc2pe = lib::regbit<11>;
    using tim_capt_comp_mode_oc2m =
        lib::regbit<12,
            tim_capt_comp_mode_ocm_t,
            3,
            tim_capt_comp_mode_ocm_t::frozen>;
    using tim_capt_comp_mode_oc2ce = lib::regbit<15>;

    using tim_capt_comp_enable_cc1e = lib::regbit<0>;
    using tim_capt_comp_enable_cc1p = lib::regbit<1>;
    using tim_capt_comp_enable_cc1np = lib::regbit<3>;
    using tim_capt_comp_enable_cc2e = lib::regbit<4>;
    using tim_capt_comp_enable_cc2p = lib::regbit<5>;
    using tim_capt_comp_enable_cc2np = lib::regbit<7>;
    using tim_capt_comp_enable_cc3e = lib::regbit<8>;
    using tim_capt_comp_enable_cc3p = lib::regbit<9>;
    using tim_capt_comp_enable_cc3np = lib::regbit<11>;
    using tim_capt_comp_enable_cc4e = lib::regbit<12>;
    using tim_capt_comp_enable_cc4p = lib::regbit<13>;
    using tim_capt_comp_enable_cc4np = lib::regbit<15>;

    using tim_dma_control_dba = lib::regbit<0, lib::u8, 5, 0>;
    using tim_dma_control_dbl = lib::regbit<8, lib::u8, 5, 0>;

    struct tim_t {
        uint16_t control1;
        uint16_t _reserved0;
        uint16_t control2;
        uint16_t _reserved1;
        uint16_t slave_mode;
        uint16_t _reserved2;
        uint16_t dma_interrupt;
        uint16_t _reserved3;
        uint16_t status;
        uint16_t _reserved4;
        uint16_t event_generation;
        uint16_t _reserved5;
        uint16_t capt_comp_mode1;
        uint16_t _reserved6;
        uint16_t capt_comp_mode2;
        uint16_t _reserved7;
        uint16_t capt_comp_enable;
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
        uint16_t dma_control;
        uint16_t _reserved18;
        uint16_t dmar;
        uint16_t _reserved19;
        uint16_t option;
        uint16_t _reserved20;
    };

    struct tim32_t {
        uint16_t control1;
        uint16_t _reserved0;
        uint16_t control2;
        uint16_t _reserved1;
        uint16_t slave_mode;
        uint16_t _reserved2;
        uint16_t dma_interrupt;
        uint16_t _reserved3;
        uint16_t status;
        uint16_t _reserved4;
        uint16_t event_generation;
        uint16_t _reserved5;
        uint16_t capt_comp_mode1;
        uint16_t _reserved6;
        uint16_t capt_comp_mode2;
        uint16_t _reserved7;
        uint16_t capt_comp_enable;
        uint16_t _reserved8;
        uint32_t cnt;
        uint16_t psc;
        uint16_t _reserved10;
        uint32_t arr;
        uint32_t _reserved12;
        uint32_t ccr1;
        uint32_t ccr2;
        uint32_t ccr3;
        uint32_t ccr4;
        uint32_t _reserved17;
        uint16_t dma_control;
        uint16_t _reserved18;
        uint16_t dmar;
        uint16_t _reserved19;
        uint16_t option;
        uint16_t _reserved20;
    };

    template <lib::u32 addr, typename Timer>
    struct tim_d {
        static constexpr volatile Timer * const regs =
            reinterpret_cast<Timer *>(addr);
    };
}

#include "hal/tim_d.hh"

#endif // TIM_HH
