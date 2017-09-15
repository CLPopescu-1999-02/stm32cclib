#ifndef RNG_T_HH
#define RNG_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using rng_control_rngen = lib::regbit<2>;
    using rng_control_ie = lib::regbit<2>;

    using rng_status_drdy = lib::regbit<0>;
    using rng_status_cecs = lib::regbit<1>;
    using rng_status_secs = lib::regbit<2>;
    using rng_status_ceis = lib::regbit<5>;
    using rng_status_seis = lib::regbit<6>;

    template <lib::u32 addr>
    struct rng_d {
        struct rng_t {
            lib::u32 control;
            lib::u32 status;
            lib::u32 rndata;
        };

        static constexpr volatile rng_t * const regs =
            reinterpret_cast<rng_t *>(addr);
    };
}

#endif // RNG_T_HH
