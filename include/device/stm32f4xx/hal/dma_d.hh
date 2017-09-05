#ifndef DMA_D_HH
#define DMA_D_HH

namespace hal {
    using dma1 = dma_d<0x40026000>;

    using dma1_channel1 = dma_channel_d<0x40026000+ 0x10 + 0x18 * 0>;
    using dma1_channel2 = dma_channel_d<0x40026000+ 0x10 + 0x18 * 1>;
    using dma1_channel3 = dma_channel_d<0x40026000+ 0x10 + 0x18 * 2>;
    using dma1_channel4 = dma_channel_d<0x40026000+ 0x10 + 0x18 * 3>;
    using dma1_channel5 = dma_channel_d<0x40026000+ 0x10 + 0x18 * 4>;
    using dma1_channel6 = dma_channel_d<0x40026000+ 0x10 + 0x18 * 5>;
    using dma1_channel7 = dma_channel_d<0x40026000+ 0x10 + 0x18 * 6>;
    using dma1_channel8 = dma_channel_d<0x40026000+ 0x10 + 0x18 * 7>;

    using dma2 = dma_d<0x40026400>;

    using dma2_channel1 = dma_channel_d<0x40026400+ 0x10 + 0x18 * 0>;
    using dma2_channel2 = dma_channel_d<0x40026400+ 0x10 + 0x18 * 1>;
    using dma2_channel3 = dma_channel_d<0x40026400+ 0x10 + 0x18 * 2>;
    using dma2_channel4 = dma_channel_d<0x40026400+ 0x10 + 0x18 * 3>;
    using dma2_channel5 = dma_channel_d<0x40026400+ 0x10 + 0x18 * 4>;
    using dma2_channel6 = dma_channel_d<0x40026400+ 0x10 + 0x18 * 5>;
    using dma2_channel7 = dma_channel_d<0x40026400+ 0x10 + 0x18 * 6>;
    using dma2_channel8 = dma_channel_d<0x40026400+ 0x10 + 0x18 * 7>;
}

#endif // DMA_D_HH
