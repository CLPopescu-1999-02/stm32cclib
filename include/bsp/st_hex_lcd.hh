#ifndef ST_HEX_LCD_HH
#define ST_HEX_LCD_HH

#include <stdint.h>

#include "hal/lcd.hh"

namespace bsp {
    class st_hex_lcd {
    public:
        st_hex_lcd() {
            lcd = hal::lcd;

            // set BIAS to 1/3
            lcd->control.bias = 0b10;
            // set DUTY to 1/4
            lcd->control.duty = 0b011;
            // enable lcd remaping
            lcd->control.mux_seg = 1;

            // setup lcd clock
            lcd->frame_control.ps = 0b0100;
            lcd->frame_control.div = 0b0001;
            // setup lcd contrast
            lcd->frame_control.cc = 0b010;
            // wait for synchro lcd frame control
            while (lcd->status.fcrsf == 0);

            // internal step-up converter
            lcd->control.vsel = 0;
            // enable lcd controller
            lcd->control.lcden = 1;

            // wait for ready step-up converter
            while (lcd->status.rdy != 1);
            // wait for ready lcd controller
            while (lcd->status.ens != 1);

            // wait for final update display
            while (lcd->status.udr == 1);
            // write TEST to buffer
            lcd->ram[0] = 0x02200b00;
            lcd->ram[2] = 0x07340d00;
            lcd->ram[4] = 0x00001004;
            lcd->ram[6] = 0x04040000;
            // update lcd from buffer
            lcd->status.udr = 1;
        }

    private:
        volatile hal::lcd_t * lcd;
    };
}

#endif // ST_HEX_LCD_HH
