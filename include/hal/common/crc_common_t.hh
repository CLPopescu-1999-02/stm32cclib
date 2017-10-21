#ifndef CRC_COMMON_T_HH
#define CRC_COMMON_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using crc_control_reset = lib::regbit<0>;

    template <lib::u32 addr>
    struct crc_d {
        struct crc_t {
            lib::u32 dr;
            lib::u8 independ_data;
            lib::u8 _unused0[3];
            lib::u32 control;
        };

        static constexpr volatile crc_t & regs() {
            return *reinterpret_cast<crc_t *>(addr);
        }
    };
}

#endif // CRC_COMMON_T_HH
