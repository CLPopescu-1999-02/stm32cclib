#ifndef SSD1306_HH
#define SSD1306_HH

#include "lib/types.hh"

#include "hal/spi.hh"
#include "hal/gpio.hh"

namespace bsp {
    template <typename spi, typename reset, typename cs, typename dc>
    class ssd1306 {
    public:
        enum commands : lib::u8 {
            setmux = 0xa8, // set multiplex ratio (n, number of lines active on display)
            setoffs = 0xd3, // set display offset
            startline = 0x40, // set display start line
            seg_norm = 0xa0, // column 0 is mapped to seg0 (x coordinate normal)
            seg_inv = 0xa1, // column 127 is mapped to seg0 (x coordinate inverted)
            com_norm = 0xc0, // scan from com0 to com[n-1] (n - mux ratio, y coordinate normal)
            com_inv = 0xc8, // scan from com[n-1] to com0 (n - mux ratio, y coordinate inverted)
            com_hw = 0xda, // set com pins hardware configuration
            contrast = 0x81, // contrast control
            edon = 0xa5, // entire display on enabled (all pixels on, ram content ignored)
            edoff = 0xa4, // entire display on disabled (output follows ram content)
            inv_off = 0xa6, // entire display inversion off (normal display)
            inv_on = 0xa7, // entire display inversion on (all pixels inverted)
            clockdiv = 0xd5, // set display clock divide ratio/oscillator frequency
            chgpump = 0x8d, // charge pump setting
            disp_on = 0xaf, // display on
            disp_off = 0xae, // display off (sleep mode)
            mem_mode = 0x20, // set memory addressing mode
            set_col = 0x21, // set column address
            set_page = 0x22, // set page address
            vcomh = 0xdb, // set vcomh deselect level
            scrl_hr = 0x26, // setup continuous horizontal scroll right
            scrl_hl = 0x27, // setup continuous horizontal scroll left
            scrl_vhr = 0x29, // setup continuous vertical and horizontal scroll right
            scrl_vhl = 0x2a, // setup continuous vertical and horizontal scroll left
            scrl_stop = 0x2e, // deactivate scroll
            scrl_act = 0x2f, // activate scroll
            prech_per = 0xd9 // prechange preriod
        };

        static void send_cmd(lib::u8 cmd) {
            dc::reset();

            spi::send_w(cmd);
        }

        static void send_cmd(lib::u8 cmd1, lib::u8 cmd2) {
            dc::reset();

            spi::send_w(cmd1);
            spi::send_w(cmd2);
        }

        static void send_data(lib::u8 data) {
            dc::set();
            cs::reset();

            spi::send_w(data);

            while (spi::is_busy());
            cs::set();
        }

        template <lib::u32 size>
        static void send_data(const lib::u8 (&data)[size]) {
            const auto end_data = data + size;
            auto it = data;

            dc::set();
            cs::reset();

            while (it < end_data)
                spi::send_w(*it++);

            while (spi::is_busy());
            cs::set();
        }

        static void enter_command(const commands cmd) {
            cs::reset();

            send_cmd(cmd);

            cs::set();
        }

        template <lib::u32 size>
        static void enter_command(const lib::u8 (&cmd)[size]) {
            const auto end_cmd = cmd + size;
            auto it = cmd;

            dc::reset();
            cs::reset();

            while (it < end_cmd)
                spi::send_w(*it++);

            while (spi::is_busy());
            cs::set();
        }

        static void set_contrast(lib::u8 new_contrast) {
            cs::reset();

            send_cmd(contrast, new_contrast);

            cs::set();
        }

        static void setup() {
            dc::set();
            cs::set();
            reset::reset();
            reset::set();
            dc::reset();
            cs::reset();

            // display off
            send_cmd(disp_off);
            // clock divide, OSC freq
            send_cmd(clockdiv, 0xf0);
            // multiplex ratio
            send_cmd(setmux, 0x3f);
            // display offset
            send_cmd(setoffs, 0x00);
            // set display startline(64)
            send_cmd(startline);
            // enable charge pump
            send_cmd(chgpump, 0x14);
            // segment remap(col.127 mapped to SEG0)
            send_cmd(seg_inv);
            // set COM output scan direction
            send_cmd(com_inv);
            // set addressing mode is "horisontal"
            send_cmd(mem_mode, 0x00);
            // set COM pins hardware configuration
            send_cmd(com_hw, 0x12);
            // set contrast
            send_cmd(contrast, 127);
            // pre-charge period
            send_cmd(prech_per, 0xe1);
            // set vcomh deselect level
            send_cmd(vcomh, 0x40);
            // set entire display ON/OFF
            send_cmd(edoff);
            // set normal, inverse display
            send_cmd(inv_off);
            // display ON
            send_cmd(disp_on);

            while (spi::is_busy());
            cs::set();
            dc::set();
        }
    };
}

#endif // SSD1306_HH
