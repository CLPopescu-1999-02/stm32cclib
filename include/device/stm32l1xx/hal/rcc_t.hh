#ifndef RCC_T_HH
#define RCC_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using rcc_control_hsion = lib::regbit<0>;
    using rcc_control_hsirdy = lib::regbit<1>;
    using rcc_control_msion = lib::regbit<8>;
    using rcc_control_msirdy = lib::regbit<9>;
    using rcc_control_hseon = lib::regbit<16>;
    using rcc_control_hserdy = lib::regbit<17>;
    using rcc_control_hsebyp = lib::regbit<18>;
    using rcc_control_pllon = lib::regbit<24>;
    using rcc_control_pllrdy = lib::regbit<25>;
    using rcc_control_csson = lib::regbit<28>;
    enum struct rcc_control_rtc_pre_t : lib::u8 {
        by2 = 0b00,
        by4 = 0b01,
        by8 = 0b10,
        by16 = 0b11
    };
    using rcc_control_rtc_pre = lib::regbit<29,
        rcc_control_rtc_pre_t,
        2,
        rcc_control_rtc_pre_t::by2>;

    using rcc_calibration_hsical = lib::regbit8<0, 8>;
    using rcc_calibration_hsitrim = lib::regbit8<8, 5>;
    enum struct rcc_calibration_msirange_t : lib::u8 {
        around65_536kHz = 0b000,
        around131_072kHz = 0b001,
        around262_144kHz = 0b010,
        around524_288kHz = 0b011,
        around1_048MHz = 0b100,
        around2_097MHz = 0b101,
        around4_194MHz = 0b110
    };
    using rcc_calibration_msirange = lib::regbit<13,
        rcc_calibration_msirange_t,
        3,
        rcc_calibration_msirange_t::around2_097MHz>;
    using rcc_calibration_msical = lib::regbit8<16, 8>;
    using rcc_calibration_msitrim = lib::regbit8<24, 8>;

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
    using rcc_config_pll_src = lib::regbit<16>;
    enum struct rcc_config_pllmul_t : lib::u8 {
        x3 = 0b0000,
        x4 = 0b0001,
        x6 = 0b0010,
        x8 = 0b0011,
        x12 = 0b0100,
        x16 = 0b0101,
        x24 = 0b0110,
        x32 = 0b0111,
        x48 = 0b1000
    };
    using rcc_config_pllmul =
        lib::regbit<18,
            rcc_config_pllmul_t,
            4,
            rcc_config_pllmul_t::x3>;
    enum struct rcc_config_plldiv_t : lib::u8 {
        by2 = 0b01,
        by3 = 0b10,
        by4 = 0b11
    };
    using rcc_config_plldiv =
        lib::regbit<22,
            rcc_config_plldiv_t,
            2,
            rcc_config_plldiv_t::by2>;
    enum struct rcc_config_mco_t : lib::u8 {
        mco = 0b000,
        sysclk = 0b001,
        hsi = 0b010,
        msi = 0b011,
        hse = 0b100,
        pll = 0b101,
        lsi = 0b110,
        lse = 0b111
    };
    using rcc_config_mco =
        lib::regbit<24,
            rcc_config_mco_t,
            3,
            rcc_config_mco_t::hsi>;
    enum struct rcc_config_mco_pre_t : lib::u8 {
        not_div = 0b000,
        by2 = 0b100,
        by4 = 0b101,
        by8 = 0b110,
        by16 = 0b111,
    };
    using rcc_config_mco_pre =
        lib::regbit<28,
            rcc_config_mco_pre_t,
            3,
            rcc_config_mco_pre_t::not_div>;

    using rcc_interrupt_lsirdyf = lib::regbit<0>;
    using rcc_interrupt_lserdyf = lib::regbit<1>;
    using rcc_interrupt_hsirdyf = lib::regbit<2>;
    using rcc_interrupt_hserdyf = lib::regbit<3>;
    using rcc_interrupt_pllrdyf = lib::regbit<4>;
    using rcc_interrupt_msirdyf = lib::regbit<5>;
    using rcc_interrupt_lsecssf = lib::regbit<6>;
    using rcc_interrupt_cssf = lib::regbit<7>;
    using rcc_interrupt_lsirdyie = lib::regbit<8>;
    using rcc_interrupt_lserdyie = lib::regbit<9>;
    using rcc_interrupt_hsirdyie = lib::regbit<10>;
    using rcc_interrupt_hserdyie = lib::regbit<11>;
    using rcc_interrupt_pllrdyie = lib::regbit<12>;
    using rcc_interrupt_msirdyie = lib::regbit<13>;
    using rcc_interrupt_lsecssie = lib::regbit<13>;
    using rcc_interrupt_lsirdyc = lib::regbit<16>;
    using rcc_interrupt_lserdyc = lib::regbit<17>;
    using rcc_interrupt_hsirdyc = lib::regbit<18>;
    using rcc_interrupt_hserdyc = lib::regbit<19>;
    using rcc_interrupt_pllrdyc = lib::regbit<20>;
    using rcc_interrupt_msirdyc = lib::regbit<21>;
    using rcc_interrupt_lsecssc = lib::regbit<21>;
    using rcc_interrupt_cssc = lib::regbit<23>;

    using rcc_ahb1_gpioa = lib::regbit<0>;
    using rcc_ahb1_gpiob = lib::regbit<1>;
    using rcc_ahb1_gpioc = lib::regbit<2>;
    using rcc_ahb1_gpiod = lib::regbit<3>;
    using rcc_ahb1_gpioe = lib::regbit<4>;
    using rcc_ahb1_gpiof = lib::regbit<5>;
    using rcc_ahb1_gpiog = lib::regbit<6>;
    using rcc_ahb1_crc = lib::regbit<12>;
    using rcc_ahb1_flitf = lib::regbit<15>;
    using rcc_ahb1_dma1 = lib::regbit<24>;
    using rcc_ahb1_dma2 = lib::regbit<25>;
    using rcc_ahb1_aes = lib::regbit<27>;
    using rcc_ahb1_fsmc = lib::regbit<30>;

    using rcc_apb2_syscfg = lib::regbit<0>;
    using rcc_apb2_tim9 = lib::regbit<2>;
    using rcc_apb2_tim10 = lib::regbit<3>;
    using rcc_apb2_tim11 = lib::regbit<4>;
    using rcc_apb2_adc = lib::regbit<9>;
    using rcc_apb2_sdio = lib::regbit<11>;
    using rcc_apb2_spi1 = lib::regbit<12>;
    using rcc_apb2_usart1 = lib::regbit<14>;

    using rcc_apb1_tim2 = lib::regbit<0>;
    using rcc_apb1_tim3 = lib::regbit<1>;
    using rcc_apb1_tim4 = lib::regbit<2>;
    using rcc_apb1_tim5 = lib::regbit<3>;
    using rcc_apb1_tim6 = lib::regbit<4>;
    using rcc_apb1_tim7 = lib::regbit<5>;
    using rcc_apb1_lcd = lib::regbit<9>;
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
    using rcc_apb1_pwr = lib::regbit<28>;
    using rcc_apb1_dac = lib::regbit<29>;
    using rcc_apb1_comp = lib::regbit<31>;

    using rcc_control_status_lsion = lib::regbit<0>;
    using rcc_control_status_lsirdy = lib::regbit<1>;
    using rcc_control_status_lseon = lib::regbit<8>;
    using rcc_control_status_lserdy = lib::regbit<9>;
    using rcc_control_status_lsebyp = lib::regbit<10>;
    using rcc_control_status_lsecsson = lib::regbit<11>;
    using rcc_control_status_lsecssd = lib::regbit<12>;
    enum struct rcc_control_status_rtc_sel_t : lib::u8 {
        no_clock = 0b00,
        lse = 0b01,
        lsi = 0b10,
        hse = 0b11
    };
    using rcc_control_status_rtc_sel =
        lib::regbit<16,
            rcc_control_status_rtc_sel_t,
            2,
            rcc_control_status_rtc_sel_t::no_clock>;
    using rcc_control_status_rtcen = lib::regbit<22>;
    using rcc_control_status_rtcrst = lib::regbit<23>;
    using rcc_control_status_rmvf = lib::regbit<24>;
    using rcc_control_status_borrstf = lib::regbit<25>;
    using rcc_control_status_pinrstf = lib::regbit<26>;
    using rcc_control_status_porrstf = lib::regbit<27>;
    using rcc_control_status_sftrstf = lib::regbit<28>;
    using rcc_control_status_iwdgrstf = lib::regbit<29>;
    using rcc_control_status_wwdgrstf = lib::regbit<30>;
    using rcc_control_status_lpwrrstf = lib::regbit<31>;

    template <lib::u32 addr>
    struct rcc_d {
        struct rcc_t {
            lib::u32 control;
            lib::u32 calibration;
            lib::u32 config;
            lib::u32 interrupt;
            lib::u32 ahb1_reset;
            lib::u32 apb2_reset;
            lib::u32 apb1_reset;
            lib::u32 ahb1_enable;
            lib::u32 apb2_enable;
            lib::u32 apb1_enable;
            lib::u32 ahb1_lp_enable;
            lib::u32 apb2_lp_enable;
            lib::u32 apb1_lp_enable;
            lib::u32 control_status;
        };

        static constexpr volatile rcc_t * const regs =
            reinterpret_cast<rcc_t *>(addr);
    };
} // namespace Hal

#endif // RCC_T_HH
