#ifndef DMA_HH
#define DMA_HH

#include "lib/types.hh"

namespace hal {
    struct dma_interrupt_status_t {
        lib::u32 gif1:1;
        lib::u32 tcif1:1;
        lib::u32 htif1:1;
        lib::u32 teif1:1;
        lib::u32 gif2:1;
        lib::u32 tcif2:1;
        lib::u32 htif2:1;
        lib::u32 teif2:1;
        lib::u32 gif3:1;
        lib::u32 tcif3:1;
        lib::u32 htif3:1;
        lib::u32 teif3:1;
        lib::u32 gif4:1;
        lib::u32 tcif4:1;
        lib::u32 htif4:1;
        lib::u32 teif4:1;
        lib::u32 gif5:1;
        lib::u32 tcif5:1;
        lib::u32 htif5:1;
        lib::u32 teif5:1;
        lib::u32 gif6:1;
        lib::u32 tcif6:1;
        lib::u32 htif6:1;
        lib::u32 teif6:1;
        lib::u32 gif7:1;
        lib::u32 tcif7:1;
        lib::u32 htif7:1;
        lib::u32 teif7:1;
        lib::u32 _unused0:4;
    };

    struct dma_interrupt_clear_t {
        lib::u32 gif1:1;
        lib::u32 tcif1:1;
        lib::u32 htif1:1;
        lib::u32 teif1:1;
        lib::u32 gif2:1;
        lib::u32 tcif2:1;
        lib::u32 htif2:1;
        lib::u32 teif2:1;
        lib::u32 gif3:1;
        lib::u32 tcif3:1;
        lib::u32 htif3:1;
        lib::u32 teif3:1;
        lib::u32 gif4:1;
        lib::u32 tcif4:1;
        lib::u32 htif4:1;
        lib::u32 teif4:1;
        lib::u32 gif5:1;
        lib::u32 tcif5:1;
        lib::u32 htif5:1;
        lib::u32 teif5:1;
        lib::u32 gif6:1;
        lib::u32 tcif6:1;
        lib::u32 htif6:1;
        lib::u32 teif6:1;
        lib::u32 gif7:1;
        lib::u32 tcif7:1;
        lib::u32 htif7:1;
        lib::u32 teif7:1;
        lib::u32 _unused0:4;
    };

    struct dma_t {
        dma_interrupt_status_t interrupt_status;
        dma_interrupt_clear_t interrupt_clear;
    };

    struct dma_channel_config_t {
        lib::u32 en:1;
        lib::u32 tcie:1;
        lib::u32 htie:1;
        lib::u32 teie:1;
        lib::u32 dir:1;
        lib::u32 circ:1;
        lib::u32 pinc:1;
        lib::u32 minc:1;
        lib::u32 psize:2;
        lib::u32 msize:2;
        lib::u32 pl:2;
        lib::u32 mem2mem:1;
        lib::u32 _unused0:17;
    };

    struct dma_channel_number_of_data_t {
        lib::u16 ndt;
        lib::u16 _unused0;
    };

    struct dma_channel_t {
        dma_channel_config_t config;
        lib::u32 number_of_data;
        lib::u32 peripheral_address;
        lib::u32 memory_address;
    };
}

#include "hal/dma_d.hh"

#endif // DMA_HH
