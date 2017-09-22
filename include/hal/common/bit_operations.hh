#ifndef BIT_OPERATIONS_HH
#define BIT_OPERATIONS_HH

namespace hal {
    template <typename ...Pins>
    using bits32val = lib::bits32<lib::u32, 1, 0, Pins...>;
}

#endif // BIT_OPERATIONS_HH
