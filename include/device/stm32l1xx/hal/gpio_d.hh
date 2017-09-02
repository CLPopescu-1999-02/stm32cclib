#ifndef GPIO_D_HH
#define GPIO_D_HH

namespace hal {
    using gpioa = gpio_d<0x40020000>;
    using gpiob = gpio_d<0x40020400>;
    using gpioc = gpio_d<0x40020800>;
}

#endif // GPIO_D_HH
