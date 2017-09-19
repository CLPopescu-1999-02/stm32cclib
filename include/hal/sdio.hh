#ifndef SDIO_HH
#define SDIO_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    enum struct sdio_power_pwrctrl_t : lib::u8 {
        power_off = 0b00,
        power_up = 0b10,
        power_on = 0b11
    };
    using sdio_power_pwrctrl =
        lib::regbit<0,
            sdio_power_pwrctrl_t,
            2,
            sdio_power_pwrctrl_t::power_off>;

    using sdio_clock_control_clkdiv =
        lib::regbit<0, lib::u8, 8, 0>;
    using sdio_clock_control_clken = lib::regbit<8>;
    using sdio_clock_control_pwrsav = lib::regbit<9>;
    using sdio_clock_control_bypass = lib::regbit<10>;
    enum struct sdio_clock_control_widbus_t : lib::u8 {
        default_mode = 0b00,
        on4wide_mode = 0b01,
        on8wide_mode = 0b10
    };
    using sdio_clock_control_widbus =
        lib::regbit<11,
            sdio_clock_control_widbus_t,
            2,
            sdio_clock_control_widbus_t::default_mode>;
    using sdio_clock_control_negedge = lib::regbit<13>;
    using sdio_clock_control_hwfc_en = lib::regbit<14>;

    using sdio_command_cmdindex =
        lib::regbit<0, lib::u8, 6, 0>;
    enum struct sdio_command_waitresp_t : lib::u8 {
        no_resp_exp_cmdsent = 0b00,
        short_resp_exp_cmdrend_ccrcfail = 0b01,
        no_resp_exp_cmdsent2 = 0b10,
        long_resp_exp_cmdrend_ccrcfail = 0b11
    };
    using sdio_command_waitresp =
        lib::regbit<6,
            sdio_command_waitresp_t,
            2,
            sdio_command_waitresp_t::no_resp_exp_cmdsent>;
    using sdio_command_waitint = lib::regbit<8>;
    using sdio_command_waitpend = lib::regbit<9>;
    using sdio_command_cpsmen = lib::regbit<10>;
    using sdio_command_sdio_suspend = lib::regbit<11>;
    using sdio_command_encmd_compl = lib::regbit<12>;
    using sdio_command_n_ien = lib::regbit<13>;
    using sdio_command_ata_cmd = lib::regbit<14>;

    using sdio_data_control_dten = lib::regbit<0>;
    using sdio_data_control_dtdir = lib::regbit<1>;
    using sdio_data_control_dtmode = lib::regbit<2>;
    using sdio_data_control_dmaen = lib::regbit<3>;
    enum struct sdio_data_control_dblock_size_t : lib::u8 {
        is1byte = 0,
        is2bytes,
        is4bytes,
        is8bytes,
        is16bytes,
        is32bytes,
        is64bytes,
        is128bytes,
        is256bytes,
        is512bytes,
        is1024bytes,
        is2048bytes,
        is4096bytes,
        is8192bytes,
        is16384bytes,
    };
    using sdio_data_control_dblock_size =
        lib::regbit<4,
            sdio_data_control_dblock_size_t,
            4,
            sdio_data_control_dblock_size_t::is1byte>;
    using sdio_data_control_rwstart = lib::regbit<8>;
    using sdio_data_control_rwstop = lib::regbit<9>;
    using sdio_data_control_rwmod = lib::regbit<10>;
    using sdio_data_control_sdioen = lib::regbit<11>;

    using sdio_status_ccrfail = lib::regbit<0>;
    using sdio_status_dcrfail = lib::regbit<1>;
    using sdio_status_ctimeout = lib::regbit<2>;
    using sdio_status_dtimeout = lib::regbit<3>;
    using sdio_status_txunderr = lib::regbit<4>;
    using sdio_status_rxoverr = lib::regbit<5>;
    using sdio_status_cmdrend = lib::regbit<6>;
    using sdio_status_cmdsent = lib::regbit<7>;
    using sdio_status_dataend = lib::regbit<8>;
    using sdio_status_stbiterr = lib::regbit<9>;
    using sdio_status_dbckend = lib::regbit<10>;
    using sdio_status_cmdact = lib::regbit<11>;
    using sdio_status_txact = lib::regbit<12>;
    using sdio_status_rxact = lib::regbit<13>;
    using sdio_status_txfifohe = lib::regbit<14>;
    using sdio_status_rxfifohf = lib::regbit<15>;
    using sdio_status_txfifof = lib::regbit<16>;
    using sdio_status_rxfifof = lib::regbit<17>;
    using sdio_status_txfifoe = lib::regbit<18>;
    using sdio_status_rxfifoe = lib::regbit<19>;
    using sdio_status_txdavl = lib::regbit<20>;
    using sdio_status_rxdavl = lib::regbit<21>;
    using sdio_status_sdioit = lib::regbit<22>;
    using sdio_status_ceataend = lib::regbit<23>;

    template <lib::u32 addr>
    struct sdio_d {
        struct sdio_t {
            lib::u32 power;
            lib::u32 clock_control;
            lib::u32 argument;
            lib::u32 command;
            lib::u32 resp_command;
            lib::u32 resp1;
            lib::u32 resp2;
            lib::u32 resp3;
            lib::u32 resp4;
            lib::u32 data_timer;
            lib::u32 data_len;
            lib::u32 data_control;
            lib::u32 data_count;
            lib::u32 status;
            lib::u32 clear;
            lib::u32 mask;
            lib::u32 fifo_count;
            lib::u32 fifo_data;
        };

        static constexpr volatile sdio_t * const regs =
            reinterpret_cast<sdio_t *>(addr);
    };
}

#include "hal/sdio_d.hh"

#endif // SDIO_HH
