#ifndef PRODUCTSERVICEPROXY_H
#define PRODUCTSERVICEPROXY_H

#include "IProductService.h"
#include "RealProductService.h"
#include <vector>
#include <string>
#include <map>

using namespace std;

class ProductServiceProxy : public IProductService {
private:
    RealProductService* _realService;
    map<string, vector<Product>> _cache;

public:
    ProductServiceProxy();
    ~ProductServiceProxy() override;

    vector<Product> getProducts() override;

    void clearCache();
};

#endif