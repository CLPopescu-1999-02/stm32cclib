#ifndef FSMC_D_HH
#define FSMC_D_HH

namespace hal {
    using fsmc_bank1 = fsmc_bank_d<0xa0000000, fsmc_bank1_t>;

    using fsmc_bank1e = fsmc_bank_d<0xa0000000 + 0x104, fsmc_bank1e_t>;
}

#endif // FSMC_D_HH
