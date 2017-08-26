#ifndef GPIO_D_HH
#define GPIO_D_HH

namespace hal {
    volatile gpio_t * const gpioa = reinterpret_cast<gpio_t *>(0x40020000);
    volatile gpio_t * const gpiob = reinterpret_cast<gpio_t *>(0x40020400);
    volatile gpio_t * const gpioc = reinterpret_cast<gpio_t *>(0x40020800);
    volatile gpio_t * const gpiod = reinterpret_cast<gpio_t *>(0x40020c00);
    volatile gpio_t * const gpioe = reinterpret_cast<gpio_t *>(0x40021000);
    volatile gpio_t * const gpiof = reinterpret_cast<gpio_t *>(0x40021400);
    volatile gpio_t * const gpiog = reinterpret_cast<gpio_t *>(0x40021800);
    volatile gpio_t * const gpioh = reinterpret_cast<gpio_t *>(0x40021c00);
    volatile gpio_t * const gpioi = reinterpret_cast<gpio_t *>(0x40022000);
}

#endif // GPIO_D_HH
