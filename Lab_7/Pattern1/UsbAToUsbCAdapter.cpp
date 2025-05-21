#include "UsbAToUsbCAdapter.h"
#include <iostream>

using namespace std;

UsbAToUsbCAdapter::UsbAToUsbCAdapter(UsbACharger* charger) : oldCharger(charger) {
    cout << "Adapter: USB-A to USB-C adapter created." << endl;
}

UsbAToUsbCAdapter::~UsbAToUsbCAdapter() {
    cout << "Adapter: USB-A to USB-C adapter destroyed." << endl;
}

void UsbAToUsbCAdapter::chargeWithUsbC() {
    cout << "Adapter: Converting power from USB-A for USB-C delivery..." << endl;
    if (oldCharger) {
        oldCharger->givePowerViaUsbA();
    } else {
        cout << "Error: No USB-A charger connected for adaptation." << endl;
    }
    cout << "Adapter: Power successfully delivered to USB-C." << endl;
}