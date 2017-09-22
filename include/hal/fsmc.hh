#ifndef FSMC_HH
#define FSMC_HH

#if (defined(STM32F4XX) || defined(STM32L1XX))
#include "hal/common/fsmc_common_t.hh"
#else
#include "hal/fsmc_t.hh"
#endif

#include "hal/fsmc_d.hh"

#endif // FSMC_HH  
