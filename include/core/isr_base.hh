#ifndef ISR_BASE_HH
#define ISR_BASE_HH

#include <stdint.h>
extern uint32_t _estack; // linker defined variable - is a stack size

extern "C" {
    namespace isr {
        struct vectors // table of pointer to interrupt vectors - arm cortex core interrupts
        {
            uint32_t *estack; /*! stack begin */
            void (*reset)           (); /*!#0 cortex reset interrupt begin code of this */
            void (*NMI)             (); /*!#1 cortex non maskable interrupt */
            void (*hard_fault)      (); /*!#2 cortex hardware fault interrupt */
            void (*mem_manage)      (); /*!#3 cortex memory management interrupt */
            void (*bus_fault)       (); /*!#4 cortex bus fault interrupt */
            void (*usage_fault)     (); /*!#5 cortex usage fault interrupt */
            void (*__unused0[4])    (); /*!#6-9 reserved */
            void (*SVC)             (); /*!#10 cortex system service interrupt */
            void (*debug_mon)       (); /*!#11 cortex debug monitor interrupt */
            void (*__unused1[1])    (); /*!#12 reserved */
            void (*pend_SV)         (); /*!#13 cortex penable request for system service interrupt */
            void (*sys_tick_timer)  (); /*!#14 cortex system tick timer interrupt */
        };

        void reset();
        void NMI();
        void hard_fault();
        void mem_manage();
        void bus_fault();
        void usage_fault();
        void SVC();
        void debug_mon();
        void pend_SV();
        void sys_tick_timer();
    }
}

#endif // ISR_BASE_HH
