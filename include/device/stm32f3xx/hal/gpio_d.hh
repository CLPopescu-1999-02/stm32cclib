#ifndef GPIO_D_HH
#define GPIO_D_HH

namespace hal {
    volatile gpio_t * const gpioa = reinterpret_cast<gpio_t *>(0x48000000);
    volatile gpio_t * const gpiob = reinterpret_cast<gpio_t *>(0x48000400);
    volatile gpio_t * const gpioc = reinterpret_cast<gpio_t *>(0x48000800);
    volatile gpio_t * const gpiod = reinterpret_cast<gpio_t *>(0x48000c00);
    volatile gpio_t * const gpioe = reinterpret_cast<gpio_t *>(0x48001000);
    volatile gpio_t * const gpiof = reinterpret_cast<gpio_t *>(0x48001400);
}

#endif // GPIO_D_HH
