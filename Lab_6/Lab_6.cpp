#include "Lab_6.h"
#include <cmath>
#include <iostream>

using namespace std;

auto f_lambda = [](double x) {
    return exp(x) - exp(-x) - 2;
};

auto df_lambda = [](double x) {
    return exp(x) + exp(-x);
};

Dyhotomia_class::Dyhotomia_class(double lowerBound, double upperBound, double tolerance)
    : a(lowerBound), b(upperBound), eps(tolerance), iterations(0) {}

int Dyhotomia_class::getIterations() const {
    return iterations;
}

double Dyhotomia_class::solve() {
    double left = a;
    double right = b;
    double mid;
    iterations = 0;

    while (right - left > eps) {
        mid = (left + right) / 2.0;
        if (f_lambda(mid) * f_lambda(left) < 0) {
            right = mid;
        } else {
            left = mid;
        }
        iterations++;
    }
    return (left + right) / 2.0;
}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double tolerance) {
    eps = tolerance;
}

double Dyhotomia_class::getA() const {
    return a;
}

double Dyhotomia_class::getB() const {
    return b;
}

double Dyhotomia_class::getEps() const {
    return eps;
}

void Dyhotomia_class::setIterations(int val) {
    iterations = val;
}

Newton_class::Newton_class(double tol, int maxIter)
    : tolerance(tol), maxIterations(maxIter), iterations(0) {}

int Newton_class::getIterations() const {
    return iterations;
}

double Newton_class::solve(double initialGuess) {
    double x = initialGuess;
    iterations = 0;

    while (fabs(f_lambda(x)) > tolerance && iterations < maxIterations) {
        double f_prime = df_lambda(x);
        if (fabs(f_prime) < 1e-9) {
            cout << "Derivative is close to zero. Newton's method cannot continue." << endl;
            return x;
        }
        x = x - f_lambda(x) / f_prime;
        iterations++;
    }
    return x;
}
