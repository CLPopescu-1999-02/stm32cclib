#ifndef RCC_T_HH
#define RCC_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using rcc_control_hsion = lib::regbit<0>;
    using rcc_control_hsirdy = lib::regbit<1>;
    using rcc_control_hsitrim = lib::regbit<3, lib::u8, 5>;
    using rcc_control_hsical = lib::regbit<8, lib::u8, 8>;
    using rcc_control_hseon = lib::regbit<16>;
    using rcc_control_hserdy = lib::regbit<17>;
    using rcc_control_hsebyp = lib::regbit<18>;
    using rcc_control_csson = lib::regbit<19>;
    using rcc_control_pllon = lib::regbit<24>;
    using rcc_control_pllrdy = lib::regbit<25>;
    using rcc_control_plli2son = lib::regbit<26>;
    using rcc_control_plli2srdy = lib::regbit<27>;

    using rcc_pll_config_div = lib::regbit<0, lib::u8, 6, 1>;
    using rcc_pll_config_main_mul = lib::regbit<6, lib::u16, 9, 63>;
    enum struct rcc_pll_config_main_div_t : lib::u8 {
        by2 = 0b00,
        by4 = 0b01,
        by6 = 0b10,
        by8 = 0b11
    };
    using rcc_pll_config_main_div =
        lib::regbit<16,
            rcc_pll_config_main_div_t,
            2,
            rcc_pll_config_main_div_t::by2>;
    enum struct rcc_pll_config_clk_src_t : lib::u8 {
        hsi = 0b0,
        hse = 0b1,
    };
    using rcc_pll_config_clk_src =
        lib::regbit<22,
            rcc_pll_config_clk_src_t,
            1,
            rcc_pll_config_clk_src_t::hsi>;
    using rcc_pll_config_otgfs_sdio_div = lib::regbit<24, lib::u8, 4, 2>;

    enum struct rcc_config_clk_sw_t : lib::u8 {
        hsi = 0b00,
        hse = 0b01,
        pll = 0b10
    };
    using rcc_config_clk_sw =
        lib::regbit<0,
            rcc_config_clk_sw_t,
            2,
            rcc_config_clk_sw_t::hsi>;
    using rcc_config_clk_sws =
        lib::regbit<2,
            rcc_config_clk_sw_t,
            2,
            rcc_config_clk_sw_t::hsi>;
    enum struct rcc_config_ahb_pre_t : lib::u8 {
        not_div = 0b0000,
        by2 = 0b1000,
        by4 = 0b1001,
        by8 = 0b1010,
        by16 = 0b1011,
        by64 = 0b1100,
        by128 = 0b1101,
        by256 = 0b1110,
        by512 = 0b1111
    };
    using rcc_config_ahb_pre =
        lib::regbit<4,
            rcc_config_ahb_pre_t,
            4,
            rcc_config_ahb_pre_t::not_div>;
    enum struct rcc_config_apb_pre_t : lib::u8 {
        not_div = 0b000,
        by2 = 0b100,
        by4 = 0b101,
        by8 = 0b110,
        by16 = 0b111,
    };
    using rcc_config_apb1_pre =
        lib::regbit<10,
            rcc_config_apb_pre_t,
            3,
            rcc_config_apb_pre_t::not_div>;
    using rcc_config_apb2_pre =
        lib::regbit<13,
            rcc_config_apb_pre_t,
            3,
            rcc_config_apb_pre_t::not_div>;
    using rcc_config_rtc_pre = lib::regbit<16, lib::u8, 5, 2>;
    enum struct rcc_config_mco_t : lib::u8 {
        hsi = 0b00,
        lse = 0b01,
        hse = 0b10,
        pll = 0b11
    };
    using rcc_config_mco1 =
        lib::regbit<21,
            rcc_config_mco_t,
            2,
            rcc_config_mco_t::hsi>;
    using rcc_config_i2s_ext_src = lib::regbit<23>;
    enum struct rcc_config_mco_pre_t : lib::u8 {
        not_div = 0b000,
        by2 = 0b100,
        by3 = 0b101,
        by4 = 0b110,
        by5 = 0b111,
    };
    using rcc_config_mco1_pre =
        lib::regbit<24,
            rcc_config_mco_pre_t,
            3,
            rcc_config_mco_pre_t::not_div>;
    using rcc_config_mco2_pre =
        lib::regbit<27,
            rcc_config_mco_pre_t,
            3,
            rcc_config_mco_pre_t::not_div>;
    using rcc_config_mco2 =
        lib::regbit<30,
            rcc_config_mco_t,
            2,
            rcc_config_mco_t::hsi>;

    using rcc_interrupt_lsirdyf = lib::regbit<0>;
    using rcc_interrupt_lserdyf = lib::regbit<1>;
    using rcc_interrupt_hsirdyf = lib::regbit<2>;
    using rcc_interrupt_hserdyf = lib::regbit<3>;
    using rcc_interrupt_pllrdyf = lib::regbit<4>;
    using rcc_interrupt_plli2srdyf = lib::regbit<5>;
    using rcc_interrupt_cssf = lib::regbit<7>;
    using rcc_interrupt_lsirdyie = lib::regbit<8>;
    using rcc_interrupt_lserdyie = lib::regbit<9>;
    using rcc_interrupt_hsirdyie = lib::regbit<10>;
    using rcc_interrupt_hserdyie = lib::regbit<11>;
    using rcc_interrupt_pllrdyie = lib::regbit<12>;
    using rcc_interrupt_plli2srdyie = lib::regbit<13>;
    using rcc_interrupt_lsirdyc = lib::regbit<16>;
    using rcc_interrupt_lserdyc = lib::regbit<17>;
    using rcc_interrupt_hsirdyc = lib::regbit<18>;
    using rcc_interrupt_hserdyc = lib::regbit<19>;
    using rcc_interrupt_pllrdyc = lib::regbit<20>;
    using rcc_interrupt_plli2srdyc = lib::regbit<21>;
    using rcc_interrupt_cssc = lib::regbit<23>;

    using rcc_ahb1_gpioa = lib::regbit<0>;
    using rcc_ahb1_gpiob = lib::regbit<1>;
    using rcc_ahb1_gpioc = lib::regbit<2>;
    using rcc_ahb1_gpiod = lib::regbit<3>;
    using rcc_ahb1_gpioe = lib::regbit<4>;
    using rcc_ahb1_gpiof = lib::regbit<5>;
    using rcc_ahb1_gpiog = lib::regbit<6>;
    using rcc_ahb1_gpioh = lib::regbit<7>;
    using rcc_ahb1_gpioi = lib::regbit<8>;
    using rcc_ahb1_crc = lib::regbit<12>;
    using rcc_ahb1_dma1 = lib::regbit<21>;
    using rcc_ahb1_dma2 = lib::regbit<22>;
    using rcc_ahb1_ethmac = lib::regbit<25>;
    using rcc_ahb1_otghs = lib::regbit<29>;

    using rcc_ahb2_dcmi = lib::regbit<0>;
    using rcc_ahb2_cryp = lib::regbit<4>;
    using rcc_ahb2_hash = lib::regbit<5>;
    using rcc_ahb2_rng = lib::regbit<6>;
    using rcc_ahb2_otgfs = lib::regbit<7>;

    using rcc_ahb3_fsmc = lib::regbit<0>;

    using rcc_apb1_tim2 = lib::regbit<0>;
    using rcc_apb1_tim3 = lib::regbit<1>;
    using rcc_apb1_tim4 = lib::regbit<2>;
    using rcc_apb1_tim5 = lib::regbit<3>;
    using rcc_apb1_tim6 = lib::regbit<4>;
    using rcc_apb1_tim7 = lib::regbit<5>;
    using rcc_apb1_tim12 = lib::regbit<6>;
    using rcc_apb1_tim13 = lib::regbit<7>;
    using rcc_apb1_tim14 = lib::regbit<8>;
    using rcc_apb1_wwdg = lib::regbit<11>;
    using rcc_apb1_spi2 = lib::regbit<14>;
    using rcc_apb1_spi3 = lib::regbit<15>;
    using rcc_apb1_usart2 = lib::regbit<17>;
    using rcc_apb1_usart3 = lib::regbit<18>;
    using rcc_apb1_uart4 = lib::regbit<19>;
    using rcc_apb1_uart5 = lib::regbit<20>;
    using rcc_apb1_i2c1 = lib::regbit<21>;
    using rcc_apb1_i2c2 = lib::regbit<22>;
    using rcc_apb1_i2c3 = lib::regbit<23>;
    using rcc_apb1_can1 = lib::regbit<25>;
    using rcc_apb1_can2 = lib::regbit<26>;
    using rcc_apb1_pwr = lib::regbit<28>;
    using rcc_apb1_dac = lib::regbit<29>;

    using rcc_apb2_tim1 = lib::regbit<0>;
    using rcc_apb2_tim8 = lib::regbit<1>;
    using rcc_apb2_usart1 = lib::regbit<4>;
    using rcc_apb2_usart6 = lib::regbit<5>;
    using rcc_apb2_adc = lib::regbit<8>;
    using rcc_apb2_sdio = lib::regbit<11>;
    using rcc_apb2_spi1 = lib::regbit<12>;
    using rcc_apb2_syscfg = lib::regbit<14>;

    using rcc_backupd_control_lseon = lib::regbit<0>;
    using rcc_backupd_control_lserdy = lib::regbit<1>;
    using rcc_backupd_control_lsebyp = lib::regbit<2>;
    enum struct rcc_backupd_control_rtc_sel_t : lib::u8 {
        no_clock = 0b00,
        lse = 0b01,
        lsi = 0b10,
        hse = 0b11
    };
    using rcc_backupd_control_rtc_sel =
        lib::regbit<8,
            rcc_backupd_control_rtc_sel_t,
            2,
            rcc_backupd_control_rtc_sel_t::no_clock>;
    using rcc_backupd_control_rtcen = lib::regbit<15>;
    using rcc_backupd_control_bdrts = lib::regbit<16>;

    using rcc_control_status_lsion = lib::regbit<0>;
    using rcc_control_status_lsirdy = lib::regbit<1>;
    using rcc_control_status_rmvf = lib::regbit<24>;
    using rcc_control_status_borrstf = lib::regbit<25>;
    using rcc_control_status_pinrstf = lib::regbit<26>;
    using rcc_control_status_porrstf = lib::regbit<27>;
    using rcc_control_status_sftrstf = lib::regbit<28>;
    using rcc_control_status_iwdgrstf = lib::regbit<29>;
    using rcc_control_status_wwdgrstf = lib::regbit<30>;
    using rcc_control_status_lpwrrstf = lib::regbit<31>;

    using rcc_spread_spectrum_modper = lib::regbit<0, lib::u16, 13, 0>;
    using rcc_spread_spectrum_incstep = lib::regbit<13, lib::u16, 15, 0>;
    using rcc_spread_spectrum_down_sel = lib::regbit<30>;
    using rcc_spread_spectrum_mod_en = lib::regbit<31>;

    using rcc_plli2s_config_mul = lib::regbit<6, lib::u16, 9, 192>;
    using rcc_plli2s_config_div = lib::regbit<28, lib::u8, 3, 2>;

    struct rcc_t {
        lib::u32 control;
        lib::u32 pll_config;
        lib::u32 config;
        lib::u32 interrupt;
        lib::u32 ahb1_reset;
        lib::u32 ahb2_reset;
        lib::u32 ahb3_reset;
        lib::u32 _unused0;
        lib::u32 apb1_reset;
        lib::u32 apb2_reset;
        lib::u32 _unused1;
        lib::u32 _unused2;
        lib::u32 ahb1_enable;
        lib::u32 ahb2_enable;
        lib::u32 ahb3_enable;
        lib::u32 _unused3;
        lib::u32 apb1_enable;
        lib::u32 apb2_enable;
        lib::u32 _unused4;
        lib::u32 _unused5;
        lib::u32 ahb1lp_enable;
        lib::u32 ahb2lp_enable;
        lib::u32 ahb3lp_enable;
        lib::u32 _unused6;
        lib::u32 apb1lp_enable;
        lib::u32 apb2lp_enable;
        lib::u32 _unused7;
        lib::u32 _unused8;
        lib::u32 backupd_control;
        lib::u32 control_status;
        lib::u32 _unused9;
        lib::u32 _unused10;
        lib::u32 spread_spectrum;
        lib::u32 plli2s_config;
    };
} // namespace Hal

#endif // RCC_T_HH
