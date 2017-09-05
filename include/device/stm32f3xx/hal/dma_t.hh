#ifndef DMA_T_HH
#define DMA_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using dma_interrupt_gif1 = lib::regbit<0>;
    using dma_interrupt_tcif1 = lib::regbit<1>;
    using dma_interrupt_htif1 = lib::regbit<2>;
    using dma_interrupt_teif1 = lib::regbit<3>;
    using dma_interrupt_gif2 = lib::regbit<4>;
    using dma_interrupt_tcif2 = lib::regbit<5>;
    using dma_interrupt_htif2 = lib::regbit<6>;
    using dma_interrupt_teif2 = lib::regbit<7>;
    using dma_interrupt_gif3 = lib::regbit<8>;
    using dma_interrupt_tcif3 = lib::regbit<9>;
    using dma_interrupt_htif3 = lib::regbit<10>;
    using dma_interrupt_teif3 = lib::regbit<11>;
    using dma_interrupt_gif4 = lib::regbit<12>;
    using dma_interrupt_tcif4 = lib::regbit<13>;
    using dma_interrupt_htif4 = lib::regbit<14>;
    using dma_interrupt_teif4 = lib::regbit<15>;
    using dma_interrupt_gif5 = lib::regbit<16>;
    using dma_interrupt_tcif5 = lib::regbit<17>;
    using dma_interrupt_htif5 = lib::regbit<18>;
    using dma_interrupt_teif5 = lib::regbit<19>;
    using dma_interrupt_gif6 = lib::regbit<20>;
    using dma_interrupt_tcif6 = lib::regbit<21>;
    using dma_interrupt_htif6 = lib::regbit<22>;
    using dma_interrupt_teif6 = lib::regbit<23>;
    using dma_interrupt_gif7 = lib::regbit<24>;
    using dma_interrupt_tcif7 = lib::regbit<25>;
    using dma_interrupt_htif7 = lib::regbit<26>;
    using dma_interrupt_teif7 = lib::regbit<27>;

    template <lib::u32 addr>
    struct dma_d {
        struct dma_t {
            lib::u32 interrupt_status;
            lib::u32 interrupt_clear;
        };

        static constexpr volatile dma_t * const regs =
            reinterpret_cast<dma_t *>(addr);
    };

    using dma_channel_config_en = lib::regbit<0>;
    using dma_channel_config_tcie = lib::regbit<1>;
    using dma_channel_config_htie = lib::regbit<2>;
    using dma_channel_config_teie = lib::regbit<3>;
    using dma_channel_config_dir = lib::regbit<4>;
    using dma_channel_config_circ = lib::regbit<5>;
    using dma_channel_config_pinc = lib::regbit<6>;
    using dma_channel_config_minc = lib::regbit<7>;
    enum struct dma_channel_config_size_t : lib::u8 {
        by8bit = 0b00,
        by16bit = 0b01,
        by32bit = 0b10
    };
    using dma_channel_config_psize =
        lib::regbit<8,
            dma_channel_config_size_t,
            2,
            dma_channel_config_size_t::by8bit>;
    using dma_channel_config_msize =
        lib::regbit<10,
            dma_channel_config_size_t,
            2,
            dma_channel_config_size_t::by8bit>;
    enum struct dma_channel_config_pl_t : lib::u8 {
        low = 0b00,
        medium = 0b01,
        high = 0b10,
        very_high = 0b11
    };
    using dma_channel_config_pl =
        lib::regbit<12,
            dma_channel_config_pl_t,
            2,
            dma_channel_config_pl_t::low>;
    using dma_channel_config_mem2mem = lib::regbit<14>;

    template <lib::u32 addr>
    struct dma_channel_d {
        struct dma_channel_t {
            lib::u32 config;
            lib::u32 number_of_data;
            lib::u32 peripheral_address;
            lib::u32 memory_address;
        };

        static constexpr volatile dma_channel_t * const regs =
            reinterpret_cast<dma_channel_t *>(addr);
    };
}

#endif // DMA_T_HH
