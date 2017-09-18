#ifndef CRC_HH
#define CRC_HH

#if (defined(STM32F4XX) || defined(STM32L1XX))
#include "hal/crc_common_t.hh"
#else
#include "hal/crc_t.hh"
#endif

#include "hal/crc_d.hh"

#endif // CRC_HH  
