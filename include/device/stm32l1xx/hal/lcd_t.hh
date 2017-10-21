#ifndef LCD_T_HH
#define LCD_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using lcd_control_lcden = lib::regbit<0>;
    using lcd_control_vsel = lib::regbit<1>;
    enum struct lcd_control_duty_t : lib::u8 {
        by_static = 0b000,
        by1div2 = 0b001,
        by1div3 = 0b010,
        by1div4 = 0b011,
        by1div8 = 0b100
    };
    using lcd_control_duty =
        lib::regbit<2,
            lcd_control_duty_t,
            3,
            lcd_control_duty_t::by_static>;
    enum struct lcd_control_bias_t : lib::u8 {
        by1div4 = 0b00,
        by1div2 = 0b01,
        by1div3 = 0b10
    };
    using lcd_control_bias =
        lib::regbit<5,
            lcd_control_bias_t,
            2,
            lcd_control_bias_t::by1div4>;
    using lcd_control_mux_seg = lib::regbit<7>;

    using lcd_frame_control_hd = lib::regbit<0>;
    using lcd_frame_control_sofie = lib::regbit<1>;
    using lcd_frame_control_uddie = lib::regbit<3>;
    using lcd_frame_control_pon = lib::regbit8<4, 3>;
    using lcd_frame_control_dead = lib::regbit8<7, 3>;
    using lcd_frame_control_cc = lib::regbit8<10, 3>;
    enum struct lcd_frame_control_blinkf_t : lib::u8 {
        by8 = 0b000,
        by16 = 0b001,
        by32 = 0b010,
        by64 = 0b011,
        by128 = 0b100,
        by256 = 0b101,
        by512 = 0b110,
        by1024 = 0b111
    };
    using lcd_frame_control_blinkf =
        lib::regbit<13,
        lcd_frame_control_blinkf_t,
        3,
        lcd_frame_control_blinkf_t::by8>;
    enum struct lcd_frame_control_blink_t : lib::u8 {
        disable = 0b00,
        seg0com0 = 0b01,
        seg0all = 0b10,
        all = 0b11
    };
    using lcd_frame_control_blink =
        lib::regbit<16,
        lcd_frame_control_blink_t,
        2,
        lcd_frame_control_blink_t::disable>;
    enum class lcd_frame_control_div_t : lib::u8 {
        ck_psdiv16 = 0,
        ck_psdiv17 = 1,
        ck_psdiv18 = 2,
        ck_psdiv19 = 3,
        ck_psdiv20 = 4,
        ck_psdiv21 = 5,
        ck_psdiv22 = 6,
        ck_psdiv23 = 7,
        ck_psdiv24 = 8,
        ck_psdiv25 = 9,
        ck_psdiv26 = 10,
        ck_psdiv27 = 11,
        ck_psdiv28 = 12,
        ck_psdiv29 = 13,
        ck_psdiv30 = 14,
        ck_psdiv31 = 15
    };
    using lcd_frame_control_div =
        lib::regbit<18,
            lcd_frame_control_div_t,
            4,
            lcd_frame_control_div_t::ck_psdiv16>;
    enum class lcd_frame_control_ps_t : lib::u8 {
        lcdclk = 0,
        by2 = 1,
        by4 = 2,
        by8 = 3,
        by16 = 4,
        by32 = 5,
        by64 = 6,
        by128 = 7,
        by256 = 8,
        by512 = 9,
        by1024 = 10,
        by2048 = 11,
        by4096 = 12,
        by8192 = 13,
        by16384 = 14,
        by32768 = 15
    };
    using lcd_frame_control_ps =
        lib::regbit<22,
            lcd_frame_control_ps_t,
            4,
            lcd_frame_control_ps_t::lcdclk>;

    using lcd_status_ens = lib::regbit<0>;
    using lcd_status_sof = lib::regbit<1>;
    using lcd_status_udr = lib::regbit<2>;
    using lcd_status_udd = lib::regbit<3>;
    using lcd_status_rdy = lib::regbit<4>;
    using lcd_status_fcrsf = lib::regbit<5>;

    using lcd_clear_sofc = lib::regbit<1>;
    using lcd_clear_uddc = lib::regbit<3>;

    template <lib::u32 addr>
    struct lcd_d {
        struct lcd_t {
            lib::u32 control;
            lib::u32 frame_control;
            lib::u32 status;
            lib::u32 clear;
            lib::u32 _unused0;
            lib::u32 ram[16];
        };

        static constexpr volatile lcd_t & regs() {
            return *reinterpret_cast<lcd_t *>(addr);
        }
    };
}

#endif // LCD_T_HH 
