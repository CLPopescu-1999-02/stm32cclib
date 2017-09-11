#ifndef SPI_D_HH
#define SPI_D_HH

namespace hal {
    using spi1 = spi_d<0x40013000>;

    using i2s2ext = spi_d<0x40003400>;
    using spi2 = spi_d<0x40003800>;

    using spi3 = spi_d<0x40003c00>;
    using i2s3ext = spi_d<0x40004000>;
}

#endif // SPI_D_HH
