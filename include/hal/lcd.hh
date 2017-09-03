#ifndef LCD_HH
#define LCD_HH

#include "lib/types.hh"

namespace hal {
    struct lcd_control_t {
        lib::u32 lcden:1;
        lib::u32 vsel:1;
        lib::u32 duty:3;
        lib::u32 bias:2;
        lib::u32 mux_seg:1;
        lib::u32 _unused0:24;
    };

    struct lcd_frame_control_t {
        lib::u32 hd:1;
        lib::u32 sofie:1;
        lib::u32 _unused0:1;
        lib::u32 uddie:1;
        lib::u32 pon:3;
        lib::u32 dead:3;
        lib::u32 cc:3;
        lib::u32 blinkf:3;
        lib::u32 blink:2;
        lib::u32 div:4;
        lib::u32 ps:4;
        lib::u32 _unused1:6;
    };

    struct lcd_status_t {
        lib::u32 ens:1;
        lib::u32 sof:1;
        lib::u32 udr:1;
        lib::u32 udd:1;
        lib::u32 rdy:1;
        lib::u32 fcrsf:1;
        lib::u32 _unused0:26;
    };

    struct lcd_clear_t {
        lib::u32 _unused0:1;
        lib::u32 sofc:1;
        lib::u32 _unused1:1;
        lib::u32 uddc:1;
        lib::u32 _unused2:28;
    };

    struct lcd_t {
        lcd_control_t control;
        lcd_frame_control_t frame_control;
        lcd_status_t status;
        lcd_clear_t clear;
        lib::u32 _unused0;
        lib::u32 ram[16];
    };
}

#include "hal/lcd_d.hh"

#endif // LCD_HH
