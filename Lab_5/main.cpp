#include "Lab_5.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    FruitTree appleTree("Apple Tree", "Green", 5.0, false, "Apples");
    //appleTree.displayInfo();
    cout << endl;

    HybridFruitTree hybridTree("Hybrid Tree", "Purple", 7.0, true);
    //hybridTree.displayInfo();
    cout << endl;

    return 0;
}
