#ifndef USART_COMMON_T_HH
#define USART_COMMON_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using usart_status_pe = lib::regbit<0>;
    using usart_status_fe = lib::regbit<1>;
    using usart_status_nf = lib::regbit<2>;
    using usart_status_ore = lib::regbit<3>;
    using usart_status_idle = lib::regbit<4>;
    using usart_status_rxne = lib::regbit<5>;
    using usart_status_tc = lib::regbit<6>;
    using usart_status_txe = lib::regbit<7>;
    using usart_status_lbd = lib::regbit<8>;
    using usart_status_cts = lib::regbit<9>;

    using usart_baudrate_fraction = lib::regbit8<0, 4>;
    using usart_baudrate_mantissa = lib::regbit16<4, 12>;

    using usart_control1_sbk = lib::regbit<0>;
    using usart_control1_rwu = lib::regbit<1>;
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
    using usart_control1_ue = lib::regbit<13>;
    using usart_control1_over8 = lib::regbit<15>;

    using usart_control2_add = lib::regbit8<0, 4>;
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

    using usart_guard_prescaler_psc = lib::regbit8<0, 8>;
    using usart_guard_prescaler_gt = lib::regbit8<8, 8>;

    template <lib::u32 addr>
    struct usart_d {
        struct usart_t {
            lib::u32 status;
            lib::u32 dr;
            lib::u32 baudrate;
            lib::u32 control1;
            lib::u32 control2;
            lib::u32 control3;
            lib::u32 guard_prescaler;
        };

        static void send_w(lib::u32 word) {
            while ((regs->status &
                usart_status_txe::clean<lib::u32>::mask) == 0);

            regs->dr = word;
        }

        static lib::u32 recv_w() {
            while ((regs->status &
                usart_status_rxne::clean<lib::u32>::mask) == 0);

            return regs->dr;
        }

        static constexpr volatile usart_t * const regs =
            reinterpret_cast<usart_t *>(addr);
    };
}

#endif // USART_COMMON_T_HH
