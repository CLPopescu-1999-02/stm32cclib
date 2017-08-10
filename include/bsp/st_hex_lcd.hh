#ifndef ST_HEX_LCD_HH
#define ST_HEX_LCD_HH

#include <stdint.h>

#include "hal/lcd.hh"

namespace bsp {
    class digit {
    public:
        digit(const uint32_t pos, volatile uint32_t * const ram);

        void write(const uint16_t mask) const;

        void clear() const;

    private:
        const uint32_t _pos;
        volatile uint32_t * const _ram;
    };

    class screen {
    public:
        screen (volatile uint32_t * const ram);

        const digit & operator [] (const uint32_t pos) const;

    private:
        const digit digits[6];
    };

    class st_hex_lcd {
    public:
        st_hex_lcd();

        void setup();

        st_hex_lcd write_char(const unsigned int pos, const char ch);

        st_hex_lcd write_digit(const unsigned int pos, const int dig);

        st_hex_lcd write_col(const unsigned int pos);

        st_hex_lcd write_dp(const unsigned int pos);

        st_hex_lcd clear(const unsigned int pos);

        st_hex_lcd wait_update();

        st_hex_lcd update();

    private:
        volatile hal::lcd_t * lcd;
        const screen scr;
    };
}

#endif // ST_HEX_LCD_HH
