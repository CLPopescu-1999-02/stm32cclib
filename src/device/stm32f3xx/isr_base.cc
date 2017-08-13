#include "isr_base.hh"
#include "isr_base_impl.hh"

__attribute__((naked, noreturn)) void isr::default_handler() {
    // nothing in prototype
    while (true);
}

__attribute__((section(".vectors"))) extern const isr::vectors vectors_table = {
    &_estack,
    isr::reset,
    isr::NMI,
    isr::hard_fault,
    isr::mem_manage,
    isr::bus_fault,
    isr::usage_fault,
    0, 0, 0, 0,
    isr::SVC,
    isr::debug_mon,
    0,
    isr::pend_SV,
    isr::sys_tick_timer
}; 
