#ifndef SPI_HH
#define SPI_HH

#if (defined(STM32F4XX) || defined(STM32L1XX))
#include "hal/common/spi_common_t.hh"
#else
#include "hal/spi_t.hh"
#endif

#include "hal/spi_d.hh"

#endif // SPI_HH
