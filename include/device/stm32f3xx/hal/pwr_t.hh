#ifndef PWR_T_HH
#define PWR_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using pwr_control_lpds = lib::regbit<0>;
    using pwr_control_pdds = lib::regbit<1>;
    using pwr_control_cwuf = lib::regbit<2>;
    using pwr_control_csbf = lib::regbit<3>;
    using pwr_control_pvde = lib::regbit<4>;
    enum struct pwr_control_pls_t : lib::u8 {
        l2_2v = 0b000,
        l2_3v = 0b001,
        l2_4v = 0b010,
        l2_5v = 0b011,
        l2_6v = 0b100,
        l2_7v = 0b101,
        l2_8v = 0b110,
        l2_9 = 0b111
    };
    using pwr_control_pls =
        lib::regbit<5,
        pwr_control_pls_t,
        3,
        pwr_control_pls_t::l2_2v>;
    using pwr_control_dbp = lib::regbit<8>;

    using pwr_control_status_wuf = lib::regbit<0>;
    using pwr_control_status_sbf = lib::regbit<1>;
    using pwr_control_status_pvdo = lib::regbit<2>;
    using pwr_control_status_vrefintrdyf = lib::regbit<3>;
    using pwr_control_status_ewup1 = lib::regbit<8>;
    using pwr_control_status_ewup2 = lib::regbit<9>;
    using pwr_control_status_ewup3 = lib::regbit<10>;

    template <lib::u32 addr>
    struct pwr_d {
        struct pwr_t {
            lib::u32 control;
            lib::u32 control_status;
        };

        static constexpr volatile pwr_t & regs() {
            return *reinterpret_cast<pwr_t *>(addr);
        }
    };
}

#endif // PWR_T_HH
