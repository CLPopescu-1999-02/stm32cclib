#ifndef FSMC_COMMON_T_HH
#define FSMC_COMMON_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using fsmc_cs_control_mbken = lib::regbit<0>;
    using fsmc_cs_control_muxen = lib::regbit<1>;
    enum struct fsmc_cs_control_mtyp_t : lib::u8 {
        sram = 0b00,
        psram,
        nor_flash
    };
    using fsmc_cs_control_mtyp =
        lib::regbit<2,
            fsmc_cs_control_mtyp_t,
            2,
            fsmc_cs_control_mtyp_t::sram>;
    enum struct fsmc_cs_control_mwid_t : lib::u8 {
        on8bits = 0b00,
        on16bits
    };
    using fsmc_cs_control_mwid =
        lib::regbit<4,
            fsmc_cs_control_mwid_t,
            2,
            fsmc_cs_control_mwid_t::on8bits>;
    using fsmc_cs_control_faccen = lib::regbit<6>;
    using fsmc_cs_control_bursten = lib::regbit<8>;
    using fsmc_cs_control_waitpol = lib::regbit<9>;
    using fsmc_cs_control_wrapmod = lib::regbit<10>;
    using fsmc_cs_control_waitcfg = lib::regbit<11>;
    using fsmc_cs_control_wren = lib::regbit<12>;
    using fsmc_cs_control_waiten = lib::regbit<13>;
    using fsmc_cs_control_extmod = lib::regbit<14>;
    using fsmc_cs_control_asyncwait = lib::regbit<15>;
    enum struct fsmc_cs_control_cpsize_t : lib::u8 {
        no_burst = 0b000,
        on128bytes,
        on256bytes,
        on512bytes,
        on1024bytes
    };
    using fsmc_cs_control_cpsize =
        lib::regbit<16,
            fsmc_cs_control_cpsize_t,
            3,
            fsmc_cs_control_cpsize_t::no_burst>;
    using fsmc_cs_control_cburstrw = lib::regbit<19>;

    using fsmc_cs_timing_addset =
        lib::regbit<0, lib::u8, 4, 0>;
    using fsmc_cs_timing_addhld =
        lib::regbit<4, lib::u8, 4, 0>;
    using fsmc_cs_timing_datast =
        lib::regbit<8, lib::u8, 8, 0>;
    using fsmc_cs_timing_busturn =
        lib::regbit<16, lib::u8, 4, 0>;
    using fsmc_cs_timing_clkdiv =
        lib::regbit<20, lib::u8, 4, 0>;
    using fsmc_cs_timing_datlat =
        lib::regbit<24, lib::u8, 4, 0>;
    using fsmc_cs_timing_accmod =
        lib::regbit<28, lib::u8, 4, 0>;

    struct fsmc_bank1_t {
        lib::u32 cs_control1;
        lib::u32 cs_timing1;
        lib::u32 cs_control2;
        lib::u32 cs_timing2;
        lib::u32 cs_control3;
        lib::u32 cs_timing3;
        lib::u32 cs_control4;
        lib::u32 cs_timing4;
    };

    using fsmc_write_timing_addset =
        lib::regbit<0, lib::u8, 4, 0>;
    using fsmc_write_timing_addhld =
        lib::regbit<4, lib::u8, 4, 0>;
    using fsmc_write_timing_datast =
        lib::regbit<8, lib::u8, 8, 0>;
    using fsmc_write_timing_busturn =
        lib::regbit<16, lib::u8, 4, 0>;
    using fsmc_write_timing_accmod =
        lib::regbit<28, lib::u8, 4, 0>;

    struct fsmc_bank1e_t {
        lib::u32 write_timing1;
        lib::u32 _unused0;
        lib::u32 write_timing2;
        lib::u32 _unused1;
        lib::u32 write_timing3;
        lib::u32 _unused2;
        lib::u32 write_timing4;
    };

    using fsmc_control_pwaiten = lib::regbit<1>;
    using fsmc_control_pbken = lib::regbit<2>;
    using fsmc_control_ptyp = lib::regbit<3>;
    enum struct fsmc_control_pwid_t : lib::u8 {
        on8bits = 0b00,
        on16bits
    };
    using fsmc_control_pwid =
        lib::regbit<4,
            fsmc_control_pwid_t,
            2,
            fsmc_control_pwid_t::on8bits>;
    using fsmc_control_eccen = lib::regbit<6>;
    using fsmc_control_tclr =
        lib::regbit<9, lib::u8, 4, 0>;
    using fsmc_control_tar =
        lib::regbit<13, lib::u8, 4, 0>;
    enum struct fsmc_control_eccps_t : lib::u8 {
        on256bytes = 0b000,
        on512bytes,
        on1024bytes,
        on2048bytes,
        on4096bytes,
        on8192bytes
    };
    using fsmc_control_eccps =
        lib::regbit<17,
            fsmc_control_eccps_t,
            3,
            fsmc_control_eccps_t::on256bytes>;

    using fsmc_status_irs = lib::regbit<0>;
    using fsmc_status_ils = lib::regbit<1>;
    using fsmc_status_ifs = lib::regbit<2>;
    using fsmc_status_iren = lib::regbit<3>;
    using fsmc_status_ilen = lib::regbit<4>;
    using fsmc_status_ifen = lib::regbit<5>;
    using fsmc_status_fempt = lib::regbit<6>;

    using fsmc_space_timing_set =
        lib::regbit<0, lib::u8, 8, 0>;
    using fsmc_space_timing_wait =
        lib::regbit<8, lib::u8, 8, 0>;
    using fsmc_space_timing_hold =
        lib::regbit<16, lib::u8, 8, 0>;
    using fsmc_space_timing_hiz =
        lib::regbit<24, lib::u8, 8, 0>;

    struct fsmc_bank23_t {
        lib::u32 control;
        lib::u32 status;
        lib::u32 com_mem_space_timing;
        lib::u32 att_mem_space_timing;
        lib::u32 _unused0;
        lib::u32 ecc_result;
    };

    struct fsmc_bank4_t {
        lib::u32 control;
        lib::u32 status;
        lib::u32 com_mem_space_timing;
        lib::u32 att_mem_space_timing;
        lib::u32 io_space_timing;
    };

    template <lib::u32 addr, typename Bank>
    struct fsmc_bank_d {
        static constexpr volatile Bank * const regs =
            reinterpret_cast<Bank *>(addr);
    };
}

#endif // FSMC_COMMON_T_HH
