#ifndef I2C_HH
#define I2C_HH

#if (defined(STM32F4XX) || defined(STM32L1XX))
#include "hal/i2c_common_t.hh"
#else
#include "hal/i2c_t.hh"
#endif

#include "hal/i2c_d.hh"

#endif // I2C_HH 
