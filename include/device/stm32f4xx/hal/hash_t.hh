#ifndef HASH_T_HH
#define HASH_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using hash_control_init = lib::regbit<2>;
    using hash_control_dmae = lib::regbit<3>;
    enum struct hash_control_datatype_t : lib::u8 {
        on32bit,
        on16bit,
        on8bit,
        bit
    };
    using hash_control_datatype =
        lib::regbit<4,
            hash_control_datatype_t,
            2,
            hash_control_datatype_t::on32bit>;
    using hash_control_mode = lib::regbit<6>;
    using hash_control_algo = lib::regbit<7>;
    using hash_control_nbw =
        lib::regbit8<8, 4>;
    using hash_control_dinne = lib::regbit<12>;
    using hash_control_lkey = lib::regbit<16>;

    using hash_start_nblw =
        lib::regbit8<0, 5>;
    using hash_start_dcal = lib::regbit<8>;

    using hash_interrupt_dinie = lib::regbit<0>;
    using hash_interrupt_dcie = lib::regbit<1>;

    using hash_status_dinis = lib::regbit<0>;
    using hash_status_dcis = lib::regbit<1>;
    using hash_status_dmas = lib::regbit<2>;
    using hash_status_busy = lib::regbit<3>;

    template <lib::u32 addr>
    struct hash_d {
        struct hash_t {
            lib::u32 control;
            lib::u32 data_in;
            lib::u32 start;
            lib::u32 hr0;
            lib::u32 hr1;
            lib::u32 hr2;
            lib::u32 hr3;
            lib::u32 hr4;
            lib::u32 interrupt;
            lib::u32 status;
            lib::u32 csr[50];
        };

        static constexpr volatile hash_t * const regs =
            reinterpret_cast<hash_t *>(addr);
    };
}

#endif // HASH_T_HH
