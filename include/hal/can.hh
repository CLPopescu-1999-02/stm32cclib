#ifndef CAN_HH
#define CAN_HH

#if (defined(STM32F4XX) || defined(STM32F3XX))
#include "hal/common/can_common_t.hh"
#else
#include "hal/can_t.hh"
#endif

#include "hal/can_d.hh"

#endif // CAN_HH 
