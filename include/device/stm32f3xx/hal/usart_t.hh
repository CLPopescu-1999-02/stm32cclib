#ifndef USART_T_HH
#define USART_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using usart_control1_ue = lib::regbit<0>;
    using usart_control1_uesm = lib::regbit<1>;
    using usart_control1_re = lib::regbit<2>;
    using usart_control1_te = lib::regbit<3>;
    using usart_control1_idleie = lib::regbit<4>;
    using usart_control1_rxneie = lib::regbit<5>;
    using usart_control1_tcie = lib::regbit<6>;
    using usart_control1_txeie = lib::regbit<7>;
    using usart_control1_peie = lib::regbit<8>;
    using usart_control1_ps = lib::regbit<9>;
    using usart_control1_pce = lib::regbit<10>;
    using usart_control1_wake = lib::regbit<11>;
    using usart_control1_m = lib::regbit<12>;
    using usart_control1_mme = lib::regbit<13>;
    using usart_control1_cmie = lib::regbit<14>;
    using usart_control1_over8 = lib::regbit<15>;
    using usart_control1_dedt = lib::regbit<16, lib::u8, 5, 0>;
    using usart_control1_deat = lib::regbit<21, lib::u8, 5, 0>;
    using usart_control1_rtoie = lib::regbit<26>;
    using usart_control1_eobie = lib::regbit<27>;

    using usart_control2_addm7 = lib::regbit<4>;
    using usart_control2_lbdl = lib::regbit<5>;
    using usart_control2_lbdie = lib::regbit<6>;
    using usart_control2_lbcl = lib::regbit<8>;
    using usart_control2_cpha = lib::regbit<9>;
    using usart_control2_cpol = lib::regbit<10>;
    using usart_control2_clken = lib::regbit<11>;
    enum struct usart_control2_stop_t : lib::u8 {
        b1 = 0b00,
        b0_5 = 0b01,
        b2 = 0b10,
        b1_5 = 0b11
    };
    using usart_control2_stop =
        lib::regbit<12,
            usart_control2_stop_t,
            2,
            usart_control2_stop_t::b1>;
    using usart_control2_linen = lib::regbit<14>;
    using usart_control2_swap = lib::regbit<15>;
    using usart_control2_rxinv = lib::regbit<16>;
    using usart_control2_txinv = lib::regbit<17>;
    using usart_control2_datainv = lib::regbit<18>;
    using usart_control2_msbfirst = lib::regbit<19>;
    using usart_control2_abren = lib::regbit<20>;
    enum struct usart_control2_abrmod_t : lib::u8 {
        start_bit = 0b00,
        faling_edge = 0b01,
        x7f_frame = 0b10,
        x55_frame = 0b11
    };
    using usart_control2_abrmod =
        lib::regbit<21,
            usart_control2_abrmod_t,
            2,
            usart_control2_abrmod_t::start_bit>;
    using usart_control2_rtoen = lib::regbit<23>;
    using usart_control2_add = lib::regbit<24, lib::u8, 4, 0>;
    using usart_control2_add8 = lib::regbit<24, lib::u8, 8, 0>;

    using usart_control3_eie = lib::regbit<0>;
    using usart_control3_iren = lib::regbit<1>;
    using usart_control3_irlp = lib::regbit<2>;
    using usart_control3_hdsel = lib::regbit<3>;
    using usart_control3_nack = lib::regbit<4>;
    using usart_control3_scen = lib::regbit<5>;
    using usart_control3_dmar = lib::regbit<6>;
    using usart_control3_dmat = lib::regbit<7>;
    using usart_control3_rtse = lib::regbit<8>;
    using usart_control3_ctse = lib::regbit<9>;
    using usart_control3_ctsie = lib::regbit<10>;
    using usart_control3_onebit = lib::regbit<11>;
    using usart_control3_onedis = lib::regbit<12>;
    using usart_control3_ddre = lib::regbit<13>;
    using usart_control3_dem = lib::regbit<14>;
    using usart_control3_dep = lib::regbit<15>;
    using usart_control3_scarcnt = lib::regbit<17, lib::u8, 3, 0>;
    enum struct usart_control3_wus_t : lib::u8 {
        address_match = 0b00,
        start_bit = 0b10,
        rxne = 0b11
    };
    using usart_control3_wus =
        lib::regbit<20,
            usart_control3_wus_t,
            2,
            usart_control3_wus_t::address_match>;
    using usart_control3_wufie = lib::regbit<22>;

    using usart_baudrate_fraction = lib::regbit<0, lib::u8, 4, 0>;
    using usart_baudrate_mantissa = lib::regbit<4, lib::u16, 12, 0>;

    using usart_guard_prescaler_psc = lib::regbit<0, lib::u8, 8, 0>;
    using usart_guard_prescaler_gt = lib::regbit<8, lib::u8, 8, 0>;

    using usart_receiver_timeout_rto = lib::regbit<0, lib::u32, 24, 0>;
    using usart_receiver_timeout_blen = lib::regbit<24, lib::u8, 8, 0>;

    using usart_request_abrrq = lib::regbit<0>;
    using usart_request_sbkrq = lib::regbit<1>;
    using usart_request_mmrq = lib::regbit<2>;
    using usart_request_rxfrq = lib::regbit<3>;
    using usart_request_txfrq = lib::regbit<4>;

    using usart_status_pe = lib::regbit<0>;
    using usart_status_fe = lib::regbit<1>;
    using usart_status_nf = lib::regbit<2>;
    using usart_status_ore = lib::regbit<3>;
    using usart_status_idle = lib::regbit<4>;
    using usart_status_rxne = lib::regbit<5>;
    using usart_status_tc = lib::regbit<6>;
    using usart_status_txe = lib::regbit<7>;
    using usart_status_lbdf = lib::regbit<8>;
    using usart_status_ctsif = lib::regbit<9>;
    using usart_status_cts = lib::regbit<10>;
    using usart_status_rtof = lib::regbit<11>;
    using usart_status_eobf = lib::regbit<12>;
    using usart_status_abre = lib::regbit<14>;
    using usart_status_abrf = lib::regbit<15>;
    using usart_status_busy = lib::regbit<16>;
    using usart_status_cmf = lib::regbit<17>;
    using usart_status_sbkf = lib::regbit<18>;
    using usart_status_rwu = lib::regbit<19>;
    using usart_status_wuf = lib::regbit<20>;
    using usart_status_teack = lib::regbit<21>;
    using usart_status_reack = lib::regbit<22>;

    template <lib::u32 addr>
    struct usart_d {
        struct usart_t {
            lib::u32 control1;
            lib::u32 control2;
            lib::u32 control3;
            lib::u32 baudrate;
            lib::u32 guard_prescaler;
            lib::u32 receiver_timeout;
            lib::u32 request;
            lib::u32 status;
            lib::u32 clear;
            lib::u32 rdr;
            lib::u32 tdr;
        };

        static void send_w(lib::u32 word) {
            while ((regs->status &
                usart_status_txe::clean<lib::u32>::mask) == 0);

            regs->tdr = word;
        }

        static lib::u32 recv_w() {
            while ((regs->status &
                usart_status_rxne::clean<lib::u32>::mask) == 0);

            return regs->rdr;
        }

        static constexpr volatile usart_t * const regs =
            reinterpret_cast<usart_t *>(addr);
    };
}

#endif // USART_T_HH
