#ifndef GPIO_D_HH
#define GPIO_D_HH

namespace hal {
    volatile gpio_t * const gpioa = reinterpret_cast<gpio_t *>(0x40020000);
    volatile gpio_t * const gpiob = reinterpret_cast<gpio_t *>(0x40020400);
    volatile gpio_t * const gpioc = reinterpret_cast<gpio_t *>(0x40020800);
}

#endif // GPIO_D_HH
