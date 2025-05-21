#ifndef I_USB_C_PORT_H
#define I_USB_C_PORT_H

class IUsbCPort {
public:
    virtual void chargeWithUsbC() = 0;
    virtual ~IUsbCPort() = default;
};

#endif