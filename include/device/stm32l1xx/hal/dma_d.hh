#ifndef DMA_D_HH
#define DMA_D_HH

namespace hal {
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

#endif // DMA_D_HH
