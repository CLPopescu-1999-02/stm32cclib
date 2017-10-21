#ifndef SYSCFG_COMMON_T_HH
#define SYSCFG_COMMON_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    enum struct syscfg_mem_remap_mem_mode_t : lib::u8 {
        main_flash = 0,
        system_flash = 1,
        fsmc_bank1 = 2,
        embedded_sram = 3
    };
    using syscfg_mem_remap_mem_mode =
        lib::regbit<0,
            syscfg_mem_remap_mem_mode_t,
            2,
            syscfg_mem_remap_mem_mode_t::main_flash>;

    using syscfg_periph_mode_mii_rmii_sel = lib::regbit<23>;

    enum struct syscfg_exti_config_exti_t : lib::u8 {
        pa = 0,
        pb = 1,
        pc = 2,
        pd = 3,
        pe = 4,
        pf = 5,
        pg = 6,
        ph = 7,
        pi = 8
    };
    using syscfg_exti_config1_exti0 =
        lib::regbit<0,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;
    using syscfg_exti_config1_exti1 =
        lib::regbit<4,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;
    using syscfg_exti_config1_exti2 =
        lib::regbit<8,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;
    using syscfg_exti_config1_exti3 =
        lib::regbit<12,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;

    using syscfg_exti_config2_exti4 =
        lib::regbit<0,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;
    using syscfg_exti_config2_exti5 =
        lib::regbit<4,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;
    using syscfg_exti_config2_exti6 =
        lib::regbit<8,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;
    using syscfg_exti_config2_exti7 =
        lib::regbit<12,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;

    using syscfg_exti_config3_exti8 =
        lib::regbit<0,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;
    using syscfg_exti_config3_exti9 =
        lib::regbit<4,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;
    using syscfg_exti_config3_exti10 =
        lib::regbit<8,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;
    using syscfg_exti_config3_exti11 =
        lib::regbit<12,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;

    using syscfg_exti_config4_exti12 =
        lib::regbit<0,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;
    using syscfg_exti_config4_exti13 =
        lib::regbit<4,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;
    using syscfg_exti_config4_exti14 =
        lib::regbit<8,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;
    using syscfg_exti_config4_exti15 =
        lib::regbit<12,
            syscfg_exti_config_exti_t,
            4,
            syscfg_exti_config_exti_t::pa>;

    using syscfg_compens_cell_cmp_pd =
        lib::regbit<0>;
    using syscfg_compens_cell_ready =
        lib::regbit<8>;

    template <lib::u32 addr>
    struct syscfg_d {
        struct syscfg_t {
            lib::u32 mem_remap;
            lib::u32 periph_mode;
            lib::u32 exti_config1;
            lib::u32 exti_config2;
            lib::u32 exti_config3;
            lib::u32 exti_config4;
            lib::u32 compens_cell;
        };

        static constexpr volatile syscfg_t & regs() {
            return *reinterpret_cast<syscfg_t *>(addr);
        }
    };
}

#endif // SYSCFG_COMMON_T_HH
