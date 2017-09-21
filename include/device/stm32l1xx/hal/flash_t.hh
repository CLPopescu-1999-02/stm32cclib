#ifndef FLASH_T_HH
#define FLASH_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using flash_access_control_latency = lib::regbit<0>;
    using flash_access_control_prften = lib::regbit<1>;
    using flash_access_control_acc64 = lib::regbit<2>;
    using flash_access_control_sleep_pd = lib::regbit<3>;
    using flash_access_control_run_pd = lib::regbit<4>;

    using flash_control_pelock = lib::regbit<0>;
    using flash_control_prglock = lib::regbit<1>;
    using flash_control_optlock = lib::regbit<2>;
    using flash_control_prog = lib::regbit<3>;
    using flash_control_data = lib::regbit<4>;
    using flash_control_ftdw = lib::regbit<8>;
    using flash_control_erase = lib::regbit<9>;
    using flash_control_fprg = lib::regbit<10>;
    using flash_control_parallbank = lib::regbit<15>;
    using flash_control_eopie = lib::regbit<16>;
    using flash_control_errie = lib::regbit<17>;
    using flash_control_obl_launch = lib::regbit<18>;

    using flash_status_bsy = lib::regbit<0>;
    using flash_status_eop = lib::regbit<1>;
    using flash_status_endhv = lib::regbit<2>;
    using flash_status_ready = lib::regbit<3>;
    using flash_status_wrperr = lib::regbit<8>;
    using flash_status_pgaerr = lib::regbit<9>;
    using flash_status_sizerr = lib::regbit<10>;
    using flash_status_optverr = lib::regbit<11>;
    using flash_status_optverrusr = lib::regbit<12>;
    using flash_status_rderr = lib::regbit<13>;

    using flash_opt_control_rdprt =
        lib::regbit<0, lib::u8, 8, 0>;
    using flash_opt_control_sprmod = lib::regbit<8>;
    using flash_opt_control_optstrt = lib::regbit<1>;
    using flash_opt_control_bor_lev =
        lib::regbit<16, lib::u8, 4, 0>;
    using flash_opt_control_wdg_sw = lib::regbit<20>;
    using flash_opt_control_nrst_stop = lib::regbit<21>;
    using flash_opt_control_nrst_stdby = lib::regbit<22>;
    using flash_opt_control_bfb2 = lib::regbit<23>;

    template <lib::u32 addr>
    struct flash_d {
        struct flash_t {
            lib::u32 access_control;
            lib::u32 control;
            lib::u32 pwr_down_key;
            lib::u32 program_erase_key;
            lib::u32 key;
            lib::u32 opt_key;
            lib::u32 status;
            lib::u32 opt_control;
            lib::u32 write_protect1;
            lib::u32 write_protect2;
            lib::u32 write_protect3;
            lib::u32 write_protect4;
        };

        static constexpr volatile flash_t * const regs =
            reinterpret_cast<flash_t *>(addr);
    };
}

#endif // FLASH_T_HH
