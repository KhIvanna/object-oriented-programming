#include "Lab_2.h"
#include <cmath>

double distance(const Tochka& p1, const Tochka& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double heronArea(const Trukutnik& t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double vectordobutok(const Tochka& p1, const Tochka& p2, const Tochka& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool inside_tochka(const Trukutnik& t, const Tochka& p, double tolerance, bool useHeron) {

    if (useHeron) {
        double area_abc = heronArea(t);
        double area_pab = heronArea({p, t.A, t.B});
        double area_pbc = heronArea({p, t.B, t.C});
        double area_pca = heronArea({p, t.C, t.A});

        if (fabs(area_abc - (area_pab + area_pbc + area_pca)) < tolerance) {
            return true;
        }

        if (area_pab == 0 || area_pbc == 0 || area_pca == 0) {
            return true;
        }
    } else {
        double cp1 = vectordobutok(t.A, t.B, p);
        double cp2 = vectordobutok(t.B, t.C, p);
        double cp3 = vectordobutok(t.C, t.A, p);

        if (cp1 == 0 || cp2 == 0 || cp3 == 0) {
            return true;
        }

        if ((cp1 > 0 && cp2 > 0 && cp3 > 0) || (cp1 < 0 && cp2 < 0 && cp3 < 0)) {
            return true;
        }
    }

    return false;
}

bool Trukutniks_zero(const Trukutnik& t) {
    return heronArea(t) == 0;
}