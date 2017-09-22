#ifndef SYSCFG_T_HH
#define SYSCFG_T_HH

#include "hal/common/syscfg_common_t.hh"

namespace hal {
    using syscfg_mem_remap_boot_mode =
        lib::regbit<8,
            syscfg_mem_remap_mem_mode_t,
            2,
            syscfg_mem_remap_mem_mode_t::main_flash>;

    using syscfg_periph_mode_usb_pu = lib::regbit<0>;
    using syscfg_periph_mode_lcd_capa =
        lib::regbit8<1, 5>;
}

#endif // SYSCFG_T_HH 
