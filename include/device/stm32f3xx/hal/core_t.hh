namespace hal {
    struct nvic_t {
        uint32_t iser[8];
        uint32_t __reserved0[24];
        uint32_t icer[8];
        uint32_t __reserved1[24];
        uint32_t ispr[8];
        uint32_t __reserved2[24];
        uint32_t icpr[8];
        uint32_t __reserved3[24];
        uint32_t iabr[8];
        uint32_t __reserved4[56];
        uint32_t ip[240];
        uint32_t __reserved5[644];
        uint32_t stir;

        template <typename Irq_t>
        void enable_irq(Irq_t irq_n) volatile {
            iser[(uint32_t)((int32_t)irq_n) >> 5] =
                (uint32_t)(1 << ((uint32_t)((int32_t)irq_n) & (uint32_t)0x1f));
        }
    };

    namespace sys_tick_int {
        const uint32_t load_reload_msk = 0xffffff;
    }

    struct sys_tick_control_t {
        uint32_t enable:1;
        uint32_t tickint:1;
        uint32_t clksource:1;
        uint32_t _unused0:13;
        uint32_t countf:1;
        uint32_t _unused1:15;
    };

    struct sys_tick_t {
        sys_tick_control_t control;
        uint32_t load;
        uint32_t value;
        uint32_t calib;

        bool config(uint32_t ticks) volatile {
            if (ticks > sys_tick_int::load_reload_msk)
                return false;

            load = (ticks & sys_tick_int::load_reload_msk) - 1;

            value = 0;

            control.clksource = 1;
            control.tickint = 1;
            control.enable = 1;

            return true;
        }
    };
} // namespace Hal 
