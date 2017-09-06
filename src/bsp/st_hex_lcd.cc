#include "bsp/st_hex_lcd.hh"

namespace bsp {
    // constant upper letters
    const lib::u16 cap_letter_masks[26] = {
        // A      B      C      D      E      F      G      H      I
        0xf00b,0x511e,0x3005,0x511c,0xb005,0xb001,0x300f,0xe00b,0x0110,
        // J      K      L      M      N      O      P      Q      R
        0x400d,0xa441,0x2005,0x6609,0x6249,0x700d,0xf003,0x704d,0xf043,
        // S      T      U      V      W      X      Y      Z
        0xb00e,0x1110,0x600d,0x2c01,0x6849,0x0e40,0x0610,0x1c04
    };

    // constant numbers
    const lib::u16 number_masks[10] = {
        // 0      1      2      3      4      5      6      7      8      9
        0x700d,0x4008,0xd007,0x500e,0xe00a,0xb00e,0xb00f,0x5008,0xf00f,0xf00e
    };

    void st_hex_lcd::write(const lib::u32 pos, const lib::u16 mask) {
        switch (pos) {
            case 0:
                _ram[0] |= (mask & 0xc000) << 14 | (mask & 0x0003);
                _ram[2] |= (mask & 0x3000) << 16 | (mask & 0x000c) >> 2;
                _ram[4] |= (mask & 0x0c00) << 18 | (mask & 0x0030) >> 4;
                _ram[6] |= (mask & 0x0300) << 20 | (mask & 0x00c0) >> 6;
                break;
            case 1:
                _ram[0] |= (mask & 0xc000) << 12 | ((mask & 0x0002) >> 1) << 7 | (mask & 0x0001) << 2;
                _ram[2] |= (mask & 0x3000) << 14 | ((mask & 0x0008) >> 3) << 7 | ((mask & 0x0004) >> 2) << 2;
                _ram[4] |= (mask & 0x0c00) << 16 | ((mask & 0x0020) >> 5) << 7 | ((mask & 0x0010) >> 4) << 2;
                _ram[6] |= (mask & 0x0300) << 18 | ((mask & 0x0080) >> 7) << 7 | ((mask & 0x0040) >> 6) << 2;
                break;
            case 2:
                _ram[0] |= (mask & 0xc000) << 10 | (mask & 0x0003) << 8;
                _ram[2] |= (mask & 0x3000) << 12 | ((mask & 0x000c) >> 2) << 8;
                _ram[4] |= (mask & 0x0c00) << 14 | ((mask & 0x0030) >> 4) << 8;
                _ram[6] |= (mask & 0x0300) << 16 | ((mask & 0x00c0) >> 6) << 8;
                break;
            case 3:
                _ram[0] |= (mask & 0xc000) << 6 | (mask & 0x0003) << (10);
                _ram[2] |= (mask & 0x3000) << 8 | ((mask & 0x000c) >> 2) << (10);
                _ram[4] |= (mask & 0x0c00) << 10 | ((mask & 0x0030) >> 4) << (10);
                _ram[6] |= (mask & 0x0300) << 12 | ((mask & 0x00c0) >> 6) << (10);
                break;
            case 4:
                _ram[0] |= (mask & 0xc000) << 4 | (mask & 0x0003) << (12);
                _ram[2] |= (mask & 0x3000) << 6 | ((mask & 0x000c) >> 2) << (12);
                _ram[4] |= (mask & 0x0c00) << 8 | ((mask & 0x0030) >> 4) << (12);
                _ram[6] |= (mask & 0x0300) << 10 | ((mask & 0x00c0) >> 6) << (12);
                break;
            case 5:
            default:
                _ram[0] |= (mask & 0x8000) << 1 | (mask & 0x4000) << 3 | (mask & 0x0003) << (14);
                _ram[2] |= (mask & 0x2000) << 3 | (mask & 0x1000) << 5 | ((mask & 0x000c) >> 2) << (14);
                _ram[4] |= (mask & 0x0800) << 5 | (mask & 0x0400) << 7 | ((mask & 0x0030) >> 4) << (14);
                _ram[6] |= (mask & 0x0200) << 7 | (mask & 0x0100) << 9 | ((mask & 0x00c0) >> 6) << (14);
                break;
        }
    }

    void st_hex_lcd::clear(const lib::u32 pos) {
        switch (pos) {
            case 0:
                _ram[0] &= 0xcffffffc;
                _ram[2] &= 0xcffffffc;
                _ram[4] &= 0xcffffffc;
                _ram[6] &= 0xcffffffc;
                break;
            case 1:
                _ram[0] &= 0xf3ffff03;
                _ram[2] &= 0xf3ffff03;
                _ram[4] &= 0xf3ffff03;
                _ram[6] &= 0xf3ffff03;
                break;
            case 2:
                _ram[0] &= 0xfcfffcff;
                _ram[2] &= 0xfcfffcff;
                _ram[4] &= 0xfcfffcff;
                _ram[6] &= 0xfcfffcff;
                break;
            case 3:
                _ram[0] &= 0xffcff3ff;
                _ram[2] &= 0xffcff3ff;
                _ram[4] &= 0xffcff3ff;
                _ram[6] &= 0xffcff3ff;
                break;
            case 4:
                _ram[0] &= 0xfff3cfff;
                _ram[2] &= 0xfff3cfff;
                _ram[4] &= 0xfff3cfff;
                _ram[6] &= 0xfff3cfff;
                break;
            case 5:
            default:
                _ram[0] &= 0xfffc3fff;
                _ram[2] &= 0xfffc3fff;
                _ram[4] &= 0xfffc3fff;
                _ram[6] &= 0xfffc3fff;
                break;
        }
    }

    void st_hex_lcd::setup() {
        // set BIAS to 1/3
        // set DUTY to 1/4
        // enable lcd remaping
        lcd::regs->control =
            lib::regbits32<
                hal::lcd_control_bias::val<
                    hal::lcd_control_bias_t::by1div3>,
                hal::lcd_control_duty::val<
                    hal::lcd_control_duty_t::by1div4>,
                hal::lcd_control_mux_seg
            >::mask;

        // setup lcd clock
        // setup lcd contrast
        lcd::regs->frame_control =
            lib::regbits32<
                hal::lcd_frame_control_ps::val<
                    hal::lcd_frame_control_ps_t::by16>,
                hal::lcd_frame_control_div::val<
                    hal::lcd_frame_control_div_t::ck_psdiv17>,
                hal::lcd_frame_control_cc::val<0b010>
            >::mask;
        // wait for synchro lcd frame control
        while ((lcd::regs->status &
            hal::lcd_status_fcrsf::clean<lib::u32>::mask) == 0);

        // internal step-up converter
        // enable lcd controller
        lcd::regs->control |=
            lib::regbits32<
                hal::lcd_control_vsel::val<false>,
                hal::lcd_control_lcden
            >::mask;

        // wait for ready step-up converter
        while ((lcd::regs->status &
            hal::lcd_status_rdy::clean<lib::u32>::mask) == 0);
        // wait for ready lcd controller
        while ((lcd::regs->status &
            hal::lcd_status_ens::clean<lib::u32>::mask) == 0);
    }

    void st_hex_lcd::write_char(const lib::u32 pos, const char ch) {
        if (ch >= 'A' && ch <= 'Z') {
            write(pos, cap_letter_masks[static_cast<const lib::u8>(ch-'A')]);
        } else if (ch >= '0' && ch <= '9') {
            write(pos, number_masks[static_cast<const lib::u8>(ch-'0')]);
        } else {
            write(pos, 0x0000);
        }
    }

    void  st_hex_lcd::write_digit(const lib::u32 pos, const int dig) {
        if (dig >= 0 && dig <= 9) {
            write(pos, number_masks[dig]);
        } else {
            write(pos, 0x0000);
        }
    }

    void  st_hex_lcd::write_col(const lib::u32 pos) {
        write(pos, 0x0020);
    }

    void  st_hex_lcd::write_dp(const lib::u32 pos) {
        write(pos, 0x0080);
    }

    void st_hex_lcd::wait_update() {
        while ((lcd::regs->status &
            hal::lcd_status_udr::clean<lib::u32>::mask));
    }

    void st_hex_lcd::update() {
        lcd::regs->status |=
            hal::lcd_status_udr::clean<lib::u32>::mask;
    }
}
