#include <iostream>
#include <iomanip>
#include "Lab_6.h"

using namespace std;

int main() {
    Dyhotomia_class d(0.0, 1.5, 1e-7);
    double dichotomy_root = d.solve();

    cout << "Dichotomy method:" << endl;
    cout << "Root: " << fixed << setprecision(8) << dichotomy_root << endl;
    cout << "Iterations: " << d.getIterations() << endl << endl;

    Newton_class n;
    double guess;
    cout << "Enter initial guess for Newton's method: ";
    cin >> guess;

    double newton_root = n.solve(guess);

    cout << "Newton's method:" << endl;
    cout << "Root: " << fixed << setprecision(8) << newton_root << endl;
    cout << "Iterations: " << n.getIterations() << endl;

    return 0;
}
