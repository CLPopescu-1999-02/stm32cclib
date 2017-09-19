#ifndef DAC_COMMON_T_HH
#define DAC_COMMON_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using dac_control_en1 = lib::regbit<0>;
    using dac_control_boff1 = lib::regbit<1>;
    using dac_control_ten1 = lib::regbit<2>;
    enum struct dac_control_wave_t : lib::u8 {
        disable = 0b00,
        noise_wave = 0b01,
        triangle_wave = 0b10
    };
    using dac_control_wave1 =
        lib::regbit<6,
            dac_control_wave_t,
            2,
            dac_control_wave_t::disable>;
    enum struct dac_control_mamp_t : lib::u8 {
        eq1 = 0,
        eq3,
        eq7,
        eq15,
        eq31,
        eq63,
        eq127,
        eq255,
        eq511,
        eq1023,
        eq2047,
        eq4095
    };
    using dac_control_mamp1 =
        lib::regbit<8,
            dac_control_mamp_t,
            4,
            dac_control_mamp_t::eq1>;
    using dac_control_dmaen1 = lib::regbit<12>;
    using dac_control_damudrie1 = lib::regbit<13>;
    using dac_control_en2 = lib::regbit<16>;
    using dac_control_boff2 = lib::regbit<17>;
    using dac_control_ten2 = lib::regbit<18>;
    using dac_control_wave2 =
        lib::regbit<22,
            dac_control_wave_t,
            2,
            dac_control_wave_t::disable>;
    using dac_control_mamp2 =
        lib::regbit<24,
            dac_control_mamp_t,
            4,
            dac_control_mamp_t::eq1>;
    using dac_control_dmaen2 = lib::regbit<28>;
    using dac_control_damudrie2 = lib::regbit<29>;

    using dac_sw_trigger_swtrig1 = lib::regbit<0>;
    using dac_sw_trigger_swtrig2 = lib::regbit<1>;

    using dac_status_dmaudr1 = lib::regbit<13>;
    using dac_status_dmaudr2 = lib::regbit<29>;

    template <lib::u32 addr>
    struct dac_d {
        struct dac_t {
            lib::u32 control;
            lib::u32 sw_trigger;
            lib::u32 dhr12r1;
            lib::u32 dhr12l1;
            lib::u32 dhr8r1;
            lib::u32 dhr12r2;
            lib::u32 dhr12l2;
            lib::u32 dhr8r2;
            lib::u32 dhr12rd;
            lib::u32 dhr12ld;
            lib::u32 dhr8rd;
            lib::u32 dor1;
            lib::u32 dor2;
            lib::u32 status;
        };

        static constexpr volatile dac_t * const regs =
            reinterpret_cast<dac_t *>(addr);
    };
}

#endif // DAC_COMMON_T_HH
