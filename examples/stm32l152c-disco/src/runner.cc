#include "runner.hh"

#include "lib/types.hh"
#include "lib/bit.hh"

#include "isr_base.hh"
#include "isr_extend.hh"
#include "hal/adc.hh"
#include "hal/core.hh"
#include "hal/dma.hh"
#include "hal/exti.hh"
#include "hal/gpio.hh"
#include "hal/pwr.hh"
#include "hal/rcc.hh"
#include "hal/rtc.hh"
#include "hal/tim.hh"

#include "bsp/st_hex_lcd.hh"

namespace {
    using ld3_green = hal::p7;
    using ld4_blue = hal::p6;
    const auto all_leds = hal::bits32val<
        ld3_green, ld4_blue>::mask;

    volatile bool foward = true;
    const int add_value = 10;

    volatile int mode = 0;

    volatile lib::u16 adc_values[2];
}

extern "C" void isr::sys_tick_timer() {
    hal::tim4::regs->capt_comp_mode1 ^= lib::regbits16<
        hal::tim_capt_comp_mode_oc2m::val<
            hal::tim_capt_comp_mode_ocm_t::active>
    >::mask;

    mode++;
}

extern "C" void isr::TIM4() {
    if (hal::tim4::regs->status & hal::tim_status_uif::clean<lib::u16>::mask) {
        if (foward) {
            if (hal::tim4::regs->ccr1 < 10)
                foward = false;
            else {
                hal::tim4::regs->ccr1 -= add_value;
                hal::tim4::regs->ccr2 -= add_value;
            }
        } else {
            if (hal::tim4::regs->ccr1 > 1000)
                foward = true;
            else {
                hal::tim4::regs->ccr1 += add_value;
                hal::tim4::regs->ccr2 += add_value;
            }
        }
        hal::tim4::regs->status &= ~hal::tim_status_uif::clean<lib::u16>::mask;
    }
}

extern "C" void isr::RTC_wkup() {
    if (hal::rtc::regs->init_status &
        hal::rtc_init_status_wutf::clean<lib::u32>::mask) {
        runner::view_current_state();

        hal::rtc::regs->init_status &=
            ~hal::rtc_init_status_wutf::clean<lib::u32>::mask;
    }
}

static void setup_gpio() {
    // enable led and lcd port
    hal::rcc::regs->ahb1_enable |=
        lib::regbits32<
            hal::rcc_ahb1_gpioa,
            hal::rcc_ahb1_gpiob,
            hal::rcc_ahb1_gpioc
        >::mask;

    // enable lcd pins
    hal::gpioa::set_mode<hal::pin_mode::alt_func,
        hal::p1, hal::p2, hal::p3, hal::p8, hal::p9, hal::p10, hal::p15>();
    hal::gpioa::set_alt_func<hal::pin_alt::af11,
        hal::p1, hal::p2, hal::p3, hal::p8, hal::p9, hal::p10, hal::p15>();
    hal::gpiob::set_mode<hal::pin_mode::alt_func,
        hal::p3, hal::p4, hal::p5, hal::p8,
        hal::p9, hal::p10, hal::p11, hal::p12,
        hal::p13, hal::p14, hal::p15>();
    hal::gpiob::set_alt_func<hal::pin_alt::af11,
        hal::p3, hal::p4, hal::p5, hal::p8,
        hal::p9, hal::p10, hal::p11, hal::p12,
        hal::p13, hal::p14, hal::p15>();
    hal::gpioc::set_mode<hal::pin_mode::alt_func,
        hal::p0, hal::p1, hal::p2, hal::p3,
        hal::p6, hal::p7, hal::p8, hal::p9,
        hal::p10, hal::p11>();
    hal::gpioc::set_alt_func<hal::pin_alt::af11,
        hal::p0, hal::p1, hal::p2, hal::p3,
        hal::p6, hal::p7, hal::p8, hal::p9,
        hal::p10, hal::p11>();

    // enable led pins, connect to tim4 output
    hal::gpiob::set_mode<hal::pin_mode::alt_func,
        ld3_green, ld4_blue>();
    hal::gpiob::set_alt_func<hal::pin_alt::af2,
        ld3_green, ld4_blue>();
}

static void setup_lcd_pwr() {
    // enable lcd and pwr module
    hal::rcc::regs->apb1_enable |=
        lib::regbits32<
            hal::rcc_apb1_pwr,
            hal::rcc_apb1_lcd
        >::mask;

    // disable clock protection for rtc/lcd
    hal::pwr::regs->control |=
        hal::pwr_control_dbp::clean<lib::u32>::mask;

    // reset clock rtc/lcd
    hal::rcc::regs->control_status |= 
        hal::rcc_control_status_rtcrst::clean<lib::u32>::mask;
    hal::rcc::regs->control_status &= 
        ~hal::rcc_control_status_rtcrst::clean<lib::u32>::mask;

    // enable LSE and wait it stable
    hal::rcc::regs->control_status |= 
        hal::rcc_control_status_lseon::clean<lib::u32>::mask;
    while ((hal::rcc::regs->control_status & 
        hal::rcc_control_status_lserdy::clean<lib::u32>::mask) == 0);

    // set LSE for clocking rtc/lcd
    hal::rcc::regs->control_status |=
        lib::regbits32<
            hal::rcc_control_status_rtc_sel::val<
                hal::rcc_control_status_rtc_sel_t::lse>
        >::mask;
}

static void setup_timer4() {
    // setup tim4
    hal::rcc::regs->apb1_enable |=
        lib::regbits32<
            hal::rcc_apb1_tim4
        >::mask;
    // setup tim4 counter block
    hal::tim4::regs->psc = 40 - 1;
    hal::tim4::regs->arr = 1000;
    // setup tim4 compare blocks 1, 2
    hal::tim4::regs->capt_comp_mode1 =
        lib::regbits16<
            hal::tim_capt_comp_mode_cc1s::val<
                hal::tim_capt_comp_mode_ccs_t::output>,
            hal::tim_capt_comp_mode_cc2s::val<
                hal::tim_capt_comp_mode_ccs_t::output>,
            hal::tim_capt_comp_mode_oc1m::val<
                hal::tim_capt_comp_mode_ocm_t::pwm1>,
            hal::tim_capt_comp_mode_oc2m::val<
                hal::tim_capt_comp_mode_ocm_t::pwm1>
        >::mask;

    hal::tim4::regs->capt_comp_enable =
        lib::regbits16<
            hal::tim_capt_comp_enable_cc1e,
            hal::tim_capt_comp_enable_cc2e
        >::mask;

    // setup value to tim4 compare registers
    hal::tim4::regs->ccr1 = 500;
    hal::tim4::regs->ccr2 = 500;

    hal::tim4::regs->dma_interrupt = lib::regbits16<
        hal::tim_dma_interrupt_uie>::mask;
    // enable tim4
    hal::tim4::regs->control1 = lib::regbits16<
        hal::tim_control1_cen>::mask;
}

void setup_rtc() {
    // enable rtc clock
    hal::rcc::regs->control_status |= 
        hal::rcc_control_status_rtcen::clean<lib::u32>::mask;

    // disable protection
    hal::rtc::regs->write_protect.key = 0xca;
    hal::rtc::regs->write_protect.key = 0x53;

    // enter initialization mode
    hal::rtc::regs->init_status |= 
        hal::rtc_init_status_init::clean<lib::u32>::mask;
    // wait to enter init
    while ((hal::rtc::regs->init_status &
        hal::rtc_init_status_initf::clean<lib::u32>::mask) == 0);

    // setup prescaler value as 32768
    hal::rtc::regs->prescaler = lib::regbits32<
        hal::rtc_prescaler_prediv_s::val<255>, 
        hal::rtc_prescaler_prediv_a::val<127>
        >::mask;
    // setup 24h hour/day format
    // enable direction take value from registers
    // enable wakeup timer interrupt
    // enable wakeup timer
    hal::rtc::regs->control = lib::regbits32<
        hal::rtc_control_fmt::val<false>,
        hal::rtc_control_bypshad,
        hal::rtc_control_wute,
        hal::rtc_control_wutie
        >::mask;
    // setup time & date
    hal::rtc::regs->time = lib::regbits32<
        hal::rtc_time_ht::val<1>,
        hal::rtc_time_hu::val<2>
        >::mask;
    hal::rtc::regs->date = lib::regbits32<
        hal::rtc_date_yt::val<1>,
        hal::rtc_date_yu::val<7>,
        hal::rtc_date_mt::val<0>,
        hal::rtc_date_mu::val<8>,
        hal::rtc_date_dt::val<1>,
        hal::rtc_date_du::val<0>,
        hal::rtc_date_wdu::val<hal::rtc_date_wdu_t::tuesday>
        >::mask;

    // setup wakeup timer
    hal::rtc::regs->wakeup_timer.wut = 2048; // rtcclk/16/2048 -> 1s event

    // exit initialization mode
    hal::rtc::regs->init_status &=
        ~hal::rtc_init_status_init::clean<lib::u32>::mask;

    // enable protection
    hal::rtc::regs->write_protect.key = 0xff;

    // setup EXTI20 -> RTC_wkup to rising edge
    hal::exti->rising_edge_en(20);
    // enable interrupt for EXTI20 -> RTC_wkup
    hal::exti->unmask_int(20);
}

void setup_dma() {
    // enable dma1 power
    hal::rcc::regs->ahb1_enable |=
        lib::regbits32<
            hal::rcc_ahb1_dma1
        >::mask;
    // config dma1 channel 1 (ADC1)
    // disable dma conversion
    hal::dma1_channel1->config.en = 0;
    // memory increment
    hal::dma1_channel1->config.minc = 1;
    // peripheral size 16 bit
    hal::dma1_channel1->config.psize = 0b01;
    // memory size 16 bit
    hal::dma1_channel1->config.msize = 0b01;
    // priority medium
    hal::dma1_channel1->config.pl = 0b01;
    // circular mode
    hal::dma1_channel1->config.circ = 1;
    // setup memory address
    hal::dma1_channel1->memory_address = (lib::u32)adc_values;
    // setup peripheral address
    hal::dma1_channel1->peripheral_address = (lib::u32)&(hal::adc1->dr);
    // setup number conversions
    hal::dma1_channel1->number_of_data = 2;
    // enable dma conversion
    hal::dma1_channel1->config.en = 1;
}

void setup_adc() {
    // enable hsi clock for adc1
    hal::rcc::regs->control |= 
        hal::rcc_control_hsion::clean<lib::u32>::mask;
    while ((hal::rcc::regs->control & 
        hal::rcc_control_hsirdy::clean<lib::u32>::mask) == 0);
    // enable adc module
    hal::rcc::regs->apb2_enable |=
        lib::regbits32<
            hal::rcc_apb2_adc
        >::mask;
    // setup clock to HSI / 4
    hal::adc1_common->control.adcpre = 0b11;
    // enable Temperature sensor (channel 16), Vrefint (channel 17)
    hal::adc1_common->control.tsvrefe = 1;
    // wait for enable Vrefint
    while ((hal::pwr::regs->control_status &
        hal::pwr_control_status_vrefintrdyf::clean<lib::u32>::mask) == 0);
    // scan mode enabled
    hal::adc1->control1.scan = 1;
    // continuous conversion
    hal::adc1->control2.cont = 1;
    // dma mode enable
    hal::adc1->control2.dma = 1;
    // dma disable selection
    hal::adc1->control2.dds = 1;
    // disable adc low power mode
    hal::adc1->control2.adon = 1;
    // switch to bank A
    hal::adc1->control2.adc_cfg = 0;
    // wait for setup adc1 hw
    while (hal::adc1->status.adons == 0);
    // setup 17 channel - vref internal, 16 channel - Temperature
    hal::adc1->set_regular_sequence(17, 0);
    hal::adc1->set_sample_time(7, 17);
    hal::adc1->set_regular_sequence(16, 1);
    hal::adc1->set_sample_time(7, 16);
    hal::adc1->set_regular_sequence(1, 28);
    // wait for setup regular channel
    while (hal::adc1->status.rcnr == 1);

    // clear eoc
    hal::adc1->status.eoc = 0;
    // start conversion
    hal::adc1->control2.swstart = 1;
}

void runner::view_current_state() {
    bsp::st_hex_lcd lcd;

    switch (mode) {
        case 0: {
            lib::u32 time = hal::rtc::regs->time;
            lcd.wait_update()
                .clear(0)
                .write_digit(0, hal::rtc_time_ht::get_val(time))
                .clear(1)
                .write_digit(1, hal::rtc_time_hu::get_val(time))
                .write_col(1)
                .clear(2)
                .write_digit(2, hal::rtc_time_mnt::get_val(time))
                .clear(3)
                .write_digit(3, hal::rtc_time_mnu::get_val(time))
                .write_col(3)
                .clear(4)
                .write_digit(4, hal::rtc_time_st::get_val(time))
                .clear(5)
                .write_digit(5, hal::rtc_time_su::get_val(time))
                .update();
                break;
        }
        case 1: {
            lib::u32 date = hal::rtc::regs->date;
            lcd.wait_update()
                .clear(0)
                .write_digit(0, hal::rtc_date_yt::get_val(date))
                .clear(1)
                .write_digit(1, hal::rtc_date_yu::get_val(date))
                .write_dp(1)
                .clear(2)
                .write_digit(2, hal::rtc_date_mt::get_val(date))
                .clear(3)
                .write_digit(3, hal::rtc_date_mu::get_val(date))
                .write_dp(3)
                .clear(4)
                .write_digit(4, hal::rtc_date_dt::get_val(date))
                .clear(5)
                .write_digit(5, hal::rtc_date_du::get_val(date))
                .update();
                break;
        }
        case 2: {
            lib::u32 adc_value = *(lib::u16 *)0x1ff800f8 * 3000;
            // get data
            adc_value /= adc_values[0];

            lcd.wait_update()
                .clear(0)
                .write_digit(0, adc_value / 1000 % 10)
                .write_dp(0)
                .clear(1)
                .write_digit(1, adc_value / 100 % 10)
                .clear(2)
                .write_digit(2, adc_value / 10 % 10)
                .clear(3)
                .write_digit(3, adc_value % 10)
                .clear(4)
                .write_char(4, 'V')
                .clear(5)
                .write_char(5, 'R')
                .update();
            break;
        }
        case 3: {
            lib::s32 adc_value = (110 - 30) * 100 / (*(lib::u16 *)0x1ff800fe - *(lib::u16 *)0x1ff800fa);
            // get data
            adc_value = adc_value * (adc_values[1] - *(lib::u16 *)0x1ff800fa) + 3000;

            lcd.wait_update()
                .clear(0)
                .write_digit(0, adc_value / 1000 % 10)
                .clear(1)
                .write_digit(1, adc_value / 100 % 10)
                .write_dp(1)
                .clear(2)
                .write_digit(2, adc_value / 10 % 10)
                .clear(3)
                .write_digit(3, adc_value % 10)
                .clear(4)
                .write_char(4, 'T')
                .clear(5)
                .write_char(5, 'R')
                .update();
            break;
        }
        default:
            mode = 0;
            break;
    }
}

void runner::run() {
    bsp::st_hex_lcd lcd;

    setup_gpio();
    setup_timer4();
    setup_lcd_pwr();
    setup_rtc();
    setup_dma();
    setup_adc();
    lcd.setup();

    view_current_state();

    // setup irq for sys_tick and enable it irq
    hal::nvic::enable_irq<hal::irq_n_t, hal::irq_n_t::sys_tick_timer>();
    hal::sys_tick::config<8000000>();
    // setup irq for tim4
    hal::nvic::enable_irq<hal::irq_dev_n_t, hal::irq_dev_n_t::TIM4>();
    // setup irq for rtc wakeup
    hal::nvic::enable_irq<hal::irq_dev_n_t, hal::irq_dev_n_t::RTC_wkup>();
}
