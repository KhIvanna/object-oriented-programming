#include "UsbCPhone.h"
#include <iostream>

using namespace std;

UsbCPhone::UsbCPhone(const string& modelName) : model(modelName) {
    cout << model << ": Waiting for USB-C charging." << endl;
}

UsbCPhone::~UsbCPhone() {
    cout << model << ": Phone turned off." << endl;
}

void UsbCPhone::plugInCharger(IUsbCPort* charger) {
    cout << model << ": Plugging in charger..." << endl;
    if (charger) {
        charger->chargeWithUsbC();
        cout << model << ": Charging started!" << endl;
    } else {
        cout << model << ": Could not plug in charger (null pointer)." << endl;
    }
}