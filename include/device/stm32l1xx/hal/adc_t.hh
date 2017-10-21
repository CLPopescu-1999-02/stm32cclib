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
    using adc_status_adons = lib::regbit<6>;
    using adc_status_rcnr = lib::regbit<8>;
    using adc_status_jcnr = lib::regbit<9>;

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
    using adc_control1_pdd = lib::regbit<16>;
    using adc_control1_pdi = lib::regbit<17>;
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
    using adc_control2_adc_cfg = lib::regbit<2>;
    enum struct adc_control2_dels_t : lib::u8 {
        no_delay = 0b000,
        until_read = 0b001,
        on7abp = 0b010,
        on15apb = 0b011,
        on31apb = 0b100,
        on63apb = 0b101,
        on127apb = 0b110,
        on255apb = 0b111
    };
    using adc_control2_dels =
        lib::regbit<4,
            adc_control2_dels_t,
            3,
            adc_control2_dels_t::no_delay>;
    using adc_control2_dma = lib::regbit<8>;
    using adc_control2_dds = lib::regbit<9>;
    using adc_control2_eocs = lib::regbit<10>;
    using adc_control2_align = lib::regbit<11>;
    enum struct adc_control2_jextsel_t : lib::u8 {
        tim9_cc1 = 0,
        tim9_trgo = 1,
        tim2_trgo = 2,
        tim2_cc1 = 3,
        tim3_cc4 = 4,
        tim4_trgo = 5,
        tim4_cc1 = 6,
        tim4_cc2 = 7,
        tim4_cc3 = 8,
        tim10_cc1 = 9,
        tim7_trgo = 10,
        exti_15 = 15
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
        tim9_cc2 = 0,
        tim9_trgo = 1,
        tim2_cc3 = 2,
        tim2_cc2 = 3,
        tim3_trgo = 4,
        tim4_cc4 = 5,
        tim2_trgo = 6,
        tim3_cc1 = 7,
        tim3_cc3 = 8,
        tim4_trgo = 9,
        tim6_trgo = 10,
        exti_11 = 15
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

    using adc_inject_ch_data_off = lib::regbit16<0, 12>;;

    using adc_higher_threshold = lib::regbit16<0, 12>;;

    using adc_lower_threshold = lib::regbit16<0, 12>;;

    using inject_sequence_jsq1 = lib::regbit8<0, 5>;
    using inject_sequence_jsq2 = lib::regbit8<5, 5>;
    using inject_sequence_jsq3 = lib::regbit8<10, 5>;
    using inject_sequence_jsq4 = lib::regbit8<15, 5>;
    using inject_sequence_jl = lib::regbit8<20, 2>;

    enum struct adc_sample_time_t : lib::u8 {
        by4cycles = 0b000,
        by9cycles = 0b001,
        by16cycles = 0b010,
        by24cycles = 0b011,
        by48cycles = 0b100,
        by96cycles = 0b101,
        by192cycles = 0b110,
        by384cycles = 0b111
    };
    using adc_sample_time3_smp0 =
        lib::regbit<0,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time3_smp1 =
        lib::regbit<3,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time3_smp2 =
        lib::regbit<6,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time3_smp3 =
        lib::regbit<9,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time3_smp4 =
        lib::regbit<12,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time3_smp5 =
        lib::regbit<15,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time3_smp6 =
        lib::regbit<18,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time3_smp7 =
        lib::regbit<21,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time3_smp8 =
        lib::regbit<24,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time3_smp9 =
        lib::regbit<27,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;

    using adc_sample_time2_smp10 =
        lib::regbit<0,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time2_smp11 =
        lib::regbit<3,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time2_smp12 =
        lib::regbit<6,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time2_smp13 =
        lib::regbit<9,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time2_smp14 =
        lib::regbit<12,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time2_smp15 =
        lib::regbit<15,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time2_smp16 =
        lib::regbit<18,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time2_smp17 =
        lib::regbit<21,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time2_smp18 =
        lib::regbit<24,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time2_smp19 =
        lib::regbit<27,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;

    using adc_sample_time1_smp20 =
        lib::regbit<0,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time1_smp21 =
        lib::regbit<3,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time1_smp22 =
        lib::regbit<6,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time1_smp23 =
        lib::regbit<9,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time1_smp24 =
        lib::regbit<12,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time1_smp25 =
        lib::regbit<15,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time1_smp26 =
        lib::regbit<18,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time1_smp27 =
        lib::regbit<21,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time1_smp28 =
        lib::regbit<24,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time1_smp29 =
        lib::regbit<27,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;

    using adc_sample_time0_smp30 =
        lib::regbit<0,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;
    using adc_sample_time0_smp31 =
        lib::regbit<3,
            adc_sample_time_t,
            3,
            adc_sample_time_t::by4cycles>;


    using adc_regular_sequence5_sq1 = lib::regbit8<0, 5>;
    using adc_regular_sequence5_sq2 = lib::regbit8<5, 5>;
    using adc_regular_sequence5_sq3 = lib::regbit8<10, 5>;
    using adc_regular_sequence5_sq4 = lib::regbit8<15, 5>;
    using adc_regular_sequence5_sq5 = lib::regbit8<20, 5>;
    using adc_regular_sequence5_sq6 = lib::regbit8<25, 5>;

    using adc_regular_sequence4_sq7 = lib::regbit8<0, 5>;
    using adc_regular_sequence4_sq8 = lib::regbit8<5, 5>;
    using adc_regular_sequence4_sq9 = lib::regbit8<10, 5>;
    using adc_regular_sequence4_sq10 = lib::regbit8<15, 5>;
    using adc_regular_sequence4_sq11 = lib::regbit8<20, 5>;
    using adc_regular_sequence4_sq12 = lib::regbit8<25, 5>;

    using adc_regular_sequence3_sq13 = lib::regbit8<0, 5>;
    using adc_regular_sequence3_sq14 = lib::regbit8<5, 5>;
    using adc_regular_sequence3_sq15 = lib::regbit8<10, 5>;
    using adc_regular_sequence3_sq16 = lib::regbit8<15, 5>;
    using adc_regular_sequence3_sq17 = lib::regbit8<20, 5>;
    using adc_regular_sequence3_sq18 = lib::regbit8<25, 5>;

    using adc_regular_sequence2_sq19 = lib::regbit8<0, 5>;
    using adc_regular_sequence2_sq20 = lib::regbit8<5, 5>;
    using adc_regular_sequence2_sq21 = lib::regbit8<10, 5>;
    using adc_regular_sequence2_sq22 = lib::regbit8<15, 5>;
    using adc_regular_sequence2_sq23 = lib::regbit8<20, 5>;
    using adc_regular_sequence2_sq24 = lib::regbit8<25, 5>;

    using adc_regular_sequence1_sq25 = lib::regbit8<0, 5>;
    using adc_regular_sequence1_sq26 = lib::regbit8<5, 5>;
    using adc_regular_sequence1_sq27 = lib::regbit8<10, 5>;
    using adc_regular_sequence1_sq28 = lib::regbit8<15, 5>;
    using adc_regular_sequence1_l = lib::regbit8<20, 5>;

    template <lib::u32 addr>
    struct adc_d {
        struct adc_t {
            lib::u32 status;
            lib::u32 control1;
            lib::u32 control2;
            lib::u32 sample_time1;
            lib::u32 sample_time2;
            lib::u32 sample_time3;
            lib::u32 inject_ch_data_off1;
            lib::u32 inject_ch_data_off2;
            lib::u32 inject_ch_data_off3;
            lib::u32 inject_ch_data_off4;
            lib::u32 higher_threshold;
            lib::u32 lower_threshold;
            lib::u32 regular_sequence1;
            lib::u32 regular_sequence2;
            lib::u32 regular_sequence3;
            lib::u32 regular_sequence4;
            lib::u32 regular_sequence5;
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
            lib::u32 sample_time0;
        };

        static constexpr volatile adc_t & regs() {
            return *reinterpret_cast<adc_t *>(addr);
        }
    };

    using adc_common_status_awd = lib::regbit<0>;
    using adc_common_status_eoc1 = lib::regbit<1>;
    using adc_common_status_jeoc1 = lib::regbit<2>;
    using adc_common_status_jstrt1 = lib::regbit<3>;
    using adc_common_status_strt1 = lib::regbit<4>;
    using adc_common_status_ovr1 = lib::regbit<5>;
    using adc_common_status_adons1 = lib::regbit<6>;

    enum struct adc_common_control_adcpre_t : lib::u8 {
        by1 = 0b00,
        by2 = 0b01,
        by4 = 0b10
    };
    using adc_common_control_adcpre =
        lib::regbit<16,
            adc_common_control_adcpre_t,
            2,
            adc_common_control_adcpre_t::by1>;
    using adc_common_control_tsvrefe = lib::regbit<23>;

    template <lib::u32 addr>
    struct adc_common_d {
        struct adc_common_t {
            lib::u32 status;
            lib::u32 control;
        };

        static constexpr volatile adc_common_t & regs() {
            return *reinterpret_cast<adc_common_t *>(addr);
        }
    };
}

#endif // ADC_T_HH
