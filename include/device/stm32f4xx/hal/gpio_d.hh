#ifndef GPIO_D_HH
#define GPIO_D_HH

namespace hal {
    using gpioa = gpio_d<0x40020000>;
    using gpiob = gpio_d<0x40020400>;
    using gpioc = gpio_d<0x40020800>;
    using gpiod = gpio_d<0x40020c00>;
    using gpioe = gpio_d<0x40021000>;
    using gpiof = gpio_d<0x40021400>;
    using gpiog = gpio_d<0x40021800>;
    using gpioh = gpio_d<0x40021c00>;
    using gpioi = gpio_d<0x40022000>;
}

#endif // GPIO_D_HH
