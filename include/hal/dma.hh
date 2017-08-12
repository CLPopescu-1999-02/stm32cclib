#ifndef DMA_HH
#define DMA_HH

#include <stdint.h>

namespace hal {
    struct dma_interrupt_status_t {
        uint32_t gif1:1;
        uint32_t tcif1:1;
        uint32_t htif1:1;
        uint32_t teif1:1;
        uint32_t gif2:1;
        uint32_t tcif2:1;
        uint32_t htif2:1;
        uint32_t teif2:1;
        uint32_t gif3:1;
        uint32_t tcif3:1;
        uint32_t htif3:1;
        uint32_t teif3:1;
        uint32_t gif4:1;
        uint32_t tcif4:1;
        uint32_t htif4:1;
        uint32_t teif4:1;
        uint32_t gif5:1;
        uint32_t tcif5:1;
        uint32_t htif5:1;
        uint32_t teif5:1;
        uint32_t gif6:1;
        uint32_t tcif6:1;
        uint32_t htif6:1;
        uint32_t teif6:1;
        uint32_t gif7:1;
        uint32_t tcif7:1;
        uint32_t htif7:1;
        uint32_t teif7:1;
        uint32_t _unused0:4;
    };

    struct dma_interrupt_clear_t {
        uint32_t gif1:1;
        uint32_t tcif1:1;
        uint32_t htif1:1;
        uint32_t teif1:1;
        uint32_t gif2:1;
        uint32_t tcif2:1;
        uint32_t htif2:1;
        uint32_t teif2:1;
        uint32_t gif3:1;
        uint32_t tcif3:1;
        uint32_t htif3:1;
        uint32_t teif3:1;
        uint32_t gif4:1;
        uint32_t tcif4:1;
        uint32_t htif4:1;
        uint32_t teif4:1;
        uint32_t gif5:1;
        uint32_t tcif5:1;
        uint32_t htif5:1;
        uint32_t teif5:1;
        uint32_t gif6:1;
        uint32_t tcif6:1;
        uint32_t htif6:1;
        uint32_t teif6:1;
        uint32_t gif7:1;
        uint32_t tcif7:1;
        uint32_t htif7:1;
        uint32_t teif7:1;
        uint32_t _unused0:4;
    };

    struct dma_t {
        dma_interrupt_status_t interrupt_status;
        dma_interrupt_clear_t interrupt_clear;
    };

    struct dma_channel_config_t {
        uint32_t en:1;
        uint32_t tcie:1;
        uint32_t htie:1;
        uint32_t teie:1;
        uint32_t dir:1;
        uint32_t circ:1;
        uint32_t pinc:1;
        uint32_t minc:1;
        uint32_t psize:2;
        uint32_t msize:2;
        uint32_t pl:2;
        uint32_t mem2mem:1;
        uint32_t _unused0:17;
    };

    struct dma_channel_number_of_data_t {
        uint16_t ndt;
        uint16_t _unused0;
    };

    struct dma_channel_t {
        dma_channel_config_t config;
        uint32_t number_of_data;
        uint32_t peripheral_address;
        uint32_t memory_address;
    };

    volatile dma_t * const dma1 = reinterpret_cast<dma_t *>(0x40026000);

    volatile dma_channel_t * const dma1_channel1 = reinterpret_cast<dma_channel_t *>(0x40026000 + 0x8 + 20 * 0);

    volatile dma_channel_t * const dma1_channel2 = reinterpret_cast<dma_channel_t *>(0x40026000 + 0x8 + 20 * 1);

    volatile dma_channel_t * const dma1_channel3 = reinterpret_cast<dma_channel_t *>(0x40026000 + 0x8 + 20 * 2);

    volatile dma_channel_t * const dma1_channel4 = reinterpret_cast<dma_channel_t *>(0x40026000 + 0x8 + 20 * 3);

    volatile dma_channel_t * const dma1_channel5 = reinterpret_cast<dma_channel_t *>(0x40026000 + 0x8 + 20 * 4);

    volatile dma_channel_t * const dma1_channel6 = reinterpret_cast<dma_channel_t *>(0x40026000 + 0x8 + 20 * 5);

    volatile dma_channel_t * const dma1_channel7 = reinterpret_cast<dma_channel_t *>(0x40026000 + 0x8 + 20 * 6);

    volatile dma_t * const dma2 = reinterpret_cast<dma_t *>(0x40026400);

    volatile dma_channel_t * const dma2_channel1 = reinterpret_cast<dma_channel_t *>(0x40026400 + 0x8 + 20 * 0);

    volatile dma_channel_t * const dma2_channel2 = reinterpret_cast<dma_channel_t *>(0x40026400 + 0x8 + 20 * 1);

    volatile dma_channel_t * const dma2_channel3 = reinterpret_cast<dma_channel_t *>(0x40026400 + 0x8 + 20 * 2);

    volatile dma_channel_t * const dma2_channel4 = reinterpret_cast<dma_channel_t *>(0x40026400 + 0x8 + 20 * 3);

    volatile dma_channel_t * const dma2_channel5 = reinterpret_cast<dma_channel_t *>(0x40026400 + 0x8 + 20 * 4);
}

#endif // DMA_HH
