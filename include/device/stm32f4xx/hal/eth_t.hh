#ifndef ETH_T_HH
#define ETH_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using eth_mac_config_re = lib::regbit<2>;
    using eth_mac_config_te = lib::regbit<3>;
    using eth_mac_config_dc = lib::regbit<4>;
    enum struct eth_mac_config_bl_t : lib::u8 {
        min_n_10 = 0b00,
        min_n_8,
        min_n_4,
        min_n_1
    };
    using eth_mac_config_bl =
        lib::regbit<5,
            eth_mac_config_bl_t,
            2,
            eth_mac_config_bl_t::min_n_10>;
    using eth_mac_config_apcs = lib::regbit<7>;
    using eth_mac_config_rd = lib::regbit<9>;
    using eth_mac_config_ipco = lib::regbit<10>;
    using eth_mac_config_dm = lib::regbit<11>;
    using eth_mac_config_lm = lib::regbit<12>;
    using eth_mac_config_rod = lib::regbit<13>;
    using eth_mac_config_fes = lib::regbit<14>;
    using eth_mac_config_csd = lib::regbit<16>;
    enum struct eth_mac_config_ifg_t : lib::u8 {
        bit96times = 0b000,
        bit88times,
        bit80times,
        bit72times,
        bit64times,
        bit56times,
        bit48times,
        bit40times
    };
    using eth_mac_config_ifg =
        lib::regbit<17,
            eth_mac_config_ifg_t,
            3,
            eth_mac_config_ifg_t::bit96times>;
    using eth_mac_config_jd = lib::regbit<22>;
    using eth_mac_config_wd = lib::regbit<23>;
    using eth_mac_config_cstf = lib::regbit<25>;

    using eth_mac_frame_filter_pm = lib::regbit<0>;
    using eth_mac_frame_filter_hu = lib::regbit<1>;
    using eth_mac_frame_filter_mm = lib::regbit<2>;
    using eth_mac_frame_filter_daif = lib::regbit<3>;
    using eth_mac_frame_filter_pam = lib::regbit<4>;
    using eth_mac_frame_filter_bdf = lib::regbit<5>;
    enum struct eth_mac_frame_filter_pcf_t : lib::u8 {
        all_frames = 0b00,
        expect_pause = 0b01,
        even_fail_filter = 0b10,
        pass_filter = 0b11
    };
    using eth_mac_frame_filter_pcf =
        lib::regbit<6,
            eth_mac_frame_filter_pcf_t,
            2,
            eth_mac_frame_filter_pcf_t::all_frames>;
    using eth_mac_frame_filter_saif = lib::regbit<8>;
    using eth_mac_frame_filter_saf = lib::regbit<9>;
    using eth_mac_frame_filter_hpf = lib::regbit<10>;
    using eth_mac_frame_filter_ra = lib::regbit<31>;

    using eth_mac_mii_address_mb = lib::regbit<0>;
    using eth_mac_mii_address_mw = lib::regbit<1>;
    enum struct eth_mac_mii_address_cr_t : lib::u8 {
        hclk_div_42 = 0b000,
        hclk_div_62,
        hclk_div_16,
        hclk_div_26,
        hclk_div_102
    };
    using eth_mac_mii_address_cr =
        lib::regbit<2,
            eth_mac_mii_address_cr_t,
            3,
            eth_mac_mii_address_cr_t::hclk_div_42>;
    using eth_mac_mii_address_mr = lib::regbit8<6, 5>;
    using eth_mac_mii_address_pa = lib::regbit8<11, 5>;

    using eth_mac_mii_dr_md = lib::regbit16<0, 16>;

    using eth_mac_flow_control_fcb_bpa = lib::regbit<0>;
    using eth_mac_flow_control_tfce = lib::regbit<1>;
    using eth_mac_flow_control_rfce = lib::regbit<2>;
    using eth_mac_flow_control_upfd = lib::regbit<3>;
    enum struct eth_mac_flow_control_plt_t : lib::u8 {
        minus4slot = 0b00,
        minus28slot,
        minus144slot,
        minus256slot
    };
    using eth_mac_flow_control_plt =
        lib::regbit<4,
            eth_mac_flow_control_plt_t,
            2,
            eth_mac_flow_control_plt_t::minus4slot>;
    using eth_mac_flow_control_zqpd = lib::regbit<7>;
    using eth_mac_flow_control_pt = lib::regbit16<16, 16>;

    using eth_mac_vlan_tag_id = lib::regbit16<0, 16>;
    using eth_mac_vlan_tag_12comp = lib::regbit<16>;

    using eth_mac_pmt_control_status_pd = lib::regbit<0>;
    using eth_mac_pmt_control_status_mpe = lib::regbit<1>;
    using eth_mac_pmt_control_status_wfe = lib::regbit<2>;
    using eth_mac_pmt_control_status_mpr = lib::regbit<5>;
    using eth_mac_pmt_control_status_wfr = lib::regbit<6>;
    using eth_mac_pmt_control_status_gu = lib::regbit<9>;
    using eth_mac_pmt_control_status_wffrpr = lib::regbit<31>;

    using eth_mac_debug_mmrpea = lib::regbit<0>;
    using eth_mac_debug_msfrwcs = lib::regbit8<1, 2>;
    using eth_mac_debug_rfwra = lib::regbit<4>;
    enum struct eth_mac_debug_rfrcs_t : lib::u8 {
        idle = 0b00,
        reading_frame_data,
        reading_frame_status,
        flushing_frame_data_status
    };
    using eth_mac_debug_rfrcs =
        lib::regbit<5,
            eth_mac_debug_rfrcs_t,
            2,
            eth_mac_debug_rfrcs_t::idle>;
    enum struct eth_mac_debug_rffl_t : lib::u8 {
        empty = 0b00,
        fill_level_below_flow_control,
        fill_level_above_flow_control,
        full
    };
    using eth_mac_debug_rffl =
        lib::regbit<8,
            eth_mac_debug_rffl_t,
            2,
            eth_mac_debug_rffl_t::empty>;
    using eth_mac_debug_mmtea = lib::regbit<16>;
    enum struct eth_mac_debug_mtfcs_t : lib::u8 {
        idle = 0b00,
        waiting_for_status,
        generating_transmitting_pause,
        transferring_input_frame
    };
    using eth_mac_debug_mtfcs =
        lib::regbit<17,
            eth_mac_debug_mtfcs_t,
            2,
            eth_mac_debug_mtfcs_t::idle>;
    using eth_mac_debug_mtp = lib::regbit<19>;
    enum struct eth_mac_debug_tfrs_t : lib::u8 {
        idle = 0b00,
        read_state,
        waiting_for_tx_status,
        writing_the_received_tx_status
    };
    using eth_mac_debug_tfrs =
        lib::regbit<20,
            eth_mac_debug_tfrs_t,
            2,
            eth_mac_debug_tfrs_t::idle>;
    using eth_mac_debug_tfwa = lib::regbit<22>;
    using eth_mac_debug_tfne = lib::regbit<24>;
    using eth_mac_debug_tff = lib::regbit<25>;

    using eth_mac_interrupt_pmt = lib::regbit<3>;
    using eth_mac_interrupt_mmc = lib::regbit<4>;
    using eth_mac_interrupt_mmcr = lib::regbit<5>;
    using eth_mac_interrupt_mmct = lib::regbit<6>;
    using eth_mac_interrupt_tst = lib::regbit<9>;

    using eth_mac_address_high_addr = lib::regbit16<0, 16>;
    using eth_mac_address_high_mbc = lib::regbit8<24, 6>;
    using eth_mac_address_high_sa = lib::regbit<30>;
    using eth_mac_address_high_ae = lib::regbit<31>;
    using eth_mac_address_high0_mo = lib::regbit8<31, 1, 1>;

    using eth_mmc_control_cr = lib::regbit<0>;
    using eth_mmc_control_csr = lib::regbit<1>;
    using eth_mmc_control_ror = lib::regbit<2>;
    using eth_mmc_control_mcf = lib::regbit<3>;
    using eth_mmc_control_mcp = lib::regbit<4>;
    using eth_mmc_control_mcfhp = lib::regbit<5>;

    using eth_mmc_rx_interrupt_rfce = lib::regbit<5>;
    using eth_mmc_rx_interrupt_rfae = lib::regbit<6>;
    using eth_mmc_rx_interrupt_rguf = lib::regbit<17>;

    using eth_mmc_tx_interrupt_tgfsc = lib::regbit<14>;
    using eth_mmc_tx_interrupt_tgfmsc = lib::regbit<15>;
    using eth_mmc_tx_interrupt_tgf = lib::regbit<21>;

    using eth_ptp_ts_control_tse = lib::regbit<0>;
    using eth_ptp_ts_control_tsfcu = lib::regbit<1>;
    using eth_ptp_ts_control_tssti = lib::regbit<2>;
    using eth_ptp_ts_control_tsstu = lib::regbit<3>;
    using eth_ptp_ts_control_tsite = lib::regbit<4>;
    using eth_ptp_ts_control_tsaru = lib::regbit<5>;
    using eth_ptp_ts_control_tssarfe = lib::regbit<8>;
    using eth_ptp_ts_control_tsssr = lib::regbit<9>;
    using eth_ptp_ts_control_tsptppsv2e = lib::regbit<10>;
    using eth_ptp_ts_control_tssptpoefe = lib::regbit<11>;
    using eth_ptp_ts_control_tssipv6fe = lib::regbit<12>;
    using eth_ptp_ts_control_tssipv4fe = lib::regbit<13>;
    using eth_ptp_ts_control_tsseme = lib::regbit<14>;
    using eth_ptp_ts_control_tssmrme = lib::regbit<15>;
    enum struct eth_ptp_ts_control_tscnt_t : lib::u8 {
        ordinary_clock = 0b00,
        boundary_clock,
        end_to_end_transparent_clock,
        peer_to_peer_transparent_clock
    };
    using eth_ptp_ts_control_tscnt =
        lib::regbit<16,
            eth_ptp_ts_control_tscnt_t,
            2,
            eth_ptp_ts_control_tscnt_t::ordinary_clock>;
    using eth_ptp_ts_control_tspffmae = lib::regbit<18>;

    using eth_ptp_sub_second_inc_stssi = lib::regbit8<0, 8>;

    using eth_ptp_ts_high_sts = lib::regbit32<0, 32>;
    using eth_ptp_ts_low_stss = lib::regbit32<0, 31>;
    using eth_ptp_ts_low_stpns = lib::regbit<31>;

    using eth_ptp_ts_status_tsso = lib::regbit<0>;
    using eth_ptp_ts_status_tsttr = lib::regbit<1>;

    using eth_ptp_pps_control_ppsfreq = lib::regbit8<0, 4>;

    using eth_dma_bus_mode_sr = lib::regbit<0>;
    using eth_dma_bus_mode_da = lib::regbit<1>;
    using eth_dma_bus_mode_dsl = lib::regbit8<2, 5>;
    using eth_dma_bus_mode_edfe = lib::regbit<7>;
    using eth_dma_bus_mode_pbl = lib::regbit8<8, 6>;
    using eth_dma_bus_mode_pm = lib::regbit8<14, 2>;
    using eth_dma_bus_mode_fb = lib::regbit<16>;
    using eth_dma_bus_mode_rdp = lib::regbit8<17, 6>;
    using eth_dma_bus_mode_usp = lib::regbit<23>;
    using eth_dma_bus_mode_fpm = lib::regbit<24>;
    using eth_dma_bus_mode_aab = lib::regbit<25>;
    using eth_dma_bus_mode_mb = lib::regbit<26>;

    using eth_dma_status_t = lib::regbit<0>;
    using eth_dma_status_tps = lib::regbit<1>;
    using eth_dma_status_tbu = lib::regbit<2>;
    using eth_dma_status_tjt = lib::regbit<3>;
    using eth_dma_status_ro = lib::regbit<4>;
    using eth_dma_status_tu = lib::regbit<5>;
    using eth_dma_status_r = lib::regbit<6>;
    using eth_dma_status_rbu = lib::regbit<7>;
    using eth_dma_status_rps = lib::regbit<8>;
    using eth_dma_status_rwt = lib::regbit<9>;
    using eth_dma_status_et = lib::regbit<10>;
    using eth_dma_status_fbe = lib::regbit<13>;
    using eth_dma_status_er = lib::regbit<14>;
    using eth_dma_status_ai = lib::regbit<15>;
    using eth_dma_status_ni = lib::regbit<16>;
    enum struct eth_dma_status_rp_t : lib::u8 {
        stopped = 0b000,
        running_fetching = 0b001,
        running_waiting = 0b011,
        suspended = 0b100,
        running_closing = 0b101,
        running_transfering
    };
    using eth_dma_status_rp =
        lib::regbit<17,
            eth_dma_status_rp_t,
            3,
            eth_dma_status_rp_t::stopped>;
    enum struct eth_dma_status_tp_t : lib::u8 {
        stopped = 0b000,
        running_fetching = 0b001,
        running_waiting = 0b010,
        running_reading = 0b011,
        suspended = 0b110,
        running_closing = 0b111
    };
    using eth_dma_status_tp =
        lib::regbit<20,
            eth_dma_status_tp_t,
            3,
            eth_dma_status_tp_t::stopped>;
    using eth_dma_status_eb = lib::regbit8<23, 3>;
    using eth_dma_status_mmc = lib::regbit<26>;
    using eth_dma_status_pmt = lib::regbit<28>;
    using eth_dma_status_tst = lib::regbit<29>;

    using eth_dma_op_mode_sr = lib::regbit<1>;
    using eth_dma_op_mode_osf = lib::regbit<2>;
    enum struct eth_dma_op_mode_rtc_t : lib::u8 {
        on64 = 0b00,
        on32,
        on96,
        on128
    };
    using eth_dma_op_mode_rtc =
        lib::regbit<3,
            eth_dma_op_mode_rtc_t,
            2,
            eth_dma_op_mode_rtc_t::on64>;
    using eth_dma_op_mode_fugf = lib::regbit<6>;
    using eth_dma_op_mode_fef = lib::regbit<7>;
    using eth_dma_op_mode_st = lib::regbit<13>;
    enum struct eth_dma_op_mode_ttc_t : lib::u8 {
        on64 = 0b000,
        on128,
        on192,
        on256,
        on40,
        on32,
        on24,
        on16
    };
    using eth_dma_op_mode_ttc =
        lib::regbit<14,
            eth_dma_op_mode_ttc_t,
            3,
            eth_dma_op_mode_ttc_t::on64>;
    using eth_dma_op_mode_ftf = lib::regbit<20>;
    using eth_dma_op_mode_tsf = lib::regbit<21>;
    using eth_dma_op_mode_dfrf = lib::regbit<24>;
    using eth_dma_op_mode_rsf = lib::regbit<25>;
    using eth_dma_op_mode_dtcefd = lib::regbit<26>;

    using eth_dma_miss_fr_b_ovf_counter_mfc = lib::regbit16<0, 16>;
    using eth_dma_miss_fr_b_ovf_counter_omfc = lib::regbit<16>;
    using eth_dma_miss_fr_b_ovf_counter_mfa = lib::regbit16<17, 11>;
    using eth_dma_miss_fr_b_ovf_counter_ofoc = lib::regbit<28>;

    using eth_dma_rx_status_wt_rswtc = lib::regbit8<0, 8>;

    template <lib::u32 addr>
    struct eth_d {
        struct eth_t {
            lib::u32 mac_config;
            lib::u32 mac_frame_filter;
            lib::u32 mac_hash_table_high;
            lib::u32 mac_hash_table_low;
            lib::u32 mac_mii_address;
            lib::u32 mac_mii_dr;
            lib::u32 mac_flow_control;
            lib::u32 mac_vlan_tag;
            lib::u32 _unused0[2];
            lib::u32 mac_remote_wakeup_frame_filter;
            lib::u32 mac_pmt_control_status;
            lib::u32 _unused1;
            lib::u32 mac_debug;
            lib::u32 mac_interrupt_status;
            lib::u32 mac_interrupt_mask;
            lib::u32 mac_address_high0;
            lib::u32 mac_address_low0;
            lib::u32 mac_address_high1;
            lib::u32 mac_address_low1;
            lib::u32 mac_address_high2;
            lib::u32 mac_address_low2;
            lib::u32 mac_address_high3;
            lib::u32 mac_address_low3;
            lib::u32 _unused2[40];
            lib::u32 mmc_control;
            lib::u32 mmc_rx_interrupt;
            lib::u32 mmc_tx_interrupt;
            lib::u32 mmc_rx_interrupt_mask;
            lib::u32 mmc_tx_interrupt_mask;
            lib::u32 _unused3[14];
            lib::u32 mmc_tx_gfsc_counter;
            lib::u32 mmc_tx_gfmsc_counter;
            lib::u32 _unused4[5];
            lib::u32 mmc_tx_gf_counter;
            lib::u32 _unused5[10];
            lib::u32 mmc_rx_fce_counter;
            lib::u32 mmc_rx_fae_counter;
            lib::u32 _unused6[10];
            lib::u32 mmc_rx_guf_counter;
            lib::u32 _unused7[334];
            lib::u32 ptp_ts_control;
            lib::u32 ptp_sub_second_inc;
            lib::u32 ptp_ts_high;
            lib::u32 ptp_ts_low;
            lib::u32 ptp_ts_high_update;
            lib::u32 ptp_ts_low_update;
            lib::u32 ptp_ts_append;
            lib::u32 ptp_tt_high;
            lib::u32 ptp_tt_low;
            lib::u32 _unused8;
            lib::u32 ptp_ts_status;
            lib::u32 ptp_pps_control;
            lib::u32 _unused9[564];
            lib::u32 dma_bus_mode;
            lib::u32 dma_tx_poll_demand;
            lib::u32 dma_rx_poll_demand;
            lib::u32 dma_rx_desc_list_addr;
            lib::u32 dma_tx_desc_list_addr;
            lib::u32 dma_status;
            lib::u32 dma_op_mode;
            lib::u32 dma_interrupt_enable;
            lib::u32 dma_miss_fr_b_ovf_counter;
            lib::u32 dma_rx_status_wt;
            lib::u32 _unused10[8];
            lib::u32 dma_curr_host_tx_desc;
            lib::u32 dma_curr_host_rx_desc;
            lib::u32 dma_curr_host_tx_buff_addr;
            lib::u32 dma_curr_host_rx_buff_addr;
        };

        static constexpr volatile eth_t & regs() {
            return *reinterpret_cast<eth_t *>(addr);
        }
    };
}

#endif // ETH_T_HH
