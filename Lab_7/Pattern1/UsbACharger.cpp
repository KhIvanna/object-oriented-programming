#include "UsbACharger.h"
#include <iostream>

using namespace std;

UsbACharger::UsbACharger() {
    cout << "USB-A Charger: Old charger created." << endl;
}

UsbACharger::~UsbACharger() {
    cout << "USB-A Charger: Charger destroyed." << endl;
}

void UsbACharger::givePowerViaUsbA() {
    cout << "USB-A Charger: Supplying power via USB-A port." << endl;
}