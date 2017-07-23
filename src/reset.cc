#include <stdint.h>
#include "runner.hh"

/* data and bss section starts and ends */
extern uint32_t __text_end;
extern uint32_t __data_start;
extern uint32_t __data_end;
extern uint32_t __bss_start;
extern uint32_t __bss_end;

namespace isr {
    extern "C" void reset() {
        uint32_t *src;
        uint32_t *dest;

        // Setup initial values for inited data
        src = &__text_end;
        dest = &__data_start;
        if (src != dest) {
            while (dest < &__data_end) {
                *(dest++) = *(src++);
            }
        }

        // Set zeros for uninited data
        dest = &__bss_start;
        while (dest < &__bss_end) {
            *(dest++) = 0;
        }

        // Run main project code
        runner::run();
        // After run inifinity loop with wait for interrupt code
        while (true) {
            __asm__ volatile ("wfi");
        }
    }
}
