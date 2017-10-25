#ifndef OPAMP_T_HH
#define OPAMP_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    template <lib::u32 addr>
    struct opamp_d {
        using control_status_opa1pd = lib::regbit<0>;
        using control_status_s3sel1 = lib::regbit<1>;
        using control_status_s4sel1 = lib::regbit<2>;
        using control_status_s5sel1 = lib::regbit<3>;
        using control_status_s6sel1 = lib::regbit<4>;
        using control_status_opa1cal_l = lib::regbit<5>;
        using control_status_opa1cal_h = lib::regbit<6>;
        using control_status_opa1lpm = lib::regbit<7>;
        using control_status_opa2pd = lib::regbit<8>;
        using control_status_s3sel2 = lib::regbit<9>;
        using control_status_s4sel2 = lib::regbit<10>;
        using control_status_s5sel2 = lib::regbit<11>;
        using control_status_s6sel2 = lib::regbit<12>;
        using control_status_opa2cal_l = lib::regbit<13>;
        using control_status_opa2cal_h = lib::regbit<14>;
        using control_status_opa2lpm = lib::regbit<15>;
        using control_status_opa3pd = lib::regbit<16>;
        using control_status_s3sel3 = lib::regbit<17>;
        using control_status_s4sel3 = lib::regbit<18>;
        using control_status_s5sel3 = lib::regbit<19>;
        using control_status_s6sel3 = lib::regbit<20>;
        using control_status_opa3cal_l = lib::regbit<21>;
        using control_status_opa3cal_h = lib::regbit<22>;
        using control_status_opa3lpm = lib::regbit<23>;
        using control_status_anawsel1 = lib::regbit<24>;
        using control_status_anawsel2 = lib::regbit<25>;
        using control_status_anawsel3 = lib::regbit<26>;
        using control_status_s7sel2 = lib::regbit<27>;
        using control_status_opa_range = lib::regbit<28>;
        using control_status_opa1calout = lib::regbit<29>;
        using control_status_opa2calout = lib::regbit<30>;
        using control_status_opa3calout = lib::regbit<31>;

        using offset_oa1_opt_offset_trim_low = lib::regbit8<0, 5>;
        using offset_oa1_opt_offset_trim_high = lib::regbit8<5, 5>;
        using offset_oa2_opt_offset_trim_low = lib::regbit8<10, 5>;
        using offset_oa2_opt_offset_trim_high = lib::regbit8<15, 5>;
        using offset_oa3_opt_offset_trim_low = lib::regbit8<20, 5>;
        using offset_oa3_opt_offset_trim_high = lib::regbit8<25, 5>;
        using offset_ot_user = lib::regbit<31>;

        using offset_lp_oa1_opt_offset_trim_low = lib::regbit8<0, 5>;
        using offset_lp_oa1_opt_offset_trim_high = lib::regbit8<5, 5>;
        using offset_lp_oa2_opt_offset_trim_low = lib::regbit8<10, 5>;
        using offset_lp_oa2_opt_offset_trim_high = lib::regbit8<15, 5>;
        using offset_lp_oa3_opt_offset_trim_low = lib::regbit8<20, 5>;
        using offset_lp_oa3_opt_offset_trim_high = lib::regbit8<25, 5>;

        struct opamp_t {
            lib::u32 control_status;
            lib::u32 offset;
            lib::u32 offset_lp;
        };

        static constexpr volatile opamp_t & regs() {
            return *reinterpret_cast<opamp_t *>(addr);
        }
    };
}

#endif // OPAMP_T_HH
