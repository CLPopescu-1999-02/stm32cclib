#ifndef PWR_T_HH
#define PWR_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using pwr_control_lpsdsr = lib::regbit<0>;
    using pwr_control_pdds = lib::regbit<1>;
    using pwr_control_cwuf = lib::regbit<2>;
    using pwr_control_csbf = lib::regbit<3>;
    using pwr_control_pvde = lib::regbit<4>;
    enum struct pwr_control_pls_t : lib::u8 {
        l1_9v = 0b000,
        l2_1v = 0b001,
        l2_3v = 0b010,
        l2_5v = 0b011,
        l2_7v = 0b100,
        l2_9v = 0b101,
        l3_1v = 0b110,
        external = 0b111
    };
    using pwr_control_pls =
        lib::regbit<5,
        pwr_control_pls_t,
        3,
        pwr_control_pls_t::l1_9v>;
    using pwr_control_dbp = lib::regbit<8>;
    using pwr_control_ulp = lib::regbit<9>;
    using pwr_control_fwu = lib::regbit<10>;
    enum struct pwr_control_vos_t : lib::u8 {
        l1_8v = 0b01,
        l1_5v = 0b10,
        l1_2v = 0b11
    };
    using pwr_control_vos =
        lib::regbit<11,
        pwr_control_vos_t,
        2,
        pwr_control_vos_t::l1_5v>;
    using pwr_control_lprun = lib::regbit<14>;

    using pwr_control_status_wuf = lib::regbit<0>;
    using pwr_control_status_sbf = lib::regbit<1>;
    using pwr_control_status_pvdo = lib::regbit<2>;
    using pwr_control_status_vrefintrdyf = lib::regbit<3>;
    using pwr_control_status_vosf = lib::regbit<4>;
    using pwr_control_status_reglpf = lib::regbit<5>;
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
