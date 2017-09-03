#ifndef REGBIT_HH
#define REGBIT_HH

#include "lib/types.hh"

namespace lib {
    template <u8 bit_n, typename U = bool, u8 bit_size = 1, U default_value = true>
    struct regbit {
        template <typename T>
        constexpr static T mask() {
                return
                    (
                        static_cast<T>(default_value) &
                            ((T)-1 >> (sizeof(T) * 8 - bit_size))
                    ) << (bit_n);
        }

        template <typename T>
        struct clean {
            static const T mask = ((T)-1 >> (sizeof(T) * 8 - bit_size)) << (bit_n);
        };

        template <typename T>
        static U get_val(const T reg) {
            return (reg & clean<T>::mask) >> (bit_n);
        }

        template <U value>
        struct val {
            template <typename T>
            constexpr static T mask() {
                return
                    (
                        static_cast<T>(value) &
                            ((T)-1 >> (sizeof(T) * 8 - bit_size))
                    ) << (bit_n);
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

    template <typename ...Bits>
    using regbits16 = regbits<u16, Bits...>;

    template <typename ...Bits>
    using regbits32 = regbits<u32, Bits...>;
}

#endif // REGBIT_HH
