#ifndef USB_C_PHONE_H
#define USB_C_PHONE_H

#include "IUsbCPort.h"
#include <string>
#include <iostream>

using namespace std;

class UsbCPhone {
private:
    string model;

public:
    UsbCPhone(const string& modelName);
    ~UsbCPhone();
    void plugInCharger(IUsbCPort* charger);
};

#endif