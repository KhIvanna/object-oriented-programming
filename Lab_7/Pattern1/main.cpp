#include "UsbACharger.h"
#include "UsbAToUsbCAdapter.h"
#include "UsbCPhone.h"
#include <iostream> 

using namespace std;

int main() {
    UsbACharger* myOldCharger = new UsbACharger();
    UsbCPhone myNewPhone("Modern Smartphone");

    cout << "Compilation Error: Incompatible types. Phone requires an IUsbCPort*." << endl;

    cout << "\n--- Using Adapter to connect ---" << endl;
    IUsbCPort* adapter = new UsbAToUsbCAdapter(myOldCharger);
    myNewPhone.plugInCharger(adapter);

    cout << "\n--- Finishing up ---" << endl;

    delete adapter;
    delete myOldCharger;

    return 0;
}
