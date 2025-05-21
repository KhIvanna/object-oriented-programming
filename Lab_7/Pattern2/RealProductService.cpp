#include "RealProductService.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

vector<Product> RealProductService::getProducts() {
    cout << "Fetching products from REAL API (simulated delay)..." << endl;
    this_thread::sleep_for(chrono::seconds(2));

    vector<Product> products;
    products.emplace_back("ZenBook Laptop", 1200.00);
    products.emplace_back("Logitech Mouse", 25.00);
    products.emplace_back("HyperX Keyboard", 75.00);
    return products;
}