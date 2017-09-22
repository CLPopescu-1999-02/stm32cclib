#ifndef ADC_T_HH
#define ADC_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using adc_status_awd = lib::regbit<0>;
    using adc_status_eoc = lib::regbit<1>;
    using adc_status_jeoc = lib::regbit<2>;
    using adc_status_jstrt = lib::regbit<3>;
    using adc_status_strt = lib::regbit<4>;
    using adc_status_ovr = lib::regbit<5>;

    using adc_control1_awdch = lib::regbit8<0, 5>;
    using adc_control1_eocie = lib::regbit<5>;
    using adc_control1_awdie = lib::regbit<6>;
    using adc_control1_jeocie = lib::regbit<7>;
    using adc_control1_scan = lib::regbit<8>;
    using adc_control1_awdsgl = lib::regbit<9>;
    using adc_control1_jauto = lib::regbit<10>;
    using adc_control1_discen = lib::regbit<11>;
    using adc_control1_jdiscen = lib::regbit<12>;
    using adc_control1_discnum = lib::regbit8<13, 3>;
    using adc_control1_jawden = lib::regbit<22>;
    using adc_control1_awden = lib::regbit<23>;
    enum struct adc_control1_res_t : lib::u8 {
        r16bit = 0b00,
        r10bit = 0b01,
        r8bit = 0b10,
        r6bit = 0b11
    };
    using adc_control1_res =
        lib::regbit<24,
            adc_control1_res_t,
            2,
            adc_control1_res_t::r16bit>;
    using adc_control1_ovrie = lib::regbit<26>;

    using adc_control2_adon = lib::regbit<0>;
    using adc_control2_cont = lib::regbit<1>;
    using adc_control2_dma = lib::regbit<8>;
    using adc_control2_dds = lib::regbit<9>;
    using adc_control2_eocs = lib::regbit<10>;
    using adc_control2_align = lib::regbit<11>;
    enum struct adc_control2_jextsel_t : lib::u8 {
        tim1_cc4 = 0,
        tim1_trgo,
        tim2_cc1,
        tim2_trgo,
        tim3_cc4,
        tim4_cc1,
        tim4_cc2,
        tim4_cc3,
        tim4_trgo,
        tim5_cc4,
        tim5_trgo,
        tim8_cc2,
        tim8_cc3,
        tim8_cc4,
        exti15
    };
    using adc_control2_jextsel =
        lib::regbit<16,
            adc_control2_jextsel_t,
            4,
            adc_control2_jextsel_t::tim9_cc1>;
    enum struct adc_control2_exten_t : lib::u8 {
        disable = 0b00,
        rising = 0b01,
        faling = 0b10,
        both = 0b11
    };
    using adc_control2_jexten =
        lib::regbit<20,
            adc_control2_exten_t,
            2,
            adc_control2_exten_t::disable>;
    using adc_control2_jswstart = lib::regbit<22>;
    enum struct adc_control2_extsel_t : lib::u8 {
        tim1_cc1 = 0,
        tim1_cc2,
        tim1_cc3,
        tim2_cc2,
        tim2_cc3,
        tim2_cc4,
        tim2_trgo,
        tim3_cc1,
        tim3_trgo,
        tim4_cc4,
        tim5_cc1,
        tim5_cc2,
        tim5_cc3,
        tim8_cc1,
        tim8_trgo,
        exti11
    };
    using adc_control2_extsel =
        lib::regbit<24,
            adc_control2_extsel_t,
            4,
            adc_control2_extsel_t::tim9_cc2>;
    using adc_control2_exten =
        lib::regbit<28,
            adc_control2_exten_t,
            2,
            adc_control2_exten_t::disable>;
    using adc_control2_swstart = lib::regbit<30>;

    enum struct adc_sample_time_t : lib::u8 {
        by3cycles = 0b000,
        by15cycles = 0b001,
        by18cycles = 0b010,
        by28cycles = 0b011,
        by56cycles = 0b100,
        by112cycles = 0b101,
        by144cycles = 0b110,
        by480cycles = 0b111
    };
    using adc_sample_time2_smp0 =
        lib::regbit<0,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time2_smp1 =
        lib::regbit<3,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time2_smp2 =
        lib::regbit<6,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time2_smp3 =
        lib::regbit<9,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time2_smp4 =
        lib::regbit<12,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time2_smp5 =
        lib::regbit<15,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time2_smp6 =
        lib::regbit<18,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time2_smp7 =
        lib::regbit<21,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time2_smp8 =
        lib::regbit<24,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time2_smp9 =
        lib::regbit<27,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;

    using adc_sample_time1_smp10 =
        lib::regbit<0,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time1_smp11 =
        lib::regbit<3,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time1_smp12 =
        lib::regbit<6,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time1_smp13 =
        lib::regbit<9,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time1_smp14 =
        lib::regbit<12,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time1_smp15 =
        lib::regbit<15,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time1_smp16 =
        lib::regbit<18,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time1_smp17 =
        lib::regbit<21,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;
    using adc_sample_time1_smp18 =
        lib::regbit<24,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by3cycles>;

    using adc_inject_ch_data_off = lib::regbit16<0, 12>;

    using adc_higher_threshold = lib::regbit16<0, 12>;

    using adc_lower_threshold = lib::regbit16<0, 12>;

    using adc_regular_sequence3_sq1 = lib::regbit8<0, 5>;
    using adc_regular_sequence3_sq2 = lib::regbit8<5, 5>;
    using adc_regular_sequence3_sq3 = lib::regbit8<10,5>;
    using adc_regular_sequence3_sq4 = lib::regbit8<15, 5>;
    using adc_regular_sequence3_sq5 = lib::regbit8<20, 5>;
    using adc_regular_sequence3_sq6 = lib::regbit8<25, 5>;

    using adc_regular_sequence2_sq7 = lib::regbit8<0, 5>;
    using adc_regular_sequence2_sq8 = lib::regbit8<5, 5>;
    using adc_regular_sequence2_sq9 = lib::regbit8<10,5>;
    using adc_regular_sequence2_sq10 = lib::regbit8<15, 5>;
    using adc_regular_sequence2_sq11 = lib::regbit8<20, 5>;
    using adc_regular_sequence2_sq12 = lib::regbit8<25, 5>;

    using adc_regular_sequence1_sq13 = lib::regbit8<0, 5>;
    using adc_regular_sequence1_sq14 = lib::regbit8<5, 5>;
    using adc_regular_sequence1_sq15 = lib::regbit8<10,5>;
    using adc_regular_sequence1_sq16 = lib::regbit8<15, 5>;
    using adc_regular_sequence1_l = lib::regbit8<20, 5>;

    using inject_sequence_jsq1 = lib::regbit8<0, 5>;
    using inject_sequence_jsq2 = lib::regbit8<5, 5>;
    using inject_sequence_jsq3 = lib::regbit8<10,5>;
    using inject_sequence_jsq4 = lib::regbit8<15, 5>;
    using inject_sequence_jl = lib::regbit8<20, 2>;

    template <lib::u32 addr>
    struct adc_d {
        struct adc_t {
            lib::u32 status;
            lib::u32 control1;
            lib::u32 control2;
            lib::u32 sample_time1;
            lib::u32 sample_time2;
            lib::u32 inject_ch_data_off1;
            lib::u32 inject_ch_data_off2;
            lib::u32 inject_ch_data_off3;
            lib::u32 inject_ch_data_off4;
            lib::u32 higher_threshold;
            lib::u32 lower_threshold;
            lib::u32 regular_sequence1;
            lib::u32 regular_sequence2;
            lib::u32 regular_sequence3;
            lib::u32 inject_sequence;
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
        };

        static constexpr volatile adc_t * const regs =
            reinterpret_cast<adc_t *>(addr);
    };

    using adc_common_status_awd1 = lib::regbit<0>;
    using adc_common_status_eoc1 = lib::regbit<1>;
    using adc_common_status_jeoc1 = lib::regbit<2>;
    using adc_common_status_jstrt1 = lib::regbit<3>;
    using adc_common_status_strt1 = lib::regbit<4>;
    using adc_common_status_ovr1 = lib::regbit<5>;
    using adc_common_status_awd2 = lib::regbit<8>;
    using adc_common_status_eoc2 = lib::regbit<9>;
    using adc_common_status_jeoc2 = lib::regbit<10>;
    using adc_common_status_jstrt2 = lib::regbit<11>;
    using adc_common_status_strt2 = lib::regbit<12>;
    using adc_common_status_ovr2 = lib::regbit<13>;
    using adc_common_status_awd3 = lib::regbit<16>;
    using adc_common_status_eoc3 = lib::regbit<17>;
    using adc_common_status_jeoc3 = lib::regbit<18>;
    using adc_common_status_jstrt3 = lib::regbit<19>;
    using adc_common_status_strt3 = lib::regbit<20>;
    using adc_common_status_ovr3 = lib::regbit<21>;

    enum struct adc_common_control_multi_t : lib::u8 {
        independ = 0b00000,
        dual_combined_regular_injected = 0b00001,
        dual_combined_regular_alternate_trigger = 0b00010,
        dual_injected = 0b00101,
        dual_regular = 0b00110,
        dual_interleaved = 0b00111,
        dual_alternate_trigger = 0b01001,
        triple_combined_regular_injected = 0b10001,
        triple_combined_regular_alternate_trigger = 0b10010,
        triple_injected = 0b10101,
        triple_regular = 0b10110,
        triple_interleaved = 0b10111,
        triple_alternate_trigger = 0b11001
    };
    using adc_common_control_multi =
        lib::regbit<0,
            adc_common_control_multi_t,
            5,
            adc_common_control_multi_t::independ>;
    enum struct adc_common_control_delay_t : lib::u8 {
        mul5tadcclk = 0b0000,
        mul6tadcclk,
        mul7tadcclk,
        mul8tadcclk,
        mul9tadcclk,
        mul10tadcclk,
        mul11tadcclk,
        mul12tadcclk,
        mul13tadcclk,
        mul14tadcclk,
        mul15tadcclk,
        mul16tadcclk,
        mul17tadcclk,
        mul18tadcclk,
        mul19tadcclk,
        mul20tadcclk,
    };
    using adc_common_control_delay =
        lib::regbit<8,
            adc_common_control_delay_t,
            4,
            adc_common_control_delay_t::mul5tadcclk>;
    using adc_common_control_dds = lib::regbit<13>;
    enum struct adc_common_control_dma_t : lib::u8 {
        disable = 0b00,
        mode1 = 0b01,
        mode2 = 0b10,
        mode3 = 0b11
    };
    using adc_common_control_dma =
        lib::regbit<14,
            adc_common_control_dma_t,
            2,
            adc_common_control_dma_t::disable>;
    enum struct adc_common_control_adcpre_t : lib::u8 {
        by2 = 0b00,
        by4 = 0b01,
        by6 = 0b10,
        by8 = 0b11
    };
    using adc_common_control_adcpre =
        lib::regbit<16,
            adc_common_control_adcpre_t,
            2,
            adc_common_control_adcpre_t::by2>;
    using adc_common_control_vbate = lib::regbit<22>;
    using adc_common_control_tsvrefe = lib::regbit<23>;

    template <lib::u32 addr>
    struct adc_common_d {
        struct adc_common_t {
            lib::u32 status;
            lib::u32 control;
            lib::u16 data1;
            lib::u16 data2;
        };

    static constexpr volatile adc_common_t * const regs =
            reinterpret_cast<adc_common_t *>(addr);
    };
}

#endif // ADC_T_HH
