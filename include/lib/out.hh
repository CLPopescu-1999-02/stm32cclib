#ifndef OUT_HH
#define OUT_HH

#include "lib/types.hh"

namespace lib {
    template <typename Outer, typename Type = u32>
    class out {
    public:
        using outer = Outer;
        static constexpr auto t_bit_size = sizeof(Type) * 8;

        enum struct base : u8 {
            bin = 2,
            oct = 8,
            dec = 10,
            hex = 16,
            alpha = 36
        };

        template <typename T>
        struct to_base {
            const base bs;
            const T t;
        };

        template <typename T>
        static to_base<T> make_base(const base bs, const T t) {
            return to_base<T>{bs, t};
        }

        static void send(const s8 symbol) {
            outer::send_w(symbol);
        }

        static void send(const s8 *string) {
            while (*string != '\0') {
                outer::send_w(*string++);
            }
        }

        static void send(const s16 number,
            const base out_base = base::dec) {
            send(static_cast<s32>(number), out_base);
        }

        static void send(const s32 number,
            const base out_base = base::dec) {
            if (number < 0) {
                send('-');
                send(static_cast<u32>(number * -1), out_base);
            } else {
                send(static_cast<u32>(number), out_base);
            }
        }

        static void send(const u8 number,
            const base out_base = base::dec) {
            send(static_cast<u32>(number), out_base);
        }

        static void send(const u16 number,
            const base out_base = base::dec) {
            send(static_cast<u32>(number), out_base);
        }

        template <typename T>
        static void send(const to_base<T> t) {
            send(t.t, t.bs);
        }

        static void send(const u32 number,
            const base out_base = base::dec) {
            s8 output_buff[t_bit_size + 1]; // number of bits + '\0'

            const s8 *pout =
                convert(output_buff + t_bit_size, number, out_base);

            send(pout);
        }

        template <typename Out, typename ...Outs>
        static void send(Out out, Outs ...outs) {
            send(out);
            send(outs...);
        }
    private:
        static const s8 * convert(
            s8 *output_buff,
            u32 number,
            const base out_base) {
            *output_buff-- = '\0';
            do {
                s8 dig = number % static_cast<u8>(out_base);
                if (dig > 9)
                    dig += 0x27;
                *output_buff-- = dig + '0';
                number /=
                    static_cast<u8>(out_base);
            } while (number > 0);

            return output_buff + 1;
        }
    };
}

#endif // OUT_HH
