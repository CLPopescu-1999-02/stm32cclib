#ifndef REGBIT_HH
#define REGBIT_HH

#include "lib/types.hh"

namespace lib {
    template <typename U, u8 bit_n, u8 bit_size>
    struct regbit {
        template <U value>
        struct val {
            template<typename T>
            constexpr static T mask() {
                return
                    (static_cast<T>(value) & (-1 >> (sizeof(T) - bit_size))) << (bit_n);
            }
        };
    };

    template <typename T, typename ...Bits>
    struct regbits;

    template <typename T>
    struct regbits<T> {
        static const T mask = 0;
    };

    template <typename T, typename Bit, typename ...Bits>
    struct regbits<T, Bit, Bits...> {
        static const T mask =
            Bit::template mask<T>() | regbits<T, Bits...>::mask;
    };
}

#endif // REGBIT_HH
