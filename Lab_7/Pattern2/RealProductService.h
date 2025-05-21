#ifndef REALPRODUCTSERVICE_H
#define REALPRODUCTSERVICE_H

#include "IProductService.h"
#include <vector>
#include <string>

using namespace std;

class RealProductService : public IProductService {
public:
    vector<Product> getProducts() override;
};

#endif