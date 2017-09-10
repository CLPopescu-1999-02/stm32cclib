#ifndef IN_HH
#define IN_HH

#include "lib/types.hh"

namespace lib {
    template <typename Inner, bool echo = true, typename Type = u32>
    class in {
    public:
        using inner = Inner;
        static constexpr auto t_bit_size = sizeof(Type) * 8;

        static void recv(s8 &symbol) {
            symbol = inner::recv_w();
            if (echo) {
                inner::send_w(symbol);
            }
        }

        template <Type N>
        static void recv(s8 (&string)[N]) {
            auto beg = string;
            const auto end = beg + N - 1;

            while (beg < end) {
                s8 ch = inner::recv_w();
                if (echo) {
                    inner::send_w(ch);
                }
                if (ch == '\n' || ch == '\r') {
                    break;
                }
                *beg++ = ch;
            }
            *beg = '\0';
        }

        template <typename T>
        static void recv(T &number) {
            number = 0;
            s8 buffer[t_bit_size + 1];

            auto beg = buffer;
            auto end = beg + t_bit_size;
            s8 ch;
            auto sig = false;

            while ((ch = inner::recv_w()) <= ' ');

            while (beg < end) {
                if (echo) {
                    inner::send_w(ch);
                }
                if (ch == '\n' || ch == '\r' || ch <= ' ') {
                    break;
                }
                *beg++ = ch;
                ch = inner::recv_w();
            }

            beg = buffer;
            if (*beg == '-') {
                sig = true;
                beg++;
            }

            convert(beg, end, number);

            if (sig)
                number = 0 - number;
        }

        template <typename In, typename ...Ins>
        static void recv(In &in, Ins &...ins) {
            recv(in);
            recv(ins...);
        }
    private:
        static bool default_checker (s8 ch) {
            return (ch == '\n' || ch == '\r') ?
                true : false;
        }

        template <typename T>
        static void convert(s8 *beg, s8 *end, T &number) {
            auto base = 10;

            if (*beg == '0') {
                beg++;
                if (*beg == 'a') {
                    base = 36;
                } else if (*beg == 'x') {
                    base = 16;
                } else if (*beg == 'b') {
                    base = 2;
                } else if (*beg <= ' ') {
                    return;
                } else {
                    base = 8;
                    beg--;
                }
                beg++;
            }

            while (beg < end) {
                s8 ch = *beg;
                if (ch <= ' ') {
                    break;
                }
                if (ch >= 'a')
                    ch -= 0x20;
                ch -= '0';
                if (ch >= 17) {
                    ch -= 7;

                    if (ch <= 9) {
                        return;
                    }
                }
                if (ch >= base) {
                    return;
                }

                number = number * base + ch;
                beg++;
            }
        }
    };
}

#endif // IN_HH
