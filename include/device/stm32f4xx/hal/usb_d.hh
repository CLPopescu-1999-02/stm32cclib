#ifndef USB_D_HH
#define USB_D_HH

namespace hal {
    using otg_fs = usb_d<0x50000000>;

    using utg_hs = usb_d<0x40040000>;
}

#endif // USB_D_HH 
