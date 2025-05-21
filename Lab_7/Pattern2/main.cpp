#include <iostream>
#include <vector>
#include "IProductService.h"
#include "ProductServiceProxy.h"

using namespace std;

int main() {
    ProductServiceProxy* productServiceProxy = new ProductServiceProxy();
    IProductService* productService = productServiceProxy;

    cout << "--- First request ---" << endl;
    vector<Product> products1 = productService->getProducts();
    for (const auto& p : products1) {
        p.display();
    }
    cout << endl;

    cout << "--- Second request (should be from cache) ---" << endl;
    vector<Product> products2 = productService->getProducts();
    for (const auto& p : products2) {
        p.display();
    }
    cout << endl;

    cout << "--- Manually clearing cache ---" << endl;
    productServiceProxy->clearCache();
    cout << endl;

    cout << "--- Third request (should refetch after manual clear) ---" << endl;
    vector<Product> products3 = productService->getProducts();
    for (const auto& p : products3) {
        p.display();
    }
    cout << endl;

    delete productService;
    return 0;
}