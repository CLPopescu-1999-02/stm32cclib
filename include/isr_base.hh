#ifndef ISR_BASE_HH
#define ISR_BASE_HH

#include <stdint.h>
extern uint32_t _estack; // linker defined variable - is a stack size

extern "C"
{
    namespace isr
    {
        struct vectors // table of pointer to interrupt vectors - arm cortex-m3 core interrupts
        {
            uint32_t *estack; /*! stack begin */
            void (*reset)       (); /*!#0 cortex-m3 reset interrupt begin code of this */
            void (*NMI)         (); /*!#1 cortex-m3 non maskable interrupt */
            void (*hard_fault)   (); /*!#2 cortex-m3 hardware fault interrupt */
            void (*mem_manage)   (); /*!#3 cortex-m3 memory management interrupt */
            void (*bus_fault)    (); /*!#4 cortex-m3 bus fault interrupt */
            void (*usage_fault)  (); /*!#5 cortex-m3 usage fault interrupt */
            void (*__unused0[4])(); /*!#6-9 reserved */
            void (*SVC)         (); /*!#10 cortex-m3 system service interrupt */
            void (*debug_mon)    (); /*!#11 cortex-m3 debug monitor interrupt */
            void (*__unused1[1])(); /*!#12 reserved */
            void (*pend_SV)      (); /*!#13 cortex-m3 penable request for system service interrupt */
            void (*sys_tick_timer)(); /*!#14 cortex-m3 system tick timer interrupt */
        };
        
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

#endif // ISR_BASE_HH
