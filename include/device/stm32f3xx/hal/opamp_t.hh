#ifndef OPAMP_T_HH
#define OPAMP_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    template <lib::u32 addr>
    struct opamp_d {
        using en = lib::regbit<0>;
        using force_vp = lib::regbit<1>;
        using vp_sel = lib::regbit8<2, 2>;
        using vm_sel = lib::regbit8<5, 2>;
        using tcm_en = lib::regbit<7>;
        using vms_sel = lib::regbit<8>;
        using vps_sel = lib::regbit8<9, 2>;
        using calon = lib::regbit<11>;
        using calsel = lib::regbit8<12, 2>;
        using pga_gain = lib::regbit8<14, 4>;
        using trimoffsetp = lib::regbit8<19, 5>;
        using trimoffsetn = lib::regbit8<24, 5>;
        using tstref = lib::regbit<29>;
        using outcal = lib::regbit<30>;
        using lock = lib::regbit<31>;

        struct opamp_t {
            lib::u32 opamp1;
            lib::u32 opamp2;
            lib::u32 opamp3;
            lib::u32 opamp4;
        };

        static constexpr volatile opamp_t & regs() {
            return *reinterpret_cast<opamp_t *>(addr);
        }
    };
}

#endif // OPAMP_T_HH
