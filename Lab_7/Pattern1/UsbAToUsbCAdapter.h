#ifndef USB_A_TO_USB_C_ADAPTER_H
#define USB_A_TO_USB_C_ADAPTER_H

#include "IUsbCPort.h"
#include "UsbACharger.h"
#include <iostream>

class UsbAToUsbCAdapter : public IUsbCPort {
private:
    UsbACharger* oldCharger;

public:
    UsbAToUsbCAdapter(UsbACharger* charger);
    ~UsbAToUsbCAdapter() override;
    void chargeWithUsbC() override;
};

#endif