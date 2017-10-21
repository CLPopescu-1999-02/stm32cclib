#ifndef ADC_T_HH
#define ADC_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using adc_status_adrdy = lib::regbit<0>;
    using adc_status_eosmp = lib::regbit<1>;
    using adc_status_eoc = lib::regbit<2>;
    using adc_status_eos = lib::regbit<3>;
    using adc_status_ovr = lib::regbit<4>;
    using adc_status_jeoc = lib::regbit<5>;
    using adc_status_jeos = lib::regbit<6>;
    using adc_status_awd1 = lib::regbit<7>;
    using adc_status_awd2 = lib::regbit<8>;
    using adc_status_awd3 = lib::regbit<9>;
    using adc_status_jqovf = lib::regbit<10>;

    using adc_control1_aden = lib::regbit<0>;
    using adc_control1_addis = lib::regbit<1>;
    using adc_control1_adstart = lib::regbit<2>;
    using adc_control1_jadstart = lib::regbit<3>;
    using adc_control1_adstp = lib::regbit<4>;
    using adc_control1_jadstp = lib::regbit<5>;
    enum struct adc_control1_advregen_t : lib::u8 {
        intermediate = 0b00,
        enable = 0b01,
        disable = 0b10
    };
    using adc_control1_advregen =
        lib::regbit<28,
            adc_control1_advregen_t,
            2,
            adc_control1_advregen_t::disable>;
    using adc_control1_adcaldif = lib::regbit<30>;
    using adc_control1_adcal = lib::regbit<31>;

    using adc_control2_dma = lib::regbit<0>;
    using adc_control2_dmacfg = lib::regbit<1>;
    enum struct adc_control2_res_t : lib::u8 {
        r16bit = 0b00,
        r10bit = 0b01,
        r8bit = 0b10,
        r6bit = 0b11
    };
    using adc_control2_res =
        lib::regbit<3,
            adc_control1_res_t,
            2,
            adc_control1_res_t::r16bit>;
    using adc_control2_align = lib::regbit<5>;
    using adc_control2_extsel = lib::regbit8<6, 4>;
    enum struct adc_control2_exten_t : lib::u8 {
        disable = 0b00,
        rising = 0b01,
        faling = 0b10,
        both = 0b11
    };
    using adc_control2_exten =
        lib::regbit<10,
            adc_control2_exten_t,
            2,
            adc_control2_exten_t::disable>;
    using adc_control2_ovrmod = lib::regbit<12>;
    using adc_control2_cont = lib::regbit<13>;
    using adc_control2_autdly = lib::regbit<14>;
    using adc_control2_discen = lib::regbit<16>;
    using adc_control2_discnum = lib::regbit8<17, 3>;
    using adc_control2_jdiscen = lib::regbit<20>;
    using adc_control2_jqm = lib::regbit<21>;
    using adc_control2_awd1sgl = lib::regbit<22>;
    using adc_control2_awd1en = lib::regbit<23>;
    using adc_control2_jawd1en = lib::regbit<24>;
    using adc_control2_jauto = lib::regbit<25>;
    using adc_control2_awd1ch = lib::regbit8<26, 5>;

    enum struct adc_sample_time_t : lib::u8 {
        by1_5cycles = 0b000,
        by2_5cycles = 0b001,
        by4_5cycles = 0b010,
        by7_5cycles = 0b011,
        by19_5cycles = 0b100,
        by61_5cycles = 0b101,
        by181_5cycles = 0b110,
        by601_5cycles = 0b111
    };
    using adc_sample_time1_smp1 =
        lib::regbit<3,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time1_smp2 =
        lib::regbit<6,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time1_smp3 =
        lib::regbit<9,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time1_smp4 =
        lib::regbit<12,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time1_smp5 =
        lib::regbit<15,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time1_smp6 =
        lib::regbit<18,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time1_smp7 =
        lib::regbit<21,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time1_smp8 =
        lib::regbit<24,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time1_smp9 =
        lib::regbit<27,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;

    using adc_sample_time2_smp10 =
        lib::regbit<0,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time2_smp11 =
        lib::regbit<3,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time2_smp12 =
        lib::regbit<6,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time2_smp13 =
        lib::regbit<9,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time2_smp14 =
        lib::regbit<12,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time2_smp15 =
        lib::regbit<15,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time2_smp16 =
        lib::regbit<18,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time2_smp17 =
        lib::regbit<21,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;
    using adc_sample_time2_smp18 =
        lib::regbit<24,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by1_5cycles>;

    using adc_threshold1_lower = lib::regbit16<0, 12>;
    using adc_threshold1_higher = lib::regbit16<16, 12>;

    using adc_threshold2_lower = lib::regbit16<0, 8>;
    using adc_threshold2_higher = lib::regbit16<16, 8>;

    using adc_threshold3_lower = lib::regbit16<0, 8>;
    using adc_threshold3_higher = lib::regbit16<16, 8>;

    using adc_regular_sequence1_l = lib::regbit8<0, 4>;
    using adc_regular_sequence1_sq1 = lib::regbit8<6, 5>;
    using adc_regular_sequence1_sq2 = lib::regbit8<12, 5>;
    using adc_regular_sequence1_sq3 = lib::regbit8<18, 5>;
    using adc_regular_sequence1_sq4 = lib::regbit8<24, 5>;

    using adc_regular_sequence2_sq5 = lib::regbit8<0, 5>;
    using adc_regular_sequence2_sq6 = lib::regbit8<6, 5>;
    using adc_regular_sequence2_sq7 = lib::regbit8<12, 5>;
    using adc_regular_sequence2_sq8 = lib::regbit8<18, 5>;
    using adc_regular_sequence2_sq9 = lib::regbit8<24, 5>;

    using adc_regular_sequence3_sq10 = lib::regbit8<0, 5>;
    using adc_regular_sequence3_sq11 = lib::regbit8<6, 5>;
    using adc_regular_sequence3_sq12 = lib::regbit8<12, 5>;
    using adc_regular_sequence3_sq13 = lib::regbit8<18, 5>;
    using adc_regular_sequence3_sq14 = lib::regbit8<24, 5>;

    using adc_regular_sequence4_sq15 = lib::regbit8<0, 5>;
    using adc_regular_sequence4_sq16 = lib::regbit8<6, 5>;

    using inject_sequence_jl = lib::regbit8<0, 2>;
    using inject_sequence_jextsel = lib::regbit8<2, 4>;
    enum struct inject_sequence_jexten_t : lib::u8 {
        disable = 0b00,
        rising = 0b01,
        faling = 0b10,
        both = 0b11
    };
    using inject_sequence_jexten =
        lib::regbit<6,
            inject_sequence_jexten_t,
            2,
            inject_sequence_jexten_t::disable>;
    using inject_sequence_jsq1 = lib::regbit8<8, 5>;
    using inject_sequence_jsq2 = lib::regbit8<14, 5>;
    using inject_sequence_jsq3 = lib::regbit8<20, 5>;
    using inject_sequence_jsq3 = lib::regbit8<26, 5>;

    using adc_offset1_offset = lib::regbit16<0, 12>;
    using adc_offset1_ch = lib::regbit8<26, 5>;
    using adc_offset1_en = lib::regbit<31>;

    using adc_offset2_offset = lib::regbit16<0, 12>;
    using adc_offset2_ch = lib::regbit8<26, 5>;
    using adc_offset2_en = lib::regbit<31>;

    using adc_offset3_offset = lib::regbit16<0, 12>;
    using adc_offset3_ch = lib::regbit8<26, 5>;
    using adc_offset3_en = lib::regbit<31>;

    using adc_offset4_offset = lib::regbit16<0, 12>;
    using adc_offset4_ch = lib::regbit8<26, 5>;
    using adc_offset4_en = lib::regbit<31>;

    using adc_analog_watchdog2_ch = lib::regbit32<1, 18>;

    using adc_analog_watchdog3_ch = lib::regbit32<1, 18>;

    using adc_diff_mode_sel = lib::regbit16<1, 15>;
    using adc_diff_mode_sel_r = lib::regbit8<16, 3>;

    using adc_calib_factors_s = lib::regbit8<0, 7>;
    using adc_calib_factors_d = lib::regbit8<16, 7>;

    template <lib::u32 addr>
    struct adc_d {
        struct adc_t {
            lib::u32 status;
            lib::u32 interrupt;
            lib::u32 control1;
            lib::u32 control2;
            lib::u32 _unused1;
            lib::u32 sample_time1;
            lib::u32 sample_time2;
            lib::u32 _unused2;
            lib::u32 adc_threshold1;
            lib::u32 adc_threshold2;
            lib::u32 adc_threshold3;
            lib::u32 _unused3;
            lib::u32 regular_sequence1;
            lib::u32 regular_sequence2;
            lib::u32 regular_sequence3;
            lib::u32 regular_sequence4;
            lib::u16 dr;
            lib::u16 _unused4;
            lib::u32 _unused5;
            lib::u32 _unused6;
            lib::u32 inject_sequence;
            lib::u32 _unused7;
            lib::u32 _unused8;
            lib::u32 _unused9;
            lib::u32 _unused10;
            lib::u32 offset1;
            lib::u32 offset2;
            lib::u32 offset3;
            lib::u32 offset4;
            lib::u32 _unused11;
            lib::u32 _unused12;
            lib::u32 _unused13;
            lib::u32 _unused14;
            lib::u16 jdr1;
            lib::u16 _unused15;
            lib::u16 jdr2;
            lib::u16 _unused16;
            lib::u16 jdr3;
            lib::u16 _unused17;
            lib::u16 jdr4;
            lib::u16 _unused18;
            lib::u32 _unused19[20];
            lib::u32 adc_analog_watchdog2;
            lib::u32 adc_analog_watchdog3;
            lib::u32 _unused20;
            lib::u32 _unused21;
            lib::u32 diff_mode;
            lib::u32 calib_factors;
        };

        static constexpr volatile adc_t * const regs =
            reinterpret_cast<adc_t *>(addr);
    };

    using adc_common_status_adrdy_mst = lib::regbit<0>;
    using adc_common_status_eosmp_mst = lib::regbit<1>;
    using adc_common_status_eoc_mst = lib::regbit<2>;
    using adc_common_status_eos_mst = lib::regbit<3>;
    using adc_common_status_ovr_mst = lib::regbit<4>;
    using adc_common_status_jeoc_mst = lib::regbit<5>;
    using adc_common_status_jeos_mst = lib::regbit<6>;
    using adc_common_status_awd1_mst = lib::regbit<7>;
    using adc_common_status_awd2_mst = lib::regbit<8>;
    using adc_common_status_awd3_mst = lib::regbit<9>;
    using adc_common_status_jqovf_mst = lib::regbit<10>;
    using adc_common_status_adrdy_slv = lib::regbit<16>;
    using adc_common_status_eosmp_slv = lib::regbit<17>;
    using adc_common_status_eoc_slv = lib::regbit<18>;
    using adc_common_status_eos_slv = lib::regbit<19>;
    using adc_common_status_ovr_slv = lib::regbit<20>;
    using adc_common_status_jeoc_slv = lib::regbit<21>;
    using adc_common_status_jeos_slv = lib::regbit<22>;
    using adc_common_status_awd1_slv = lib::regbit<23>;
    using adc_common_status_awd2_slv = lib::regbit<24>;
    using adc_common_status_awd3_slv = lib::regbit<25>;
    using adc_common_status_jqovf_slv = lib::regbit<26>;


    enum struct adc_common_control_dual_t : lib::u8 {
        independ = 0b00000,
        combined_regular_injected = 0b00001,
        combined_regular_alternate_trigger = 0b00010,
        injected = 0b00101,
        regular = 0b00110,
        interleaved = 0b00111,
        alternate_trigger = 0b01001,
    };
    using adc_common_control_dual =
        lib::regbit<0,
            adc_common_control_dual_t,
            5,
            adc_common_control_dual_t::independ>;
    using adc_common_control_delay = lib::regbit8<8, 4>;
    using adc_common_control_dma_cfg = lib::regbit<13>;
    enum struct adc_common_control_mdma_t : lib::u8 {
        disable = 0b00,
        mode2 = 0b10,
        mode3 = 0b11
    };
    using adc_common_control_mdma =
        lib::regbit<14,
            adc_common_control_mdma_t,
            2,
            adc_common_control_mdma_t::disable>;
    enum struct adc_common_control_ckmode_t : lib::u8 {
        async = 0b00,
        sync = 0b01,
        by2 = 0b10,
        by4 = 0b11
    };
    using adc_common_control_ckmode =
        lib::regbit<16,
            adc_common_control_ckmode_t,
            2,
            adc_common_control_ckmode_t::async>;
    using adc_common_control_vrefen = lib::regbit<22>;
    using adc_common_control_tsen = lib::regbit<23>;
    using adc_common_control_vbaten = lib::regbit<24>;

    template <lib::u32 addr>
    struct adc_common_d {
        struct adc_common_t {
            lib::u32 status;
            lib::u32 control;
            lib::u16 data_mst;
            lib::u16 data_slv;
        };

        static constexpr volatile adc_common_t & regs() {
            return *reinterpret_cast<adc_common_t *>(addr);
        }
    };
}

#endif // ADC_T_HH
