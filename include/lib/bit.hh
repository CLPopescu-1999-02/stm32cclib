#ifndef BIT_HH
#define BIT_HH

#include "lib/types.hh"

namespace lib {

    template <u8 bit_n>
    struct bit {
        template<typename T, typename U, u8 step>
        constexpr static T mask(const U value) {
            return static_cast<T>(value) << (bit_n << step);
        }
    };

    template<typename T, typename U, U val, u8 step, typename ...Bits>
    struct bits;

    template <typename T, typename U, U val, u8 step>
    struct bits<T, U, val, step> {
        static const T mask = 0;
    };

    template <typename T, typename U, U val, u8 step, typename Bit, typename ...Bits>
    struct bits<T, U, val, step, Bit, Bits...> {
        static const T mask =
            Bit::template mask<T, U, step>(val) |
            bits<T, U, val, step, Bits...>::mask;
    };

    template <typename U, U val, u8 step, typename ...Bits>
    using bits32 = bits<u32, U, val, step, Bits...>;
}

#endif // BIT_HH
