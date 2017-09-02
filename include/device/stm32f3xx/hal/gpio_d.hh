#ifndef GPIO_D_HH
#define GPIO_D_HH

namespace hal {
    using gpioa = gpio_d<0x48000000>;
    using gpiob = gpio_d<0x48000400>;
    using gpioc = gpio_d<0x48000800>;
    using gpiod = gpio_d<0x48000c00>;
    using gpioe = gpio_d<0x48001000>;
    using gpiof = gpio_d<0x48001400>;
}

#endif // GPIO_D_HH
