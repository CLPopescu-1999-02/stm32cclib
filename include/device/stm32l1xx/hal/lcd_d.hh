#ifndef LCD_D_HH
#define LCD_D_HH

namespace hal {
    volatile lcd_t * const lcd = reinterpret_cast<lcd_t *>(0x40002400);
}

#endif // LCD_D_HH
