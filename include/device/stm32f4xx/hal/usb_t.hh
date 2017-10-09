#ifndef USB_T_HH
#define USB_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    namespace usb {
        namespace core_global {
            using otg_ctl_srqscs = lib::regbit<0>;
            using otg_ctl_srq = lib::regbit<1>;
            using otg_ctl_hngscs = lib::regbit<8>;
            using otg_ctl_hnprq = lib::regbit<9>;
            using otg_ctl_hshnpen = lib::regbit<10>;
            using otg_ctl_dhnpen = lib::regbit<11>;
            using otg_ctl_cidsts = lib::regbit<16>;
            using otg_ctl_dbct = lib::regbit<17>;
            using otg_ctl_asvld = lib::regbit<18>;
            using otg_ctl_bsvld = lib::regbit<19>;

            using otg_int_sedet = lib::regbit<2>;
            using otg_int_srsschg = lib::regbit<8>;
            using otg_int_hnsschg = lib::regbit<9>;
            using otg_int_hngdet = lib::regbit<17>;
            using otg_int_adtochg = lib::regbit<18>;
            using otg_int_dbcdne = lib::regbit<19>;

            using ahb_cfg_gintmsk = lib::regbit<0>;
            enum struct ahb_cfg_hbstlen_t : lib::u8 {
                single = 0b0000,
                incr = 0b0001,
                incr4 = 0b0011,
                incr8 = 0b0101,
                incr16 = 0b0111
            };
            using ahb_cfg_hbstlen =
                lib::regbit<1,
                    ahb_cfg_hbstlen_t,
                    4,
                    ahb_cfg_hbstlen_t::single>;
            using dmaen = lib::regbit<5>;
            using ahb_cfg_txfelvl = lib::regbit<7>;
            using ahb_cfg_ptxfelvl = lib::regbit<8>;

            using usb_cfg_tocal = lib::regbit8<0, 2>;
            using usb_cfg_physel = lib::regbit<6>;
            using usb_cfg_srpcat = lib::regbit<8>;
            using usb_cfg_hnpcat = lib::regbit<9>;
            using usb_cfg_trdt = lib::regbit8<10, 4>;
            using usb_cfg_phylpcs = lib::regbit<15>;
            using usb_cfg_ulpifsls = lib::regbit<17>;
            using usb_cfg_ulpiar = lib::regbit<18>;
            using usb_cfg_ulpicsm = lib::regbit<19>;
            using usb_cfg_ulpievbusd = lib::regbit<20>;
            using usb_cfg_ulpievbusi = lib::regbit<21>;
            using usb_cfg_tsdps = lib::regbit<22>;
            using usb_cfg_pcci = lib::regbit<23>;
            using usb_cfg_ptci = lib::regbit<24>;
            using usb_cfg_ulpiipd = lib::regbit<25>;
            using usb_cfg_fhmod = lib::regbit<29>;
            using usb_cfg_fdmod = lib::regbit<30>;
            using usb_cfg_ctxpkt = lib::regbit<31>;

            using rst_ctl_csrst = lib::regbit<0>;
            using rst_ctl_hsrst = lib::regbit<1>;
            using rst_ctl_fcrst = lib::regbit<2>;
            using rst_ctl_rxfflsh = lib::regbit<4>;
            using rst_ctl_txfflsh = lib::regbit<5>;
            using rst_ctl_txfnum = lib::regbit8<6, 5>;
            using rst_ctl_dmareq = lib::regbit<30>;
            using rst_ctl_ahbidl = lib::regbit<31>;

            using int_cmod = lib::regbit<0>;
            using int_mmis = lib::regbit<1>;
            using int_otgint = lib::regbit<2>;
            using int_sof = lib::regbit<3>;
            using int_rxflvl = lib::regbit<4>;
            using int_nptxfe = lib::regbit<5>;
            using int_ginakeff = lib::regbit<6>;
            using int_gonakeff = lib::regbit<7>;
            using int_esusp = lib::regbit<10>;
            using int_usbsusp = lib::regbit<11>;
            using int_usbrst = lib::regbit<12>;
            using int_enumdne = lib::regbit<13>;
            using int_isoodrp = lib::regbit<14>;
            using int_eopf = lib::regbit<15>;
            using int_iepint = lib::regbit<18>;
            using int_oepint = lib::regbit<19>;
            using int_iisoixfr = lib::regbit<20>;
            using int_ipxfr = lib::regbit<21>;
            using int_datafsusp = lib::regbit<22>;
            using int_hprtint = lib::regbit<24>;
            using int_hcint = lib::regbit<25>;
            using int_ptxfe = lib::regbit<26>;
            using int_cidschg = lib::regbit<28>;
            using int_disint = lib::regbit<29>;
            using int_srqint = lib::regbit<30>;
            using int_wkupint = lib::regbit<31>;

            using rx_sts_chnum = lib::regbit8<0, 4>;
            using rx_sts_bcnt = lib::regbit16<4, 11>;
            enum struct rx_sts_dpid_t : lib::u8 {
                data0 = 0b00,
                data1,
                data2,
                mdata
            };
            using rx_sts_dpid =
                lib::regbit<15,
                    rx_sts_dpid_t,
                    2,
                    rx_sts_dpid_t::data0>;
            enum struct rx_sts_pktsts_t : lib::u8 {
                global_out_nack = 0b0001,
                out_data_recv = 0b0010,
                out_tx_compl = 0b0011,
                in_data_recv = 0b0010,
                in_tx_compl = 0b0011,
                setup_tx_compl = 0b0100,
                setup_data_recv = 0b110,
                data_togl_err = 0b0101,
                ch_halted = 0b0111
            };
            using rx_sts_pktsts =
                lib::regbit<17,
                    rx_sts_pktsts_t,
                    4,
                    rx_sts_pktsts_t::in_data_recv>;
            using rx_sts_frnum = lib::regbit8<21, 4>;

            using rx_fsiz_rxfd = lib::regbit16<0, 16, 16>;

            using dieptxf0_hnptxfsiz_nptxfsa = lib::regbit16<0, 16>;
            using dieptxf0_hnptxfsiz_nptxfd = lib::regbit16<16, 16>;
            using dieptxf0_hnptxfsiz_tx0fsa = lib::regbit16<0, 16>;
            using dieptxf0_hnptxfsiz_tx0fd = lib::regbit16<16, 16>;

            using hnptx_sts_nptxsav = lib::regbit16<0, 16>;
            using hnptx_sts_nptqxsav = lib::regbit16<16, 8>;
            using hnptx_sts_nptxqtop = lib::regbit16<24, 7>;

            using i2cctl_rwdata = lib::regbit8<0, 8>;
            using i2cctl_regaddr = lib::regbit8<8, 8>;
            using i2cctl_addr = lib::regbit8<16, 7>;
            using i2cctl_i2cen = lib::regbit<23>;
            using i2cctl_ack = lib::regbit<24>;
            using i2cctl_i2cdevaddr = lib::regbit8<26, 2>;
            using i2cctl_i2cdatase0 = lib::regbit<28>;
            using i2cctl_rw = lib::regbit<30>;
            using i2cctl_bsydne = lib::regbit<31>;

            using ccfg_pwrdwn = lib::regbit<16>;
            using ccfg_i2cpaden = lib::regbit<17>;
            using ccfg_vbusasen = lib::regbit<18>;
            using ccfg_vbusbsen = lib::regbit<19>;
            using ccfg_sofouten = lib::regbit<20>;
            using ccfg_novbussens = lib::regbit<21>;

            using hptx_fsiz_ptxsa = lib::regbit16<0, 16>;
            using hptx_fsiz_ptxfd = lib::regbit16<16, 16>;

            using dieptxf_ineptxsa = lib::regbit16<0, 16>;
            using dieptxf_ineptxfd = lib::regbit16<16, 16>;
        }

        namespace host_mode {
            enum struct cfg_fslspcs_t : lib::u8 {
                phy_clock_48MHz = 0b01,
                phy_clock_6MHz = 0b10
            };
            using cfg_fslspcs =
                lib::regbit<0,
                    cfg_fslspcs_t,
                    2,
                    cfg_fslspcs_t::phy_clock_48MHz>;
            using cfg_fslss = lib::regbit<2>;

            using fir_frivl = lib::regbit16<0, 16>;

            using fnum_frnum = lib::regbit16<0, 16>;
            using fnum_ftrem = lib::regbit16<16, 16>;

            using ptx_sts_ptxfsavl = lib::regbit16<0, 16>;
            using ptx_sts_ptxqsav = lib::regbit8<16, 8>;
            using ptx_sts_ptxqtop = lib::regbit8<24, 8>;

            using aint = lib::regbit16<0, 16>;

            using aintmsk = lib::regbit16<0, 16>;

            using prt_pcsts = lib::regbit<0>;
            using prt_pcdet = lib::regbit<1>;
            using prt_pena = lib::regbit<2>;
            using prt_penchng = lib::regbit<3>;
            using prt_poca = lib::regbit<4>;
            using prt_pocchng = lib::regbit<5>;
            using prt_pres = lib::regbit<6>;
            using prt_psusp = lib::regbit<7>;
            using prt_prst = lib::regbit<8>;
            using prt_plsts = lib::regbit8<10, 2>;
            using prt_ppwr = lib::regbit<12>;
            enum struct prt_ptctl_t : lib::u8 {
                disabled = 0b0000,
                test_j = 0b0001,
                test_k = 0b0010,
                test_se0_nak = 0b0011,
                test_packet = 0b0100,
                test_force = 0b0101
            };
            using prt_ptctl =
                lib::regbit<13,
                    prt_ptctl_t,
                    4,
                    prt_ptctl_t::disabled>;
            enum struct prt_pspd_t : lib::u8 {
                full_speed = 0b01,
                low_speed = 0b10
            };
            using prt_pspd =
                lib::regbit<17,
                    prt_pspd_t,
                    2,
                    prt_pspd_t::full_speed>;
        }

        namespace hc {
            using cha_mpsiz = lib::regbit16<0, 11>;
            using cha_epnum = lib::regbit8<11, 4>;
            using cha_epdir = lib::regbit<15>;
            using cha_lsdev = lib::regbit<17>;
            enum struct cha_eptyp_t : lib::u8 {
                control = 0b00,
                isochronous,
                bulk,
                interrupt
            };
            using cha_eptyp =
                lib::regbit<18,
                    cha_eptyp_t,
                    2,
                    cha_eptyp_t::control>;
            using cha_mcnt = lib::regbit8<20, 2, 1>;
            using cha_dad = lib::regbit8<22, 7>;
            using cha_oddfrm = lib::regbit<29>;
            using cha_chdis = lib::regbit<30>;
            using cha_chena = lib::regbit<31>;

            using plt_prtaddr = lib::regbit8<0, 7>;
            using plt_hubaddr = lib::regbit8<7, 7>;
            enum struct plt_xactpos_t : lib::u8 {
                mid = 0b00,
                end = 0b01,
                begin = 0b10,
                all = 0b11
            };
            using plt_xactpos =
                lib::regbit<14,
                    plt_xactpos_t,
                    2,
                    plt_xactpos_t::mid>;
            using plt_complsplt = lib::regbit<16>;
            using plt_spliten = lib::regbit<31>;

            using int_xfrc = lib::regbit<0>;
            using int_chh = lib::regbit<1>;
            using int_ahberr = lib::regbit<2>;
            using int_stall = lib::regbit<3>;
            using int_nak = lib::regbit<4>;
            using int_ack = lib::regbit<5>;
            using int_nyet = lib::regbit<6>;
            using int_txerr = lib::regbit<7>;
            using int_bberr = lib::regbit<8>;
            using int_frmod = lib::regbit<9>;
            using int_dterr = lib::regbit<10>;

            using tsiz_xfrsiz = lib::regbit32<0, 19>;
            using tsiz_pkcnt = lib::regbit16<19, 10>;
            enum struct tsiz_dpid_t : lib::u8 {
                data0 = 0b00,
                data1,
                data2,
                mdata
            };
            using tsiz_dpid =
                lib::regbit<29,
                    tsiz_dpid_t,
                    2,
                    tsiz_dpid_t::data0>;
        }

        namespace device_mode {
            enum struct cfg_dspd_t : lib::u8 {
                full_speed = 0b11
            };
            using cfg_dspd =
                lib::regbit<0,
                    cfg_dspd_t,
                    2,
                    cfg_dspd_t::full_speed>;
            using cfg_nzlsohsk = lib::regbit<2>;
            using cfg_dad = lib::regbit8<4, 7>;
            enum struct cfg_pfivl_t : lib::u8 {
                on80percent,
                on85percent,
                on90percent,
                on95percent
            };
            using cfg_pfivl =
                lib::regbit<11,
                    cfg_pfivl_t,
                    2,
                    cfg_pfivl_t::on80percent>;

            using ctl_rwusig = lib::regbit<0>;
            using ctl_sdis = lib::regbit<1>;
            using ctl_ginsts = lib::regbit<2>;
            using ctl_gonsts = lib::regbit<3>;
            enum struct ctl_tctl_t : lib::u8 {
                disabled = 0b000,
                test_j = 0b001,
                test_k = 0b010,
                test_se0_nak = 0b011,
                test_packet = 0b100,
                test_force = 0b101
            };
            using ctl_tctl =
                lib::regbit<6,
                    ctl_tctl_t,
                    3,
                    ctl_tctl_t::disabled>;
            using ctl_sginak = lib::regbit<7>;
            using ctl_cginak = lib::regbit<8>;
            using ctl_sgonak = lib::regbit<9>;
            using ctl_cgonak = lib::regbit<10>;
            using ctl_poprgdne = lib::regbit<11>;

            using sts_suspsts = lib::regbit<0>;
            using sts_enumspd = lib::regbit8<1, 2, 3>;
            using sts_eerr = lib::regbit<3>;
            using sts_fnsof = lib::regbit16<8, 14>;

            using iepmsk_xfrcm = lib::regbit<0>;
            using iepmsk_epdm = lib::regbit<1>;
            using iepmsk_tom = lib::regbit<3>;
            using iepmsk_ittxfemsk = lib::regbit<4>;
            using iepmsk_inepnmm = lib::regbit<5>;
            using iepmsk_inepnem = lib::regbit<6>;
            using iepmsk_txfurm = lib::regbit<8>;
            using iepmsk_bim = lib::regbit<9>;

            using oepmsk_xfrcm = lib::regbit<0>;
            using oepmsk_epdm = lib::regbit<1>;
            using oepmsk_stupm = lib::regbit<3>;
            using oepmsk_otepdm = lib::regbit<4>;
            using oepmsk_b2bstup = lib::regbit<6>;
            using oepmsk_opem = lib::regbit<8>;
            using oepmsk_boim = lib::regbit<9>;

            using aint_iepint = lib::regbit16<0, 16>;
            using aint_oepint = lib::regbit16<16, 16>;

            using vbusdis_vbusdt = lib::regbit16<0, 16>;

            using vbuspulse_dvbusp = lib::regbit16<0, 12>;

            using thrctl_nonisothren = lib::regbit<0>;
            using thrctl_isothren = lib::regbit<1>;
            using thrctl_txthrlen = lib::regbit16<2, 9>;
            using thrctl_rxthren = lib::regbit<16>;
            using thrctl_rxthrlen = lib::regbit16<17, 9>;
            using thrctl_arpen = lib::regbit<27>;

            using iepempmsk_ineptxfem = lib::regbit16<0, 16>;

            using eachint_iep1int = lib::regbit<1>;
            using eachint_oep1int = lib::regbit<17>;

            using inep1msk_xfrcm = lib::regbit<0>;
            using inep1msk_epdm = lib::regbit<1>;
            using inep1msk_tom = lib::regbit<3>;
            using inep1msk_ittxfemsk = lib::regbit<4>;
            using inep1msk_inepnmm = lib::regbit<5>;
            using inep1msk_inepnem = lib::regbit<6>;
            using inep1msk_txfurm = lib::regbit<8>;
            using inep1msk_bim = lib::regbit<9>;
            using inep1msk_nakm = lib::regbit<13>;

            using outep1msk_xfrcm = lib::regbit<0>;
            using outep1msk_epdm = lib::regbit<1>;
            using outep1msk_ahberrm = lib::regbit<2>;
            using outep1msk_opem = lib::regbit<8>;
            using outep1msk_bim = lib::regbit<9>;
            using outep1msk_berrm = lib::regbit<12>;
            using outep1msk_nakm = lib::regbit<13>;
            using outep1msk_nyetm = lib::regbit<14>;
        }

        namespace iep {
            enum struct ctl0_mpsiz_t : lib::u8 {
                on64bytes = 0b00,
                on32bytes,
                on16bytes,
                on8bytes
            };
            using ctl0_mpsiz =
                lib::regbit<0,
                    ctl0_mpsiz_t,
                    2,
                    ctl0_mpsiz_t::on64bytes>;
            using ctl0_usbaep = lib::regbit<15>;
            using ctl0_naksts = lib::regbit<17>;
            using ctl0_eptyp = lib::regbit8<18, 2, 0b00>;
            using ctl0_stall = lib::regbit<21>;
            using ctl0_txfnum = lib::regbit8<22, 4>;
            using ctl0_cnak = lib::regbit<26>;
            using ctl0_snak = lib::regbit<27>;
            using ctl0_epdis = lib::regbit<30>;
            using ctl0_epena = lib::regbit<31>;

            using ctl_mpsiz = lib::regbit16<0, 11>;
            using ctl_usbaep = lib::regbit<15>;
            using ctl_eonum = lib::regbit<16>;
            using ctl_naksts = lib::regbit<17>;
            enum struct ctl_etyp_t : lib::u8 {
                control = 0b00,
                isochronous,
                bulk,
                interrupt
            };
            using ctl_eptyp =
                lib::regbit<18,
                    ctl_etyp_t,
                    2,
                    ctl_etyp_t::control>;
            using ctl_stall = lib::regbit<21>;
            using ctl_txfnum = lib::regbit8<22, 4>;
            using ctl_cnak = lib::regbit<26>;
            using ctl_snak = lib::regbit<27>;
            using ctl_sd0pid_sevnfrm = lib::regbit<28>;
            using ctl_soddfrm = lib::regbit<29>;
            using ctl_epdis = lib::regbit<30>;
            using ctl_epena = lib::regbit<31>;

            using int_xfrc = lib::regbit<0>;
            using int_epdisd = lib::regbit<1>;
            using int_toc = lib::regbit<3>;
            using int_ittxfe = lib::regbit<4>;
            using int_inepne = lib::regbit<6>;
            using int_txfe = lib::regbit<7>;

            using tsiz0_xfrsiz = lib::regbit8<0, 7>;
            using tsiz0_pktcnt = lib::regbit8<19, 2>;

            using tsiz_xfrsiz = lib::regbit16<0, 19>;
            using tsiz_pkcnt = lib::regbit16<19, 10>;
            using tsiz_mcnt = lib::regbit8<29, 2>;

            using tx_fsts_ineptfsav = lib::regbit16<0, 16>;
        }

        namespace oep {
            enum struct ctl0_mpsiz_t : lib::u8 {
                on64bytes = 0b00,
                on32bytes,
                on16bytes,
                on8bytes
            };
            using ctl0_mpsiz =
                lib::regbit<0,
                    ctl0_mpsiz_t,
                    2,
                    ctl0_mpsiz_t::on64bytes>;
            using ctl0_usbaep = lib::regbit<15>;
            using ctl0_naksts = lib::regbit<17>;
            using ctl0_eptyp = lib::regbit8<18, 2, 0b00>;
            using ctl0_snpm = lib::regbit<20>;
            using ctl0_stall = lib::regbit<21>;
            using ctl0_txfnum = lib::regbit8<22, 4>;
            using ctl0_cnak = lib::regbit<26>;
            using ctl0_snak = lib::regbit<27>;
            using ctl0_epdis = lib::regbit<30>;
            using ctl0_epena = lib::regbit<31>;

            using ctl_mpsiz = lib::regbit16<0, 11>;
            using ctl_usbaep = lib::regbit<15>;
            using ctl_eonum = lib::regbit<16>;
            using ctl_naksts = lib::regbit<17>;
            enum struct ctl_etyp_t : lib::u8 {
                control = 0b00,
                isochronous,
                bulk,
                interrupt
            };
            using ctl_eptyp =
                lib::regbit<18,
                    ctl_etyp_t,
                    2,
                    ctl_etyp_t::control>;
            using ctl_snpm = lib::regbit<20>;
            using ctl_stall = lib::regbit<21>;
            using ctl_txfnum = lib::regbit8<22, 4>;
            using ctl_cnak = lib::regbit<26>;
            using ctl_snak = lib::regbit<27>;
            using ctl_sd0pid_sevnfrm = lib::regbit<28>;
            using ctl_sd1pid_soddfrm = lib::regbit<29>;
            using ctl_epdis = lib::regbit<30>;
            using ctl_epena = lib::regbit<31>;

            using int_xfrc = lib::regbit<0>;
            using int_epdisd = lib::regbit<1>;
            using int_stup = lib::regbit<3>;
            using int_otepdis = lib::regbit<4>;
            using int_b2bstup = lib::regbit<6>;

            using tsiz0_xfrsiz = lib::regbit8<0, 7>;
            using tsiz0_pktcnt = lib::regbit<19>;
            using tsiz0_stupcnt = lib::regbit8<29, 2>;

            using tsiz_xfrsiz = lib::regbit16<0, 19>;
            using tsiz_pkcnt = lib::regbit16<19, 10>;
            enum struct tsiz_rxdpid_t : lib::u8 {
                data0 = 0b00,
                data1,
                data2,
                mdata
            };
            using tsiz_rxdpid =
                lib::regbit<29,
                    tsiz_rxdpid_t,
                    2,
                    tsiz_rxdpid_t::data0>;
        }

        namespace power_clock_gating {
            using ctl_stppclk = lib::regbit<0>;
            using ctl_gatehclk = lib::regbit<1>;
            using ctl_physusp = lib::regbit<4>;
        }
    }

    template <lib::u32 addr>
    struct usb_d {
        struct core_global_t {
            lib::u32 otg_ctl;
            lib::u32 otg_int;
            lib::u32 ahb_cfg;
            lib::u32 usb_cfg;
            lib::u32 rst_ctl;
            lib::u32 int_sts;
            lib::u32 int_msk;
            lib::u32 rx_stsr;
            lib::u32 rx_stsp;
            lib::u32 rx_fsiz;
            lib::u32 dieptxf0_hnptxfsiz;
            lib::u32 hnptx_sts;
            lib::u32 i2cctl;
            lib::u32 _unused0;
            lib::u32 ccfg;
            lib::u32 cid;
            lib::u32 _unused1[48];
            lib::u32 hptx_fsiz;
            lib::u32 dieptxf[5];
        };

        struct host_mode_t {
            lib::u32 cfg;
            lib::u32 fir;
            lib::u32 fnum;
            lib::u32 _unused0;
            lib::u32 ptx_sts;
            lib::u32 aint;
            lib::u32 aintmsk;
            lib::u32 _unused1[9];
            lib::u32 prt;
        };

        struct device_mode_t {
            lib::u32 cfg;
            lib::u32 ctl;
            lib::u32 sts;
            lib::u32 _unused0;
            lib::u32 iepmsk;
            lib::u32 oepmsk;
            lib::u32 aint;
            lib::u32 aintmsk;
            lib::u32 _unused1;
            lib::u32 _unused2;
            lib::u32 vbusdis;
            lib::u32 vbuspulse;
            lib::u32 thrctl;
            lib::u32 iepempmsk;
            lib::u32 eachint;
            lib::u32 eachmsk;
            lib::u32 _unused3;
            lib::u32 inep1msk;
            lib::u32 _unused4[15];
            lib::u32 outep1msk;
        };

        struct power_clock_gating_t {
            lib::u32 ctl;
        };

        struct iep_t {
            lib::u32 ctl;
            lib::u32 _unused0;
            lib::u32 intr;
            lib::u32 _unused1;
            lib::u32 tsiz;
            lib::u32 dma;
            lib::u32 tx_fsts;
            lib::u32 _unused2;
        };

        struct oep_t {
            lib::u32 ctl;
            lib::u32 frm;
            lib::u32 intr;
            lib::u32 _unused0;
            lib::u32 tsiz;
            lib::u32 dma;
            lib::u32 _unused1[2];
        };

        struct hc_t {
            lib::u32 cha;
            lib::u32 plt;
            lib::u32 intr;
            lib::u32 intmsk;
            lib::u32 tsiz;
            lib::u32 dma;
            lib::u32 _unused0[2];
        };

        static constexpr volatile core_global_t * const 
            core_global_regs =
            reinterpret_cast<core_global_t *>(addr);

        static constexpr volatile host_mode_t * const 
            host_mode_regs =
            reinterpret_cast<host_mode_t *>(addr + 0x400);

        static constexpr volatile device_mode_t * const 
            device_mode_regs =
            reinterpret_cast<device_mode_t *>(addr + 0x800);

        static constexpr volatile power_clock_gating_t * const 
            power_clock_gating_regs =
            reinterpret_cast<power_clock_gating_t *>(addr + 0xe00);

        static constexpr volatile iep_t * const 
            iep0_regs =
            reinterpret_cast<iep_t *>(addr + 0x900);

        static constexpr volatile iep_t * const 
            iep1_regs =
            reinterpret_cast<iep_t *>(addr + 0x900 + 0x20);

        static constexpr volatile iep_t * const 
            iep2_regs =
            reinterpret_cast<iep_t *>(addr + 0x900 + 0x20 * 2);

        static constexpr volatile iep_t * const 
            iep3_regs =
            reinterpret_cast<iep_t *>(addr + 0x900 + 0x20 * 3);

        static constexpr volatile iep_t * const 
            iep4_regs =
            reinterpret_cast<iep_t *>(addr + 0x900 + 0x20 * 4);

        static constexpr volatile oep_t * const 
            oep0_regs =
            reinterpret_cast<oep_t *>(addr + 0xb00);

        static constexpr volatile oep_t * const 
            oep1_regs =
            reinterpret_cast<oep_t *>(addr + 0xb00 + 0x20);

        static constexpr volatile oep_t * const 
            oep2_regs =
            reinterpret_cast<oep_t *>(addr + 0xb00 + 0x20 * 2);

        static constexpr volatile oep_t * const 
            oep3_regs =
            reinterpret_cast<oep_t *>(addr + 0xb00 + 0x20 * 3);

        static constexpr volatile oep_t * const 
            oep4_regs =
            reinterpret_cast<oep_t *>(addr + 0xb00 + 0x20 * 4);

        static constexpr volatile hc_t * const 
            hc0_regs =
            reinterpret_cast<hc_t *>(addr + 0x500);

        static constexpr volatile hc_t * const 
            hc1_regs =
            reinterpret_cast<hc_t *>(addr + 0x500 + 0x20);

        static constexpr volatile hc_t * const 
            hc2_regs =
            reinterpret_cast<hc_t *>(addr + 0x500 + 0x20 * 2);

        static constexpr volatile hc_t * const 
            hc3_regs =
            reinterpret_cast<hc_t *>(addr + 0x500 + 0x20 * 3);

        static constexpr volatile hc_t * const 
            hc4_regs =
            reinterpret_cast<hc_t *>(addr + 0x500 + 0x20 * 4);

        static constexpr volatile hc_t * const 
            hc5_regs =
            reinterpret_cast<hc_t *>(addr + 0x500 + 0x20 * 5);

        static constexpr volatile hc_t * const 
            hc6_regs =
            reinterpret_cast<hc_t *>(addr + 0x500 + 0x20 * 6);

        static constexpr volatile hc_t * const 
            hc7_regs =
            reinterpret_cast<hc_t *>(addr + 0x500 + 0x20 * 7);

        static constexpr volatile hc_t * const 
            hc8_regs =
            reinterpret_cast<hc_t *>(addr + 0x500 + 0x20 * 8);

        static constexpr volatile hc_t * const 
            hc9_regs =
            reinterpret_cast<hc_t *>(addr + 0x500 + 0x20 * 9);

        static constexpr volatile hc_t * const 
            hc10_regs =
            reinterpret_cast<hc_t *>(addr + 0x500 + 0x20 * 10);

        static constexpr volatile hc_t * const 
            hc11_regs =
            reinterpret_cast<hc_t *>(addr + 0x500 + 0x20 * 11);

        static constexpr volatile lib::u8 * const
            fifo0 =
            reinterpret_cast<lib::u8 *>(addr + 0x1000);

        static constexpr volatile lib::u8 * const
            fifo1 =
            reinterpret_cast<lib::u8 *>(addr + 0x1000 + 0x1000);

        static constexpr volatile lib::u8 * const
            fifo2 =
            reinterpret_cast<lib::u8 *>(addr + 0x1000 + 0x1000 * 2);

        static constexpr volatile lib::u8 * const
            fifo3 =
            reinterpret_cast<lib::u8 *>(addr + 0x1000 + 0x1000 * 3);

        static constexpr volatile lib::u8 * const
            fifo4 =
            reinterpret_cast<lib::u8 *>(addr + 0x1000 + 0x1000 * 4);

        static constexpr volatile lib::u8 * const
            fifo5 =
            reinterpret_cast<lib::u8 *>(addr + 0x1000 + 0x1000 * 5);

        static constexpr volatile lib::u8 * const
            fifo6 =
            reinterpret_cast<lib::u8 *>(addr + 0x1000 + 0x1000 * 6);

        static constexpr volatile lib::u8 * const
            fifo7 =
            reinterpret_cast<lib::u8 *>(addr + 0x1000 + 0x1000 * 7);

        static constexpr volatile lib::u8 * const
            fifo8 =
            reinterpret_cast<lib::u8 *>(addr + 0x1000 + 0x1000 * 8);

        static constexpr volatile lib::u8 * const
            fifo9 =
            reinterpret_cast<lib::u8 *>(addr + 0x1000 + 0x1000 * 9);

        static constexpr volatile lib::u8 * const
            fifo10 =
            reinterpret_cast<lib::u8 *>(addr + 0x1000 + 0x1000 * 10);

        static constexpr volatile lib::u8 * const
            fifo11 =
            reinterpret_cast<lib::u8 *>(addr + 0x1000 + 0x1000 * 11);

        static constexpr volatile lib::u8 * const
            debug_fifo =
            reinterpret_cast<lib::u8 *>(addr + 0x20000);
    };
}

#endif // USB_T_HH
