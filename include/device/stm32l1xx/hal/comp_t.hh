#ifndef COMP_T_HH
#define COMP_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    template <lib::u32 addr>
    struct comp_d {
        using en400kpd = lib::regbit<3>;
        using en = lib::regbit<4>;
        using sw1 = lib::regbit<5>;
        using cmp1_out = lib::regbit<7>;
        using speed = lib::regbit<12>;
        using cmp2_out = lib::regbit<13>;
        using vrefouten = lib::regbit<16>;
        using wndwe = lib::regbit<17>;
        enum struct insel_t : lib::u8 {
            no_selection = 0b000,
            pb3_comp2_inm = 0b001,
            vrefint = 0b010,
            vrefint_by_3mod4 = 0b011,
            vrefint_by_1mod2 = 0b100,
            vrefint_by_1mod4 = 0b101,
            dac_out1 = 0b110,
            dac_out2 = 0b111
        };
        using insel =
            lib::regbit<18,
                insel_t,
                3,
                insel_t::no_selection>;
        enum struct outsel_t : lib::u8 {
            tim2_cc4 = 0b000,
            tim2_oc_ref,
            tim3_cc4,
            tim3_oc_ref,
            tim4_cc4,
            tim4_oc_ref,
            tim10_cc1,
            no_redirection
        };
        using outsel =
            lib::regbit<21,
                outsel_t,
                3,
                outsel_t::tim2_cc4>;
        using fch3 = lib::regbit<26>;
        using fch8 = lib::regbit<27>;
        using fch13 = lib::regbit<28>;
        using caie = lib::regbit<29>;
        using caif = lib::regbit<30>;
        using tsusp = lib::regbit<31>;

        struct comp_t {
            lib::u32 comp;
        };

        static constexpr volatile comp_t & regs() {
            return *reinterpret_cast<comp_t *>(addr);
        }
    };
}

#endif // COMP_T_HH
