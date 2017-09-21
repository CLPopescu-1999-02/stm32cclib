#ifndef FLASH_T_HH
#define FLASH_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using flash_access_control_latency =
        lib::regbit<0, lib::u8, 3, 0>;
    using flash_access_control_prften = lib::regbit<8>;
    using flash_access_control_icen = lib::regbit<9>;
    using flash_access_control_dcen = lib::regbit<10>;
    using flash_access_control_icrst = lib::regbit<11>;
    using flash_access_control_dcrst = lib::regbit<12>;

    using flash_status_eop = lib::regbit<0>;
    using flash_status_operr = lib::regbit<1>;
    using flash_status_wrperr = lib::regbit<4>;
    using flash_status_pgaerr = lib::regbit<5>;
    using flash_status_pgperr = lib::regbit<6>;
    using flash_status_pgserr = lib::regbit<7>;
    using flash_status_bsy = lib::regbit<16>;

    using flash_control_pg = lib::regbit<0>;
    using flash_control_ser = lib::regbit<1>;
    using flash_control_mer = lib::regbit<2>;
    using flash_control_snb =
        lib::regbit<3, lib::u8, 4, 0>;
    enum struct flash_control_psize_t : lib::u8 {
        x8 = 0,
        x16,
        x32,
        x64
    };
    using flash_control_psize =
        lib::regbit<8,
            flash_control_psize_t,
            2,
            flash_control_psize_t::x8>;
    using flash_control_strt = lib::regbit<16>;
    using flash_control_eopie = lib::regbit<24>;
    using flash_control_errie = lib::regbit<25>;
    using flash_control_lock = lib::regbit<31>;

    using flash_opt_control_optlock = lib::regbit<0>;
    using flash_opt_control_optstrt = lib::regbit<1>;
    using flash_opt_control_bor_lev =
        lib::regbit<2, lib::u8, 2, 0>;
    using flash_opt_control_wdg_sw = lib::regbit<5>;
    using flash_opt_control_nrst_stop = lib::regbit<6>;
    using flash_opt_control_nrst_stdby = lib::regbit<7>;
    using flash_opt_control_rdp =
        lib::regbit<8, lib::u8, 8, 0>;
    using flash_opt_control_nwrp =
        lib::regbit<16, lib::u16, 12, 0>;

    template <lib::u32 addr>
    struct flash_d {
        struct flash_t {
            lib::u32 access_control;
            lib::u32 key;
            lib::u32 opt_key;
            lib::u32 status;
            lib::u32 control;
            lib::u32 opt_control;
        };

        static constexpr volatile flash_t * const regs =
            reinterpret_cast<flash_t *>(addr);
    };
}

#endif // FLASH_T_HH
