#ifndef TIM_D_HH
#define TIM_D_HH

namespace hal {
    using tim2 = tim_d<0x40000000, tim_t>;
    using tim3 = tim_d<0x40000400, tim_t>;
    using tim4 = tim_d<0x40000800, tim_t>;
    using tim5 = tim_d<0x40000c00, tim32_t>;

    using tim6 = tim_d<0x40001000, tim_t>;
    using tim7 = tim_d<0x40001400, tim_t>;

    using tim9 = tim_d<0x40010800, tim_t>;
    using tim10 = tim_d<0x40010c00, tim_t>;
    using tim11 = tim_d<0x40011000, tim_t>;
}

#endif // TIM_D_HH
