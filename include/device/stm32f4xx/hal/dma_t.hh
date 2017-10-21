#ifndef DMA_T_HH
#define DMA_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using dma_interrupt_feif1 = lib::regbit<0>;
    using dma_interrupt_dmeif1 = lib::regbit<2>;
    using dma_interrupt_teif1 = lib::regbit<3>;
    using dma_interrupt_htif1 = lib::regbit<4>;
    using dma_interrupt_hcif1 = lib::regbit<5>;
    using dma_interrupt_feif2 = lib::regbit<6>;
    using dma_interrupt_dmeif2 = lib::regbit<8>;
    using dma_interrupt_teif2 = lib::regbit<9>;
    using dma_interrupt_htif2 = lib::regbit<10>;
    using dma_interrupt_hcif2 = lib::regbit<11>;
    using dma_interrupt_feif3 = lib::regbit<16>;
    using dma_interrupt_dmeif3 = lib::regbit<18>;
    using dma_interrupt_teif3 = lib::regbit<19>;
    using dma_interrupt_htif3 = lib::regbit<20>;
    using dma_interrupt_hcif3 = lib::regbit<21>;
    using dma_interrupt_feif4 = lib::regbit<22>;
    using dma_interrupt_dmeif4 = lib::regbit<24>;
    using dma_interrupt_teif4 = lib::regbit<25>;
    using dma_interrupt_htif4 = lib::regbit<26>;
    using dma_interrupt_hcif4 = lib::regbit<27>;

    using dma_interrupt_feif5 = lib::regbit<0>;
    using dma_interrupt_dmeif5 = lib::regbit<2>;
    using dma_interrupt_teif5 = lib::regbit<3>;
    using dma_interrupt_htif5 = lib::regbit<4>;
    using dma_interrupt_hcif5 = lib::regbit<5>;
    using dma_interrupt_feif6 = lib::regbit<6>;
    using dma_interrupt_dmeif6 = lib::regbit<8>;
    using dma_interrupt_teif6 = lib::regbit<9>;
    using dma_interrupt_htif6 = lib::regbit<10>;
    using dma_interrupt_hcif6 = lib::regbit<11>;
    using dma_interrupt_feif7 = lib::regbit<16>;
    using dma_interrupt_dmeif7 = lib::regbit<18>;
    using dma_interrupt_teif7 = lib::regbit<19>;
    using dma_interrupt_htif7 = lib::regbit<20>;
    using dma_interrupt_hcif7 = lib::regbit<21>;
    using dma_interrupt_feif8 = lib::regbit<22>;
    using dma_interrupt_dmeif8 = lib::regbit<24>;
    using dma_interrupt_teif8 = lib::regbit<25>;
    using dma_interrupt_htif8 = lib::regbit<26>;
    using dma_interrupt_hcif8 = lib::regbit<27>;

    template <lib::u32 addr>
    struct dma_d {
        struct dma_t {
            lib::u32 interrupt_status[2];
            lib::u32 interrupt_clear[2];
        };

        static constexpr volatile dma_t & regs() {
            return reinterpret_cast<dma_t *>(addr);
        }
    };

    using dma_channel_config_en = lib::regbit<0>;
    using dma_channel_config_dmeie = lib::regbit<1>;
    using dma_channel_config_teie = lib::regbit<2>;
    using dma_channel_config_htie = lib::regbit<3>;
    using dma_channel_config_tcie = lib::regbit<4>;
    using dma_channel_config_pfctrl = lib::regbit<5>;
    enum struct dma_channel_config_dir_t : lib::u8 {
        periph_to_mem = 0b00,
        mem_to_periph = 0b01,
        mem_to_mem = 0b11
    };
    using dma_channel_config_dir =
        lib::regbit<6,
        dma_channel_config_dir_t,
        2,
        dma_channel_config_dir_t::periph_to_mem>;
    using dma_channel_config_circ = lib::regbit<8>;
    using dma_channel_config_pinc = lib::regbit<9>;
    using dma_channel_config_minc = lib::regbit<10>;
    enum struct dma_channel_config_size_t : lib::u8 {
        by8bit = 0b00,
        by16bit = 0b01,
        by32bit = 0b10
    };
    using dma_channel_config_psize =
        lib::regbit<11,
            dma_channel_config_size_t,
            2,
            dma_channel_config_size_t::by8bit>;
    using dma_channel_config_msize =
        lib::regbit<13,
            dma_channel_config_size_t,
            2,
            dma_channel_config_size_t::by8bit>;
    using dma_channel_config_minc = lib::regbit<15>;
    enum struct dma_channel_config_pl_t : lib::u8 {
        low = 0b00,
        medium = 0b01,
        high = 0b10,
        very_high = 0b11
    };
    using dma_channel_config_pl =
        lib::regbit<16,
            dma_channel_config_pl_t,
            2,
            dma_channel_config_pl_t::low>;
    using dma_channel_config_dbm = lib::regbit<18>;
    using dma_channel_config_ct = lib::regbit<19>;
    enum struct dma_channel_config_brust_t : lib::u8 {
        single = 0b00,
        incr4 = 0b01,
        incr8 = 0b10,
        incr16 = 0b11
    };
    using dma_channel_config_pbrust =
        lib::regbit<21,
            dma_channel_config_brust_t,
            2,
            dma_channel_config_brust_t::single>;
    using dma_channel_config_mbrust =
        lib::regbit<23,
            dma_channel_config_brust_t,
            2,
            dma_channel_config_brust_t::single>;
    using dma_channel_config_chsel = lib::regbit8<25, 3>;

    template <lib::u32 addr>
    struct dma_channel_d {
        struct dma_channel_t {
            lib::u32 config;
            lib::u32 number_of_data;
            lib::u32 peripheral_address;
            lib::u32 memory_address0;
            lib::u32 memory_address1;
        };

        static constexpr volatile dma_channel_t & regs() {
            return *reinterpret_cast<dma_channel_t *>(addr);
        }
    };
}

#endif // DMA_T_HH
