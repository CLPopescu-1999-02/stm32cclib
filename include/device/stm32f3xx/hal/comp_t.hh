#ifndef COMP_T_HH
#define COMP_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    template <lib::u32 addr>
    struct comp_d {
        using en = lib::regbit<0>;
        using comp1_inp_dac = lib::regbit<1>;
        enum struct mode_t : lib::u8 {
            high_speed = 0b00,
            medium_speed = 0b01,
            low_power = 0b10,
            ultra_low_power = 0b11
        };
        using mode =
            lib::regbit<2,
                mode_t,
                2,
                mode_t::high_speed>;
        enum struct inmsel_t : lib::u8 {
            vrefint_by_1mod4 = 0b000,
            vrefint_by_1mod2 = 0b001,
            vrefint_by_3mod4 = 0b010,
            vrefint = 0b011,
            pa4_dac1 = 0b100,
            pa5_dac2 = 0b101,
            pa0 = 0b110,
            pa2 = 0b110,
            pd15 = 0b110,
            pb12 = 0b111
        };
        using inmsel =
            lib::regbit<4,
                inmsel_t,
                3,
                inmsel_t::vrefint_by_1mod4>;
        enum struct outsel_t : lib::u8 {
            no_selection = 0b0000,
            tim1_br,
            tim1_br2,
            tim8_br,
            tim8_br2,
            tim1_br2_tim8_br2,
            tim1_oc_ref,
            tim1_cc1,
            tim2_cc4,
            tim2_oc_ref,
            tim3_cc1,
            tim3_oc_ref
        };
        using outsel =
            lib::regbit<10,
                outsel_t,
                4,
                outsel_t::no_selection>;
        using pol = lib::regbit<15>;
        enum struct hyst_t : lib::u8 {
            no = 0b00,
            low,
            medium,
            high,
        };
        using hyst =
            lib::regbit<16,
                hyst_t,
                2,
                hyst_t::no>;
        enum struct blanking_t : lib::u8 {
            no = 0b000,
            tim1_oc5,
            tim2_oc3,
            tim3_oc3
        };
        using blanking =
            lib::regbit<18,
                blanking_t,
                3,
                blanking_t::no>;
        using out = lib::regbit<30>;
        using lock = lib::regbit<31>;

        using comp2_inpsel = lib::regbit<7>;
        using comp2_winmode = lib::regbit<9>;

        using comp3_inpsel = lib::regbit<7>;

        using comp4_inpsel = lib::regbit<7>;
        using comp4_winmode = lib::regbit<9>;

        using comp5_inpsel = lib::regbit<7>;

        using comp6_inpsel = lib::regbit<7>;
        using comp6_winmode = lib::regbit<9>;

        using comp7_inpsel = lib::regbit<7>;

        struct comp_t {
            lib::u32 comp1;
            lib::u32 comp2;
            lib::u32 comp3;
            lib::u32 comp4;
            lib::u32 comp5;
            lib::u32 comp6;
            lib::u32 comp7;
        };

        static constexpr volatile comp_t & regs() {
            return *reinterpret_cast<comp_t *>(addr);
        }
    };
}

#endif // COMP_T_HH
