#ifndef Lab_2_h
#define Lab_2_h

using namespace std;

struct Tochka {
    double x;
    double y;
};

struct Trukutnik {
    Tochka A, B, C;
};

double distance(const Tochka& p1, const Tochka& p2);

double heronArea(const Trukutnik& t);

double vectordobutok(const Tochka& p1, const Tochka& p2, const Tochka& p3);

bool inside_tochka(const Trukutnik& t, const Tochka& p, double tolerance = 1e-4, bool useHeron = true);

bool Trukutniks_zero(const Trukutnik& t);

#endif