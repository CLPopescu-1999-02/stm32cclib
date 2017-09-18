#ifndef IWDG_HH
#define IWDG_HH

#if (defined(STM32F4XX) || defined(STM32L1XX))
#include "hal/iwdg_common_t.hh"
#else
#include "hal/iwdg_t.hh"
#endif

#include "hal/iwdg_d.hh"

#endif // IWDG_HH  
