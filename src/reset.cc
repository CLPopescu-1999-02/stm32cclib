#include <stdint.h>

#include "isr_base.hh"
#include "runner.hh"

namespace {
    /* data and bss section starts and ends */
    extern "C" uint32_t __text_end;
    extern "C" uint32_t __data_start;
    extern "C" uint32_t __data_end;
    extern "C" uint32_t __bss_start;
    extern "C" uint32_t __bss_end;
    /* constructors */
    using ctor = void();

    extern "C" ctor *__ctors_begin[];
    extern "C" ctor *__ctors_end[];
    extern "C" ctor *__preinit_array_start[];
    extern "C" ctor *__preinit_array_end[];
    extern "C" ctor *__init_array_start[];
    extern "C" ctor *__init_array_end[];

    extern "C" void * memcpy(void *dest, const void *src, uint32_t num) {
        uint8_t *pdst = static_cast<uint8_t *>(dest);
        const uint8_t *psrc = static_cast<const uint8_t *>(src);

        while (num--) {
            *pdst++ = *psrc++;
        }

        return pdst;
    }

    static void call_ctors(const ctor **start, const ctor **end) {
        for (; start < end; ++start) {
            if (*start)
                (*start)();
        }
    }

    static inline void __attribute__((always_inline)) setup_env() {
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

        // Setup static objects
        call_ctors(__preinit_array_start, __preinit_array_end);
        call_ctors(__ctors_begin, __ctors_end);
        call_ctors(__init_array_start, __init_array_end);
    }
}

extern "C" void isr::reset() {
    setup_env();

    // Run main project code
    runner::run();
    // After run inifinity loop with wait for interrupt code
    while (true) {
        __asm__ volatile ("wfi");
    }
}
