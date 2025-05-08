#include <iostream>
#include <cmath>
#include <iomanip>
#include "Dyhotomia_class.h"

using namespace std;

double f(double x) {
    return (exp(x) - exp(-x) - 2);
}

double df_analytic(double x) {
    return (exp(x) + exp(-x));
}

double dichotomy(Dyhotomia_class& solver) {
    double left = solver.getA();
    double right = solver.getB();
    double mid;
    solver.setIterations(0);

    while (right - left > solver.getEps()) {
        mid = (left + right) / 2.0;
        if (f(mid) * f(left) < 0) {
            right = mid;
        } else {
            left = mid;
        }
        solver.setIterations(solver.getIterations() + 1);
    }
    return (left + right) / 2.0;
}

double newton(double initial_guess, double tolerance, int& iterations) {
    double x = initial_guess;
    iterations = 0;
    int max_iterations = 100;

    while (fabs(f(x)) > tolerance && iterations < max_iterations) {
        double f_prime = df_analytic(x);
        if (fabs(f_prime) < 1e-9) {
            cout << "Derivative close to zero. Newton's method cannot continue." << endl;
            return x;
        }
        x = x - f(x) / f_prime;
        iterations++;
    }
    return x;
}

int main() {
    Dyhotomia_class dyh_solver;
    dyh_solver.setVolumes(0.0, 1.5);
    dyh_solver.setTolerance(1e-7);
    double root_dichotomy = dichotomy(dyh_solver);

    cout << "Dichotomy Method:" << endl;
    cout << "Root: " << fixed << setprecision(8) << root_dichotomy << endl;
    cout << "Iterations: " << dyh_solver.getIterations() << endl;
    cout << endl;

    double initial_approximation_newton;
    cout << "Enter initial approximation for Newton's method: ";
    cin >> initial_approximation_newton;

    double tolerance = 1e-7;
    int iterations_newton;
    double root_newton = newton(initial_approximation_newton, tolerance, iterations_newton);

    cout << "Newton's Method:" << endl;
    cout << "Root: " << fixed << setprecision(8) << root_newton << endl;
    cout << "Iterations: " << iterations_newton << endl;

    return 0;
}