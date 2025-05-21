#ifndef IPRODUCTSERVICE_H
#define IPRODUCTSERVICE_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string n, double p) : name(n), price(p) {}

    void display() const {
        cout << " - Product: " << name << ", Price: $" << price << endl;
    }
};

class IProductService {
public:
    virtual vector<Product> getProducts() = 0;
    virtual ~IProductService() = default;
};

#endif