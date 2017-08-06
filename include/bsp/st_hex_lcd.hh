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

        void write_char(const unsigned int pos, const char ch);

        void write_col(const unsigned int pos);

        void write_dp(const unsigned int pos);

        void clear(const unsigned int pos);

        void wait_update();

        void update();

    private:
        volatile hal::lcd_t * lcd;
        const screen scr;
    };
}

#endif // ST_HEX_LCD_HH
