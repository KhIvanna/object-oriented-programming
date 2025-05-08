#include "Dyhotomia_class.h"

Dyhotomia_class::Dyhotomia_class() : iterations(0), a(0.0), b(0.0), eps(0.0) {}

Dyhotomia_class::~Dyhotomia_class() {}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double tolerance) {
    eps = tolerance;
}

int Dyhotomia_class::getIterations() const {
    return iterations;
}

void Dyhotomia_class::setIterations(int val) {
    iterations = val;
}

double Dyhotomia_class::getA() const{
    return a;
}

double Dyhotomia_class::getB() const{
    return b;
}

double Dyhotomia_class::getEps() const{
    return eps;
}