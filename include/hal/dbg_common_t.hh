#ifndef DBG_COMMON_T_HH
#define DBG_COMMON_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using dbg_id_code_dev =
        lib::regbit<0, lib::u16, 12, 0>;
    using dbg_id_code_rev =
        lib::regbit<16, lib::u16, 16, 0>;

    template <lib::u32 addr>
    struct dbg_d {
        struct dbg_t {
            lib::u32 id_code;
            lib::u32 config;
            lib::u32 apb1_fz;
            lib::u32 apb2_fz;
        };

        static constexpr volatile dbg_t * const regs =
            reinterpret_cast<dbg_t *>(addr);
    };
}

#endif // DBG_COMMON_T_HH
