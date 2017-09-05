#ifndef DMA_D_HH
#define DMA_D_HH

namespace hal {
    using dma1 = dma_d<0x40020000>;

    using dma1_channel1 = dma_channel_d<0x40020000 + 0x8 + 20 * 0>;
    using dma1_channel2 = dma_channel_d<0x40020000 + 0x8 + 20 * 1>;
    using dma1_channel3 = dma_channel_d<0x40020000 + 0x8 + 20 * 2>;
    using dma1_channel4 = dma_channel_d<0x40020000 + 0x8 + 20 * 3>;
    using dma1_channel5 = dma_channel_d<0x40020000 + 0x8 + 20 * 4>;
    using dma1_channel6 = dma_channel_d<0x40020000 + 0x8 + 20 * 5>;
    using dma1_channel7 = dma_channel_d<0x40020000 + 0x8 + 20 * 6>;

    using dma2 = dma_d<0x40020400>;

    using dma2_channel1 = dma_channel_d<0x40020400 + 0x8 + 20 * 0>;
    using dma2_channel2 = dma_channel_d<0x40020400 + 0x8 + 20 * 1>;
    using dma2_channel3 = dma_channel_d<0x40020400 + 0x8 + 20 * 2>;
    using dma2_channel4 = dma_channel_d<0x40020400 + 0x8 + 20 * 3>;
    using dma2_channel5 = dma_channel_d<0x40020400 + 0x8 + 20 * 4>;
}

#endif // DMA_D_HH
