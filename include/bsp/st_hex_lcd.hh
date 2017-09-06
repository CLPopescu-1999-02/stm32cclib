#ifndef ST_HEX_LCD_HH
#define ST_HEX_LCD_HH

#include "lib/types.hh"

#include "hal/lcd.hh"

namespace bsp {
    class st_hex_lcd {
    public:
        static void setup();

        static void write_char(const lib::u32 pos, const char ch);

        static void write_digit(const lib::u32 pos, const int dig);

        static void write_col(const lib::u32 pos);

        static void write_dp(const lib::u32 pos);

        static void clear(const lib::u32 pos);

        static void wait_update();

        static void update();

        static void write(const lib::u32 pos, const lib::u16 mask);

        using lcd = hal::lcd;
        static constexpr volatile lib::u32 * const _ram{lcd::regs->ram};
    };
}

#endif // ST_HEX_LCD_HH
