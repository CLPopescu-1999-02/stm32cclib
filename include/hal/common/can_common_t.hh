#ifndef CAN_COMMON_T_HH
#define CAN_COMMON_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using can_mailbox_id_txrq = lib::regbit<0>;
    using can_mailbox_id_rtr = lib::regbit<1>;
    using can_mailbox_id_ide = lib::regbit<2>;
    using can_mailbox_id_exid = lib::regbit32<3, 29>;
    using can_mailbox_id_stid = lib::regbit16<21, 11>;

    using can_mailbox_data_len_dlc = lib::regbit8<0, 4>;
    using can_mailbox_data_len_tgt = lib::regbit<8>;
    using can_mailbox_data_len_time = lib::regbit16<16, 16>;

    using can_mailbox_data0 = lib::regbit8<0, 8>;
    using can_mailbox_data1 = lib::regbit8<8, 8>;
    using can_mailbox_data2 = lib::regbit8<16, 8>;
    using can_mailbox_data3 = lib::regbit8<24, 8>;

    using can_mailbox_data4 = lib::regbit8<0, 8>;
    using can_mailbox_data5 = lib::regbit8<8, 8>;
    using can_mailbox_data6 = lib::regbit8<16, 8>;
    using can_mailbox_data7 = lib::regbit8<24, 8>;

    struct can_tx_mailbox_t {
        lib::u32 mailbox_id;
        lib::u32 mailbox_data_len;
        lib::u32 mailbox_data_low;
        lib::u32 mailbox_data_high;
    };

    using can_mailbox_data_len_fmi = lib::regbit8<8, 8>;

    struct can_fifo_mailbox_t {
        lib::u32 mailbox_id;
        lib::u32 mailbox_data_len;
        lib::u32 mailbox_data_low;
        lib::u32 mailbox_data_high;
    };

    struct can_filter_register_t {
        lib::u32 r1;
        lib::u32 r2;
    };

    using can_master_control_inrq = lib::regbit<0>;
    using can_master_control_sleep = lib::regbit<1>;
    using can_master_control_txfp = lib::regbit<2>;
    using can_master_control_rflm = lib::regbit<3>;
    using can_master_control_nart = lib::regbit<4>;
    using can_master_control_awum = lib::regbit<5>;
    using can_master_control_abom = lib::regbit<6>;
    using can_master_control_ttcm = lib::regbit<7>;
    using can_master_control_reset = lib::regbit<15>;
    using can_master_control_dbf = lib::regbit<16>;

    using can_master_status_inak = lib::regbit<0>;
    using can_master_status_slak = lib::regbit<1>;
    using can_master_status_erri = lib::regbit<2>;
    using can_master_status_wkui = lib::regbit<3>;
    using can_master_status_slaki = lib::regbit<4>;
    using can_master_status_txm = lib::regbit<8>;
    using can_master_status_rxm = lib::regbit<9>;
    using can_master_status_samp = lib::regbit<10>;
    using can_master_status_rx = lib::regbit<11>;

    using can_tx_status_rqcp0 = lib::regbit<0>;
    using can_tx_status_txok0 = lib::regbit<1>;
    using can_tx_status_alst0 = lib::regbit<2>;
    using can_tx_status_terr0 = lib::regbit<3>;
    using can_tx_status_abrq0 = lib::regbit<7>;
    using can_tx_status_rqcp1 = lib::regbit<8>;
    using can_tx_status_txok1 = lib::regbit<9>;
    using can_tx_status_alst1 = lib::regbit<10>;
    using can_tx_status_terr1 = lib::regbit<11>;
    using can_tx_status_abrq1 = lib::regbit<15>;
    using can_tx_status_rqcp2 = lib::regbit<16>;
    using can_tx_status_txok2 = lib::regbit<17>;
    using can_tx_status_alst2 = lib::regbit<18>;
    using can_tx_status_terr2 = lib::regbit<19>;
    using can_tx_status_abrq2 = lib::regbit<23>;
    using can_tx_status_code = lib::regbit8<24, 2>;
    using can_tx_status_tme0 = lib::regbit<26>;
    using can_tx_status_tme1 = lib::regbit<27>;
    using can_tx_status_tme2 = lib::regbit<28>;
    using can_tx_status_low0 = lib::regbit<29>;
    using can_tx_status_low1 = lib::regbit<30>;
    using can_tx_status_low2 = lib::regbit<31>;

    using can_rx_fifo_fmp = lib::regbit8<0, 2>;
    using can_rx_fifo_full = lib::regbit<3>;
    using can_rx_fifo_fovr = lib::regbit<4>;
    using can_rx_fifo_rfom = lib::regbit<5>;

    using can_int_enable_tmeie = lib::regbit<0>;
    using can_int_enable_fmpie0 = lib::regbit<1>;
    using can_int_enable_ffie0 = lib::regbit<2>;
    using can_int_enable_fovie0 = lib::regbit<3>;
    using can_int_enable_fmpie1 = lib::regbit<4>;
    using can_int_enable_ffie1 = lib::regbit<5>;
    using can_int_enable_fovie1 = lib::regbit<6>;
    using can_int_enable_ewgie = lib::regbit<8>;
    using can_int_enable_epvie = lib::regbit<9>;
    using can_int_enable_bofie = lib::regbit<10>;
    using can_int_enable_lecie = lib::regbit<11>;
    using can_int_enable_errie = lib::regbit<15>;
    using can_int_enable_wkuie = lib::regbit<16>;
    using can_int_enable_slkie = lib::regbit<17>;

    using can_error_status_ewgf = lib::regbit<0>;
    using can_error_status_epvf = lib::regbit<1>;
    using can_error_status_boff = lib::regbit<2>;
    enum struct can_error_status_lec_t : lib::u8 {
        no_error = 0,
        stuff_error,
        form_error,
        ack_error,
        bit_rec_error,
        bit_dom_error,
        crc_error,
        set_by_software
    };
    using can_error_status_lec =
        lib::regbit<4,
            can_error_status_lec_t,
            3,
            can_error_status_lec_t::no_error>;
    using can_error_status_tec = lib::regbit8<16, 8>;
    using can_error_status_rec = lib::regbit8<24, 8>;

    using can_bit_timing_brp = lib::regbit16<0, 10>;
    using can_bit_timing_ts1 = lib::regbit8<16, 3>;
    using can_bit_timing_ts2 = lib::regbit8<20, 3>;
    using can_bit_timing_sjw = lib::regbit8<24, 2>;
    using can_bit_timing_lbkm = lib::regbit<30>;
    using can_bit_timing_silm = lib::regbit<31>;

    using can_filter_master_finit = lib::regbit<0>;
    using can_filter_master_can2sb = lib::regbit8<8, 6>;

    using can_filter_b0 = lib::regbit<0>;
    using can_filter_b1 = lib::regbit<1>;
    using can_filter_b2 = lib::regbit<2>;
    using can_filter_b3 = lib::regbit<3>;
    using can_filter_b4 = lib::regbit<4>;
    using can_filter_b5 = lib::regbit<5>;
    using can_filter_b6 = lib::regbit<6>;
    using can_filter_b7 = lib::regbit<7>;
    using can_filter_b8 = lib::regbit<8>;
    using can_filter_b9 = lib::regbit<9>;
    using can_filter_b10 = lib::regbit<10>;
    using can_filter_b11 = lib::regbit<11>;
    using can_filter_b12 = lib::regbit<12>;
    using can_filter_b13 = lib::regbit<13>;
    using can_filter_b14 = lib::regbit<14>;
    using can_filter_b15 = lib::regbit<15>;
    using can_filter_b16 = lib::regbit<16>;
    using can_filter_b17 = lib::regbit<17>;
    using can_filter_b18 = lib::regbit<18>;
    using can_filter_b19 = lib::regbit<19>;
    using can_filter_b20 = lib::regbit<20>;
    using can_filter_b21 = lib::regbit<21>;
    using can_filter_b22 = lib::regbit<22>;
    using can_filter_b23 = lib::regbit<23>;
    using can_filter_b24 = lib::regbit<24>;
    using can_filter_b25 = lib::regbit<25>;
    using can_filter_b26 = lib::regbit<26>;
    using can_filter_b27 = lib::regbit<27>;
    using can_filter_b28 = lib::regbit<28>;
    using can_filter_b29 = lib::regbit<29>;
    using can_filter_b30 = lib::regbit<30>;
    using can_filter_b31 = lib::regbit<31>;

    template <lib::u32 addr>
    struct can_d {
        struct can_t {
            lib::u32 master_control;
            lib::u32 master_status;
            lib::u32 tx_status;
            lib::u32 rx_fifo0;
            lib::u32 rx_fifo1;
            lib::u32 int_enable;
            lib::u32 error_status;
            lib::u32 bit_timing;
            lib::u32 _unused0[88];
            can_tx_mailbox_t tx_mailbox[3];
            can_fifo_mailbox_t fifo_mailbox[2];
            lib::u32 _unused1[12];
            lib::u32 filter_master;
            lib::u32 filter_mode;
            lib::u32 _unused2;
            lib::u32 filter_scale;
            lib::u32 _unused3;
            lib::u32 filter_assgnment;
            lib::u32 _unused4;
            lib::u32 filter_activation;
            lib::u32 _unused5[8];
            can_filter_register_t filter_register[28];
        };

        static constexpr volatile can_t * const regs =
            reinterpret_cast<can_t *>(addr);
    };
}

#endif // CAN_COMMON_T_HH 
