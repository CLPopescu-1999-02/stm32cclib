#ifndef RCC_HH
#define RCC_HH
#include <stdint.h>

namespace hal {
    namespace rcc {
        struct ahb_devices_t {
            uint32_t gpioa:1;
            uint32_t gpiob:1;
            uint32_t gpioc:1;
            uint32_t gpiod:1;
            uint32_t gpioe:1;
            uint32_t gpioh:1;
            uint32_t gpiof:1;
            uint32_t gpiog:1;
            uint32_t unused0:24;
        };

        struct rcc_t {
            uint32_t cr;
            uint32_t icscr;
            uint32_t cfgr;
            uint32_t cir;
            ahb_devices_t ahb_reset;
            uint32_t apb2rstr;
            uint32_t apb1rstr;
            ahb_devices_t ahb_enable;
            uint32_t apb2enr;
            uint32_t apb1enr;
            uint32_t ahb_lpenr;
            uint32_t apb2_lpenr;
            uint32_t apb1_lpenr;
            uint32_t csr;
        };
    } // namespace Rcc
    volatile rcc::rcc_t * const rcc_r = reinterpret_cast<rcc::rcc_t *>(0x40023800);
} // namespace Hal
#endif // RCC_HH
