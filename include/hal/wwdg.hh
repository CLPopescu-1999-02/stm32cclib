#ifndef WWDG_HH
#define WWDG_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using wwdg_control_t =
        lib::regbit8<0, 7>;
    using wwdg_control_wdga = lib::regbit<7>;

    using wwdg_config_w =
        lib::regbit8<0, 7>;
    enum struct wwdg_config_wdgtb_t : lib::u8 {
        by1 = 0b00,
        by2 = 0b01,
        by4 = 0b10,
        by8 = 0b11
    };
    using wwdg_config_wdgtb =
        lib::regbit<7,
            wwdg_config_wdgtb_t,
            2,
            wwdg_config_wdgtb_t::by1>;
    using wwdg_config_ewi = lib::regbit<9>;

    using wwdg_status_ewif = lib::regbit<0>;

    template <lib::u32 addr>
    struct wwdg_d {
        struct wwdg_t {
            lib::u32 control;
            lib::u32 config;
            lib::u32 status;
        };

        static constexpr volatile wwdg_t * const regs =
            reinterpret_cast<wwdg_t *>(addr);
    };
}

#include "hal/wwdg_d.hh"

#endif // WWDG_HH
