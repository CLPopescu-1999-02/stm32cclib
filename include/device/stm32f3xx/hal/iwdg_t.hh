#ifndef IWDG_T_HH
#define IWDG_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    enum struct iwdg_prescaler_pr_t : lib::u8 {
        by4 = 0,
        by8 = 1,
        by16 = 2,
        by32 = 3,
        by64 = 4,
        by128 = 5,
        by256 = 6
    };
    using iwdg_prescaler_pr =
        lib::regbit<0,
            iwdg_prescaler_pr_t,
            3,
            iwdg_prescaler_pr_t::by4>;

    using iwdg_status_pvu = lib::regbit<0>;
    using iwdg_status_rvu = lib::regbit<1>;
    using iwdg_status_wvu = lib::regbit<2>;

    template <lib::u32 addr>
    struct iwdg_d {
        struct iwdg_t {
            lib::u32 key;
            lib::u32 prescaler;
            lib::u32 reload;
            lib::u32 status;
            lib::u32 window;
        };

        static constexpr volatile iwdg_t * const regs =
            reinterpret_cast<iwdg_t *>(addr);
    };
}

#endif // IWDG_T_HH
