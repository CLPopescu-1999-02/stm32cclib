#ifndef SPI_T_HH
#define SPI_T_HH

#include "hal/spi_common_t.hh"

namespace hal {
    using spi_control1_crcl = lib::regbit<11>;

    enum struct spi_control2_ds_t : lib::u8 {
        as4bit = 3,
        as5bit = 4,
        as6bit,
        as7bit,
        as8bit,
        as9bit,
        as10bit,
        as11bit,
        as12bit,
        as13bit,
        as14bit,
        as15bit,
        as16bit
    };
    using spi_control2_ds =
        lib::regbit<8,
            spi_control2_ds_t,
            4,
            spi_control2_ds_t::as8bit>;
    using spi_control2_frxth = lib::regbit<12>;
    using spi_control2_ldma_rx = lib::regbit<13>;
    using spi_control2_ldma_tx = lib::regbit<14>;

    enum struct spi_status_fifo_t : lib::u8 {
        empty = 0,
        quarter,
        half,
        full
    };
    using spi_status_frlvl =
        lib::regbit<9,
            spi_status_fifo_t,
            2,
            spi_status_fifo_t::empty>;
    using spi_status_ftlvl =
        lib::regbit<11,
            spi_status_fifo_t,
            2,
            spi_status_fifo_t::empty>;
}

#endif // SPI_T_HH
