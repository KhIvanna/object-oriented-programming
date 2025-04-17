#include <iostream>
#include <vector>
#include <cmath>
#include "Lab_2.h"

using namespace std;

int main() {
    Trukutnik t;

    cout << "Trukutnik vertices coordinates:" << endl;
    cout << "A(x y): ";
    cin >> t.A.x >> t.A.y;
    cout << "B(x y): ";
    cin >> t.B.x >> t.B.y;
    cout << "C(x y): ";
    cin >> t.C.x >> t.C.y;

    if (Trukutniks_zero(t)) {
        cout << "Trukutnik is degenerate (area is zero)!" << endl;
    }

    int n;
    cout << "Number of tochku to check: ";
    cin >> n;

    vector<Tochka> Tochku(n);
    cout << "Tochku coordinates: " << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Tochka №" << i + 1 << " (x y): ";
        cin >> Tochku[i].x >> Tochku[i].y;
    }

    char method;
    cout << "Use Heron formula or Vector dobutok? ";
    cin >> method;

    bool useHeron = (method == 'H');

    for (int i = 0; i < n; ++i) {
        if (useHeron) {
            if (Trukutniks_zero(t)) {
                if (fabs(Tochku[i].x - t.A.x) < 1e-4 && fabs(Tochku[i].y - t.A.y) < 1e-4 ||
                fabs(Tochku[i].x - t.B.x) < 1e-4 && fabs(Tochku[i].y - t.B.y) < 1e-4 ||
                fabs(Tochku[i].x - t.C.x) < 1e-4 && fabs(Tochku[i].y - t.C.y) < 1e-4  || Tochku[i].x == t.A.x) {
                    cout << "Tochka №" << i + 1 << " is on the boundary of the triangle." << endl;
                } else {
                    cout << "Tochka №" << i + 1 << " is outside the triangle." << endl;
                }
            } else {
                if (inside_tochka(t, Tochku[i], 1e-4, true)) {
                    Trukutnik pab = {t.A, t.B, Tochku[i]};
                    Trukutnik pbc = {t.B, t.C, Tochku[i]};
                    Trukutnik pca = {t.C, t.A, Tochku[i]};
                    if (fabs(heronArea(pab)) < 1e-4 || fabs(heronArea(pbc)) < 1e-4 || fabs(heronArea(pca)) < 1e-4) {
                        cout << "Tochka №" << i + 1 << " is on the boundary of the triangle." << endl;
                    } else {
                        cout << "Tochka №" << i + 1 << " is inside the triangle." << endl;
                    }
                } else {
                    cout << "Tochka №" << i + 1 << " is outside the triangle." << endl;
                }
            }
        }

        if (!useHeron) {
            if (inside_tochka(t, Tochku[i], 1e-4, false)) {
                double cp1 = vectordobutok(t.A, t.B, Tochku[i]);
                double cp2 = vectordobutok(t.B, t.C, Tochku[i]);
                double cp3 = vectordobutok(t.C, t.A, Tochku[i]);
                if (cp1 == 0 || cp2 == 0 || cp3 == 0) {
                    cout << "Tochka №" << i + 1 << " is on the boundary of the triangle." << endl;
                } else {
                    cout << "Tochka №" << i + 1 << " is inside the triangle." << endl;
                }
            } else {
                cout << "Tochka №" << i + 1 << " is outside the triangle." << endl;
            }
        }
    }
    return 0;
}