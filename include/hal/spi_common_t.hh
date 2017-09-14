#ifndef SPI_COMMON_T_HH
#define SPI_COMMON_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using spi_control1_cpha = lib::regbit<0>;
    using spi_control1_cpol = lib::regbit<1>;
    using spi_control1_mstr = lib::regbit<2>;
    enum struct spi_control1_br_t : lib::u8 {
        by2 = 0,
        by4 = 1,
        by8 = 2,
        by16 = 3,
        by32 = 4,
        by64 = 5,
        by128 = 6,
        by256 = 7
    };
    using spi_control1_br =
        lib::regbit<3,
            spi_control1_br_t,
            3,
            spi_control1_br_t::by2>;
    using spi_control1_spe = lib::regbit<6>;
    using spi_control1_lsbfirst = lib::regbit<7>;
    using spi_control1_ssi = lib::regbit<8>;
    using spi_control1_ssm = lib::regbit<9>;
    using spi_control1_rxonly = lib::regbit<10>;
    using spi_control1_dff = lib::regbit<11>;
    using spi_control1_crcnext = lib::regbit<12>;
    using spi_control1_crcen = lib::regbit<13>;
    using spi_control1_bidioe = lib::regbit<14>;
    using spi_control1_bidimode = lib::regbit<15>;

    using spi_control2_rxdmaen = lib::regbit<0>;
    using spi_control2_txdmaen = lib::regbit<1>;
    using spi_control2_ssoe = lib::regbit<2>;
    using spi_control2_frf = lib::regbit<4>;
    using spi_control2_errie = lib::regbit<5>;
    using spi_control2_rxneie = lib::regbit<6>;
    using spi_control2_txeie = lib::regbit<7>;

    using spi_status_rxne = lib::regbit<0>;
    using spi_status_txe = lib::regbit<1>;
    using spi_status_chside = lib::regbit<2>;
    using spi_status_udr = lib::regbit<3>;
    using spi_status_crcerr = lib::regbit<4>;
    using spi_status_modf = lib::regbit<5>;
    using spi_status_ovr = lib::regbit<6>;
    using spi_status_bsy = lib::regbit<7>;
    using spi_status_tifrfe = lib::regbit<8>;

    using spi_i2s_config_chlen = lib::regbit<0>;
    enum struct spi_i2s_config_datlen_t : lib::u8 {
        as16bit = 0b00,
        as24bit = 0b01,
        as32bit = 0b10
    };
    using spi_i2s_config_datlen =
        lib::regbit<1,
            spi_i2s_config_datlen_t,
            2,
            spi_i2s_config_datlen_t::as16bit>;
    using spi_i2s_config_ckpol = lib::regbit<3>;
    enum struct spi_i2s_config_i2sstd_t : lib::u8 {
        phillips = 0,
        msb_justified = 1,
        lsb_justified = 2,
        pcm = 3
    };
    using spi_i2s_config_i2sstd =
        lib::regbit<4,
            spi_i2s_config_i2sstd_t,
            2,
            spi_i2s_config_i2sstd_t::phillips>;
    using spi_i2s_config_pcmsync = lib::regbit<7>;
    enum struct spi_i2s_config_i2scfg_t : lib::u8 {
        slave_transmit = 0,
        slave_receive = 1,
        master_transmit = 2,
        master_receive = 3
    };
    using spi_i2s_config_i2scfg =
        lib::regbit<8,
            spi_i2s_config_i2scfg_t,
            2,
            spi_i2s_config_i2scfg_t::slave_transmit>;
    using spi_i2s_config_i2se = lib::regbit<10>;
    using spi_i2s_config_i2smod = lib::regbit<11>;

    using spi_i2s_config_prescaler_i2sdiv =
        lib::regbit<0, lib::u8, 8, 2>;
    using spi_i2s_config_prescaler_odd = lib::regbit<8>;
    using spi_i2s_config_prescaler_mckoe = lib::regbit<9>;

    template <lib::u32 addr>
    struct spi_d {
        struct spi_t {
            lib::u16 control1;
            lib::u16 _unused0;
            lib::u16 control2;
            lib::u16 _unused1;
            lib::u16 status;
            lib::u16 _unused2;
            lib::u16 dr;
            lib::u16 _unused3;
            lib::u16 crc_poly;
            lib::u16 _unused4;
            lib::u16 rx_crc;
            lib::u16 _unused5;
            lib::u16 tx_crc;
            lib::u16 _unused6;
            lib::u16 i2s_config;
            lib::u16 _unused7;
            lib::u16 i2s_prescaler;
            lib::u16 _unused8;
        };

        static void send_w(lib::u16 word) {
            while ((regs->status &
                spi_status_txe::clean<lib::u32>::mask) == 0);

            regs->dr = word;
        }

        static lib::u16 recv_w() {
            while ((regs->status &
                spi_status_rxne::clean<lib::u32>::mask) == 0);

            return regs->dr;
        }

        static bool is_busy() {
            return ((regs->status &
                spi_status_bsy::clean<lib::u32>::mask) != 0);
        }

        static constexpr volatile spi_t * const regs =
            reinterpret_cast<spi_t *>(addr);
    };
}

#endif // SPI_COMMON_T_HH
