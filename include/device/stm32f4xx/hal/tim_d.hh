#ifndef TIM_D_HH
#define TIM_D_HH

namespace hal {
    using tim2 = tim_d<0x40000000, tim32_t>;
    using tim3 = tim_d<0x40000400, tim_t>;
    using tim4 = tim_d<0x40000800, tim_t>;
    using tim5 = tim_d<0x40000c00, tim32_t>;

    using tim6 = tim_d<0x40001000, tim_t>;
    using tim7 = tim_d<0x40001400, tim_t>;

    using tim12 = tim_d<0x40001800, tim_t>;
    using tim13 = tim_d<0x40001c00, tim_t>;
    using tim14 = tim_d<0x40002000, tim_t>;

    using tim1 = tim_d<0x40012c00, tim_t>
    using tim8 = tim_d<0x40013400, tim_t>;

    using tim9 = tim_d<0x40014000, tim_t>;
    using tim10 = tim_d<0x40014400, tim_t>;
    using tim11 = tim_d<0x40014800, tim_t>;
}

#endif // TIM_D_HH
