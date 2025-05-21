#include "ProductServiceProxy.h"
#include <iostream>

using namespace std;

ProductServiceProxy::ProductServiceProxy() : _realService(NULL) {}

ProductServiceProxy::~ProductServiceProxy() {
    delete _realService;
}

vector<Product> ProductServiceProxy::getProducts() {
    if (_cache.count("all_products") > 0) {
        cout << "Returning products from CACHE." << endl;
        return _cache["all_products"];
    } else {
        if (_realService == NULL) {
            _realService = new RealProductService();
        }
        vector<Product> products = _realService->getProducts();
        _cache["all_products"] = products;
        return products;
    }
}

void ProductServiceProxy::clearCache() {
    cout << "Manually clearing cache." << endl;
    if (_realService != NULL) {
        delete _realService;
        _realService = NULL;
    }
    _cache.clear();
}