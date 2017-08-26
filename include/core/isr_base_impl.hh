#ifndef ISR_BASE_IMPL_HH
#define ISR_BASE_IMPL_HH

#include <stdint.h>

extern "C" {
    namespace isr {
        void default_handler(); // default handler for undefined handlers

        void reset() __attribute__ ((weak, alias ("default_handler")));
        void NMI() __attribute__ ((weak, alias ("default_handler")));
        void hard_fault() __attribute__ ((weak, alias ("default_handler")));
        void mem_manage() __attribute__ ((weak, alias ("default_handler")));
        void bus_fault() __attribute__ ((weak, alias ("default_handler")));
        void usage_fault() __attribute__ ((weak, alias ("default_handler")));
        void SVC() __attribute__ ((weak, alias ("default_handler")));
        void debug_mon() __attribute__ ((weak, alias ("default_handler")));
        void pend_SV() __attribute__ ((weak, alias ("default_handler")));
        void sys_tick_timer() __attribute__ ((weak, alias ("default_handler")));
    }
}

#endif // ISR_BASE_IMPL_HH
