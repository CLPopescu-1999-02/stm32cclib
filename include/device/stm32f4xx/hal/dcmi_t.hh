#ifndef DCMI_T_HH
#define DCMI_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using dcmi_control_capture = lib::regbit<0>;
    using dcmi_control_cm = lib::regbit<1>;
    using dcmi_control_crop = lib::regbit<2>;
    using dcmi_control_jpeg = lib::regbit<3>;
    using dcmi_control_ess = lib::regbit<4>;
    using dcmi_control_pckpol = lib::regbit<5>;
    using dcmi_control_hspol = lib::regbit<6>;
    using dcmi_control_vspol = lib::regbit<7>;
    enum struct dcmi_control_fcrc_t : lib::u8 {
        all = 0,
        every_alternate_frame,
        one_in_4_frames
    };
    using dcmi_control_fcrc =
        lib::regbit<8,
            dcmi_control_fcrc_t,
            2,
            dcmi_control_fcrc_t::all>;
    enum struct dcmi_control_edm_t : lib::u8 {
        on8bit = 0,
        on10bit,
        on12bit,
        on14bit
    };
    using dcmi_control_edm =
        lib::regbit<10,
            dcmi_control_edm_t,
            2,
            dcmi_control_edm_t::on8bit>;
    using dcmi_control_enable = lib::regbit<14>;

    using dcmi_status_hsync = lib::regbit<0>;
    using dcmi_status_vsync = lib::regbit<1>;
    using dcmi_status_fne = lib::regbit<2>;

    using dcmi_int_frame = lib::regbit<0>;
    using dcmi_int_ovr = lib::regbit<1>;
    using dcmi_int_err = lib::regbit<2>;
    using dcmi_int_vsync = lib::regbit<3>;
    using dcmi_int_line = lib::regbit<4>;

    using dcmi_embedded_sync_fs =
        lib::regbit8<0, 8>;
    using dcmi_embedded_sync_ls =
        lib::regbit8<8, 8>;
    using dcmi_embedded_sync_le =
        lib::regbit8<16, 8>;
    using dcmi_embedded_sync_fe =
        lib::regbit8<24, 8>;

    using dcmi_crop_window_start_hoffcnt =
        lib::regbit16<0, 14>;
    using dcmi_crop_window_start_vst =
        lib::regbit16<16, 13>;

    using dcmi_crop_window_size_capcnt =
        lib::regbit16<0, 14>;
    using dcmi_crop_window_size_vline =
        lib::regbit16<16, 14>;

    template <lib::u32 addr>
    struct dcmi_d {
        struct dcmi_t {
            lib::u32 control;
            lib::u32 status;
            lib::u32 int_raw_status;
            lib::u32 int_enable;
            lib::u32 int_mask_status;
            lib::u32 int_clear;
            lib::u32 embedded_sync_code;
            lib::u32 embedded_sync_unmask;
            lib::u32 crop_window_start;
            lib::u32 crop_window_size;
            lib::u32 dr;
        };

        static constexpr volatile dcmi_t & regs() {
            return *reinterpret_cast<dcmi_t *>(addr);
        }
    };
}

#endif // DCMI_T_HH
