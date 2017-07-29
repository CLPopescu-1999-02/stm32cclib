#ifndef LCD_HH
#define LCD_HH

#include <stdint.h>

namespace hal {
    struct lcd_control_t {
        uint32_t lcden:1;
        uint32_t vsel:1;
        uint32_t duty:3;
        uint32_t bias:2;
        uint32_t mux_seg:1;
        uint32_t _unused0:24;
    };

    struct lcd_frame_control_t {
        uint32_t hd:1;
        uint32_t sofie:1;
        uint32_t _unused0:1;
        uint32_t uddie:1;
        uint32_t pon:3;
        uint32_t dead:3;
        uint32_t cc:3;
        uint32_t blinkf:3;
        uint32_t blink:2;
        uint32_t div:4;
        uint32_t ps:4;
        uint32_t _unused1:6;
    };

    struct lcd_status_t {
        uint32_t ens:1;
        uint32_t sof:1;
        uint32_t udr:1;
        uint32_t udd:1;
        uint32_t rdy:1;
        uint32_t fcrsf:1;
        uint32_t _unused0:26;
    };

    struct lcd_clear_t {
        uint32_t _unused0:1;
        uint32_t sofc:1;
        uint32_t _unused1:1;
        uint32_t uddc:1;
        uint32_t _unused2:28;
    };

    struct lcd_t {
        lcd_control_t control;
        lcd_frame_control_t frame_control;
        lcd_status_t status;
        lcd_clear_t clear;
        uint32_t _unused0;
        uint32_t ram[16];
    };

    volatile lcd_t * const lcd = reinterpret_cast<lcd_t *>(0x40002400);
}

#endif // LCD_HH
