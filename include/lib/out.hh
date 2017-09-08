#ifndef OUT_HH
#define OUT_HH

#include "lib/types.hh"

namespace lib {
    template <typename Outer, typename T = u32>
    class out {
    public:
        using outer = Outer;
        static constexpr auto t_bit_size = sizeof(T) * 8;

        enum struct base : u8 {
            bin = 2,
            oct = 8,
            dec = 10,
            hex = 16,
            alpha = 36
        };

        static void send(const s8 symbol) {
            outer::send_w(symbol);
        }

        static void send(const s8 *string) {
            while (*string != '\0') {
                outer::send_w(*string++);
            }
        }

        static void send(const s16 number) {
            send(static_cast<s32>(number));
        }

        static void send(const s32 number) {
            if (number < 0) {
                send('-');
                send(static_cast<u32>(number * -1));
            } else {
                send(static_cast<u32>(number));
            }
        }

        static void send(const u8 number) {
            send(static_cast<u32>(number));
        }

        static void send(const u16 number) {
            send(static_cast<u32>(number));
        }

        static void send(const u32 number) {
            s8 output_buff[t_bit_size + 1]; // number of bits + '\0'

            const s8 *pout =
                convert(output_buff + t_bit_size, number);

            send(pout);
        }

        template <typename Out, typename ...Outs>
        static void send(Out out, Outs ...outs) {
            send(out);
            send(outs...);
        }

    private:
        static const s8 * convert(s8 *output_buff, u32 number) {
            *output_buff-- = '\0';
            do {
                s8 dig = number % static_cast<u8>(out_base);
                if (dig > 9)
                    dig += 0x27; // change to alpha symbols
                *output_buff-- = dig + '0';
                number /=
                    static_cast<u8>(out_base);
            } while (number > 0);

            return output_buff + 1;
        }

        static base out_base;
    };

    template <typename Outer, typename T>
    typename out<Outer, T>::base out<Outer, T>::out_base = base::dec;
}

#endif // OUT_HH
