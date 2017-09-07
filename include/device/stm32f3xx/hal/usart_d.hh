#ifndef USART_D_HH
#define USART_D_HH

namespace hal {
    using usart1 = usart_d<0x40013800>;

    using usart2 = usart_d<0x40004400>;
    using usart3 = usart_d<0x40004800>;

    using uart4 = usart_d<0x40004c00>;
    using uart5 = usart_d<0x40005000>;
}

#endif // USART_D_HH
