#ifndef CRC_T_HH
#define CRC_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using crc_control_reset = lib::regbit<0>;
    enum struct crc_control_polysize_t : lib::u8 {
        of32bit = 0b00,
        of16bit = 0b01,
        of8bit = 0b10,
        of7bit = 0b11
    };
    using crc_control_polysize =
        lib::regbit<3,
            crc_control_polysize_t,
            2,
            crc_control_polysize_t::of32bit>;
    enum struct crc_control_rev_in_t : lib::u8 {
        not_affected = 0b00,
        by_byte = 0b01,
        by_half_word = 0b10,
        by_word = 0b11
    };
    using crc_control_rev_in =
        lib::regbit<5,
            crc_control_rev_in_t,
            2,
            crc_control_rev_in_t::not_affected>;
    using crc_control_rev_out = lib::regbit<0>;

    template <lib::u32 addr>
    struct crc_d {
        struct crc_t {
            lib::u32 dr;
            lib::u8 independ_data;
            lib::u8 _unused0[3];
            lib::u32 control;
            lib::u32 init;
            lib::u32 poly;
        };

        static constexpr volatile crc_t & regs() {
            return *reinterpret_cast<crc_t *>(addr);
        }
    };
}

#endif // CRC_T_HH
