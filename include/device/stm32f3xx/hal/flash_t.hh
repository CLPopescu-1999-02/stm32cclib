#ifndef FLASH_T_HH
#define FLASH_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using flash_access_control_latency =
        lib::regbit<0, lib::u8, 3, 0>;
    using flash_access_control_hlfcya = lib::regbit<3>;
    using flash_access_control_prftbe = lib::regbit<4>;
    using flash_access_control_prftbs = lib::regbit<5>;

    using flash_status_bsy = lib::regbit<0>;
    using flash_status_pgerr = lib::regbit<2>;
    using flash_status_wrprterr = lib::regbit<4>;
    using flash_status_eop = lib::regbit<5>;

    using flash_control_pg = lib::regbit<0>;
    using flash_control_ser = lib::regbit<1>;
    using flash_control_mer = lib::regbit<2>;
    using flash_control_optpg = lib::regbit<4>;
    using flash_control_opter = lib::regbit<5>;
    using flash_control_strt = lib::regbit<6>;
    using flash_control_lock = lib::regbit<7>;
    using flash_control_optwre = lib::regbit<9>;
    using flash_control_errie = lib::regbit<10>;
    using flash_control_eopie = lib::regbit<12>;
    using flash_control_obl_launch = lib::regbit<13>;

    using flash_opt_control_opterr = lib::regbit<0>;
    using flash_opt_control_rdprt =
        lib::regbit<1, lib::u8, 2, 0>;
    using flash_opt_control_wdg_sw = lib::regbit<8>;
    using flash_opt_control_nrst_stop = lib::regbit<9>;
    using flash_opt_control_nrst_stdby = lib::regbit<10>;
    using flash_opt_control_nboot1 = lib::regbit<12>;
    using flash_opt_control_vdda_monitor = lib::regbit<13>;
    using flash_opt_control_sram_pe = lib::regbit<14>;

    template <lib::u32 addr>
    struct flash_d {
        struct flash_t {
            lib::u32 access_control;
            lib::u32 key;
            lib::u32 opt_key;
            lib::u32 status;
            lib::u32 control;
            lib::u32 address;
            lib::u32 opt_control;
            lib::u32 write_portection;
        };

        static constexpr volatile flash_t * const regs =
            reinterpret_cast<flash_t *>(addr);
    };
}

#endif // FLASH_T_HH
