#ifndef USART_HH
#define USART_HH

#if (defined(STM32F4XX) || defined(STM32L1XX))
#include "hal/usart_common_t.hh"
#else
#include "hal/usart_t.hh"
#endif

#include "hal/usart_d.hh"

#endif // USART_HH 
