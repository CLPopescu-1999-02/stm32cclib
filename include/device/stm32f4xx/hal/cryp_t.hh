#ifndef CRYP_T_HH
#define CRYP_T_HH

#include "lib/types.hh"
#include "lib/regbit.hh"

namespace hal {
    using cryp_control_agodir = lib::regbit<0>;
    enum struct cryp_control_algomode_t : lib::u8 {
        tdes_ecb = 0,
        tdes_cbc,
        des_ecb,
        des_cbc,
        aes_ebc,
        aes_cbc,
        aes_ctr,
        aes
    };
    using cryp_control_algomode =
        lib::regbit<2,
            cryp_control_algomode_t,
            3,
            cryp_control_algomode_t::tdes_ecb>;
    enum struct cryp_control_datatype_t : lib::u8 {
        on32bit = 0,
        on16bit,
        on8bit,
        bit
    };
    using cryp_control_datatype =
        lib::regbit<6,
            cryp_control_datatype_t,
            2,
            cryp_control_datatype_t::on32bit>;
    enum struct cryp_control_keysize_t : lib::u8 {
        on128bit = 0,
        on192bit,
        on256bit
    };
    using cryp_control_keysize =
        lib::regbit<6,
            cryp_control_keysize_t,
            2,
            cryp_control_keysize_t::on128bit>;
    using cryp_control_fflush = lib::regbit<14>;
    using cryp_control_crypen = lib::regbit<15>;

    using cryp_status_ifem = lib::regbit<0>;
    using cryp_status_ifnf = lib::regbit<1>;
    using cryp_status_ofne = lib::regbit<2>;
    using cryp_status_offu = lib::regbit<3>;
    using cryp_status_busy = lib::regbit<4>;

    using cryp_dma_control_dien = lib::regbit<0>;
    using cryp_dma_control_doen = lib::regbit<1>;

    using cryp_interrupt_mask_inim = lib::regbit<0>;
    using cryp_interrupt_mask_outim = lib::regbit<1>;

    using cryp_interrupt_status_inris = lib::regbit<0>;
    using cryp_interrupt_status_outris = lib::regbit<1>;

    using cryp_interrupt_mask_status_inmis = lib::regbit<0>;
    using cryp_interrupt_mask_status_outmis = lib::regbit<1>;

    template <lib::u32 addr>
    struct cryp_d {
        struct cryp_t {
            lib::u32 control;
            lib::u32 status;
            lib::u32 data_in;
            lib::u32 data_out;
            lib::u32 dma_control;
            lib::u32 interrupt_mask;
            lib::u32 interrupt_status;
            lib::u32 interrupt_mask_status;
            lib::u32 k0lr;
            lib::u32 k0rr;
            lib::u32 k1lr;
            lib::u32 k1rr;
            lib::u32 k2lr;
            lib::u32 k2rr;
            lib::u32 k3lr;
            lib::u32 k3rr;
            lib::u32 iv0lr;
            lib::u32 iv0rr;
            lib::u32 iv1lr;
            lib::u32 iv1rr;
        };

        static constexpr volatile cryp_t * const regs =
            reinterpret_cast<cryp_t *>(addr);
    };
}

#endif // CRYP_T_HH
