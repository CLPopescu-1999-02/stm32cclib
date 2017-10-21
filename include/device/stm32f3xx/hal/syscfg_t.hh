#ifndef SYSCFG_T_HH
#define SYSCFG_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    enum struct syscfg_config1_mem_mode_t : lib::u8 {
        main_flash = 0,
        system_flash = 1,
        fsmc_bank1 = 2,
        embedded_sram = 3
    };
    using syscfg_config1_mode =
        lib::regbit<0,
            syscfg_config1_mem_mode_t,
            2,
            syscfg_config1_mem_mode_t::main_flash>;
    using syscfg_config1_usb_it_rmp = lib::regbit<5>;
    using syscfg_config1_tim1_itr3_rmp = lib::regbit<6>;
    using syscfg_config1_dac_trig_rmp = lib::regbit<7>;
    using syscfg_config1_adc24_dma_rmp = lib::regbit<8>;
    using syscfg_config1_tim16_dma_rmp = lib::regbit<11>;
    using syscfg_config1_tim17_dma_rmp = lib::regbit<12>;
    using syscfg_config1_tim6_dac1_dma_rmp = lib::regbit<13>;
    using syscfg_config1_tim7_dac2_dma_rmp = lib::regbit<14>;
    using syscfg_config1_i2c_pb6_fmp_rmp = lib::regbit<16>;
    using syscfg_config1_i2c_pb7_fmp_rmp = lib::regbit<17>;
    using syscfg_config1_i2c_pb8_fmp_rmp = lib::regbit<18>;
    using syscfg_config1_i2c_pb9_fmp_rmp = lib::regbit<19>;
    using syscfg_config1_i2c1_fmp_rmp = lib::regbit<20>;
    using syscfg_config1_i2c2_fmp_rmp = lib::regbit<21>;
    using syscfg_config1_encoder_mode =
        lib::regbit8<22, 2, 0>;
    using syscfg_config1_fpu_ie =
        lib::regbit8<26, 6, 0>;

    using syscfg_ccm_sram_protect_page0 = lib::regbit<0>;
    using syscfg_ccm_sram_protect_page1 = lib::regbit<1>;
    using syscfg_ccm_sram_protect_page2 = lib::regbit<2>;
    using syscfg_ccm_sram_protect_page3 = lib::regbit<3>;
    using syscfg_ccm_sram_protect_page4 = lib::regbit<4>;
    using syscfg_ccm_sram_protect_page5 = lib::regbit<5>;
    using syscfg_ccm_sram_protect_page6 = lib::regbit<6>;
    using syscfg_ccm_sram_protect_page7 = lib::regbit<7>;

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

    using syscfg_control2_lockup_lock = lib::regbit<0>;
    using syscfg_control2_sram_parity_lock = lib::regbit<1>;
    using syscfg_control2_pvd_lock = lib::regbit<2>;
    using syscfg_control2_byp_addr_par = lib::regbit<4>;
    using syscfg_control2_sram_pef = lib::regbit<8>;

    template <lib::u32 addr>
    struct syscfg_d {
        struct syscfg_t {
            lib::u32 config1;
            lib::u32 ccm_sram_protect;
            lib::u32 exti_config1;
            lib::u32 exti_config2;
            lib::u32 exti_config3;
            lib::u32 exti_config4;
            lib::u32 config2;
        };

        static constexpr volatile syscfg_t & regs() {
            return *reinterpret_cast<syscfg_t *>(addr);
        }
    };
}

#endif // SYSCFG_T_HH
