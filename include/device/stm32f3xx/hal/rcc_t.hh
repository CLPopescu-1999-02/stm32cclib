#ifndef RCC_T_HH
#define RCC_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using rcc_control_hsion = lib::regbit<0>;
    using rcc_control_hsirdy = lib::regbit<1>;
    using rcc_control_hsitrim = lib::regbit8<3, 5>;
    using rcc_control_hsical = lib::regbit8<8, 8>;
    using rcc_control_hseon = lib::regbit<16>;
    using rcc_control_hserdy = lib::regbit<17>;
    using rcc_control_hsebyp = lib::regbit<18>;
    using rcc_control_csson = lib::regbit<19>;
    using rcc_control_pllon = lib::regbit<24>;
    using rcc_control_pllrdy = lib::regbit<25>;

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
        lib::regbit<8,
            rcc_config_apb_pre_t,
            3,
            rcc_config_apb_pre_t::not_div>;
    using rcc_config_apb2_pre =
        lib::regbit<11,
            rcc_config_apb_pre_t,
            3,
            rcc_config_apb_pre_t::not_div>;
    using rcc_config_pllsrc = lib::regbit<16>;
    using rcc_config_pllxtpre = lib::regbit<17>;
    using rcc_config_pllmul = lib::regbit8<18, 4, 0>;
    using rcc_config_usbpre = lib::regbit<22>;
    using rcc_config_i2s_ext_src = lib::regbit<23>;
    enum struct rcc_config_mco_t : lib::u8 {
        disabled = 0b000,
        lsi = 0b010,
        lse = 0b011,
        sysclk = 0b100,
        hsi = 0b101,
        hse = 0b110,
        pllby2 = 0b11
    };
    using rcc_config_mco =
        lib::regbit<24,
            rcc_config_mco_t,
            3,
            rcc_config_mco_t::hsi>;
    using rcc_config_mcof = lib::regbit<28>;

    using rcc_interrupt_lsirdyf = lib::regbit<0>;
    using rcc_interrupt_lserdyf = lib::regbit<1>;
    using rcc_interrupt_hsirdyf = lib::regbit<2>;
    using rcc_interrupt_hserdyf = lib::regbit<3>;
    using rcc_interrupt_pllrdyf = lib::regbit<4>;
    using rcc_interrupt_cssf = lib::regbit<7>;
    using rcc_interrupt_lsirdyie = lib::regbit<8>;
    using rcc_interrupt_lserdyie = lib::regbit<9>;
    using rcc_interrupt_hsirdyie = lib::regbit<10>;
    using rcc_interrupt_hserdyie = lib::regbit<11>;
    using rcc_interrupt_pllrdyie = lib::regbit<12>;
    using rcc_interrupt_lsirdyc = lib::regbit<16>;
    using rcc_interrupt_lserdyc = lib::regbit<17>;
    using rcc_interrupt_hsirdyc = lib::regbit<18>;
    using rcc_interrupt_hserdyc = lib::regbit<19>;
    using rcc_interrupt_pllrdyc = lib::regbit<20>;
    using rcc_interrupt_cssc = lib::regbit<23>;

    using rcc_apb2_syscfg = lib::regbit<0>;
    using rcc_apb2_tim1 = lib::regbit<11>;
    using rcc_apb2_spi1 = lib::regbit<12>;
    using rcc_apb2_tim8 = lib::regbit<13>;
    using rcc_apb2_usart1 = lib::regbit<14>;
    using rcc_apb2_tim15 = lib::regbit<16>;
    using rcc_apb2_tim16 = lib::regbit<17>;
    using rcc_apb2_tim17 = lib::regbit<18>;

    using rcc_apb1_tim2 = lib::regbit<0>;
    using rcc_apb1_tim3 = lib::regbit<1>;
    using rcc_apb1_tim4 = lib::regbit<2>;
    using rcc_apb1_tim6 = lib::regbit<4>;
    using rcc_apb1_tim7 = lib::regbit<5>;
    using rcc_apb1_wwdg = lib::regbit<11>;
    using rcc_apb1_spi2 = lib::regbit<14>;
    using rcc_apb1_spi3 = lib::regbit<15>;
    using rcc_apb1_usart2 = lib::regbit<17>;
    using rcc_apb1_usart3 = lib::regbit<18>;
    using rcc_apb1_uart4 = lib::regbit<19>;
    using rcc_apb1_uart5 = lib::regbit<20>;
    using rcc_apb1_i2c1 = lib::regbit<21>;
    using rcc_apb1_i2c2 = lib::regbit<22>;
    using rcc_apb1_usb = lib::regbit<23>;
    using rcc_apb1_can = lib::regbit<25>;
    using rcc_apb1_pwr = lib::regbit<28>;
    using rcc_apb1_dac = lib::regbit<29>;

    using rcc_ahb1_dam1 = lib::regbit<0>;
    using rcc_ahb1_dma2 = lib::regbit<1>;
    using rcc_ahb1_sram = lib::regbit<2>;
    using rcc_ahb1_flitf = lib::regbit<4>;
    using rcc_ahb1_crc = lib::regbit<6>;
    using rcc_ahb1_gpioa = lib::regbit<17>;
    using rcc_ahb1_gpiob = lib::regbit<18>;
    using rcc_ahb1_gpioc = lib::regbit<19>;
    using rcc_ahb1_gpiod = lib::regbit<20>;
    using rcc_ahb1_gpioe = lib::regbit<21>;
    using rcc_ahb1_gpiof = lib::regbit<22>;
    using rcc_ahb1_tsc = lib::regbit<24>;
    using rcc_ahb1_adc12 = lib::regbit<28>;
    using rcc_ahb1_adc34 = lib::regbit<29>;

    using rcc_backupd_control_lseon = lib::regbit<0>;
    using rcc_backupd_control_lserdy = lib::regbit<1>;
    using rcc_backupd_control_lsebyp = lib::regbit<2>;
    enum struct rcc_backupd_control_lsedrv_t : lib::u8 {
        lower = 0b00,
        medium_low = 0b01,
        medium_high = 0b10,
        higher = 0b11
    };
    using rcc_backupd_control_lsedrv =
        lib::regbit<3,
            rcc_backupd_control_lsedrv_t,
            2,
            rcc_backupd_control_lsedrv_t::lower>;
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
    using rcc_control_status_oblrstf = lib::regbit<25>;
    using rcc_control_status_pinrstf = lib::regbit<26>;
    using rcc_control_status_porrstf = lib::regbit<27>;
    using rcc_control_status_sftrstf = lib::regbit<28>;
    using rcc_control_status_iwdgrstf = lib::regbit<29>;
    using rcc_control_status_wwdgrstf = lib::regbit<30>;
    using rcc_control_status_lpwrrstf = lib::regbit<31>;

    using rcc_config2_prediv = lib::regbit8<0, 4>;
    enum struct rcc_config2_adcpres_t : lib::u8 {
        disable = 0b00000,
        by1 = 0b10000,
        by2 = 0b10001,
        by4 = 0b10010,
        by6 = 0b10011,
        by8 = 0b10100,
        by10 = 0b10101,
        by12 = 0b10110,
        by16 = 0b10111,
        by32 = 0b11000,
        by64 = 0b11001,
        by128 = 0b11010,
        by256 = 0b11011
    };
    using rcc_config2_adc12pres =
        lib::regbit<8,
            rcc_config2_adcpres_t,
            2,
            rcc_config2_adcpres_t::disable>;
    using rcc_config2_adc34pres =
        lib::regbit<8,
            rcc_config2_adcpres_t,
            2,
            rcc_config2_adcpres_t::disable>;

    enum struct rcc_config3_clk_src_t : lib::u8 {
        pclk = 0b00,
        sysclk = 0b01,
        lse = 0b10,
        hsi = 0b11
    };
    using rcc_config3_usart1sw =
        lib::regbit<0,
            rcc_config3_clk_src_t,
            2,
            rcc_config3_clk_src_t::pclk>;
    using rcc_config3_i2c1sw = lib::regbit<4>;
    using rcc_config3_i2c2sw = lib::regbit<5>;
    using rcc_config3_tim1sw = lib::regbit<8>;
    using rcc_config3_tim8sw = lib::regbit<9>;
    using rcc_config3_usart2sw =
        lib::regbit<16,
            rcc_config3_clk_src_t,
            2,
            rcc_config3_clk_src_t::pclk>;
    using rcc_config3_usart3sw =
        lib::regbit<18,
            rcc_config3_clk_src_t,
            2,
            rcc_config3_clk_src_t::pclk>;
    using rcc_config3_usart4sw =
        lib::regbit<20,
            rcc_config3_clk_src_t,
            2,
            rcc_config3_clk_src_t::pclk>;
    using rcc_config3_usart5sw =
        lib::regbit<22,
            rcc_config3_clk_src_t,
            2,
            rcc_config3_clk_src_t::pclk>;

    template <lib::u32 addr>
    struct rcc_d {
        struct rcc_t {
            lib::u32 control;
            lib::u32 config;
            lib::u32 interrupt;
            lib::u32 apb2_reset;
            lib::u32 apb1_reset;
            lib::u32 ahb1_enable;
            lib::u32 apb2_enable;
            lib::u32 apb1_enable;
            lib::u32 backupd_control;
            lib::u32 control_status;
            lib::u32 ahb1_reset;
            lib::u32 config2;
            lib::u32 config3;
        };

        static constexpr volatile rcc_t & regs() {
            return *reinterpret_cast<rcc_t *>(addr);
        }
    };
} // namespace Hal

#endif // RCC_T_HH
