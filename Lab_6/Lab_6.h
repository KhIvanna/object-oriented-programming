#ifndef LAB_6_H
#define LAB_6_H

class Dyhotomia_class {
private:
    double a;
    double b;
    double eps;
    int iterations;

public:
    Dyhotomia_class(double lowerBound, double upperBound, double tolerance);
    double solve();

    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double tolerance);

    double getA() const;
    double getB() const;
    double getEps() const;
    int getIterations() const;
    void setIterations(int val);
};

class Newton_class {
private:
    double tolerance;
    int maxIterations;
    int iterations;

public:
    Newton_class(double tol = 1e-7, int maxIter = 100);
    int getIterations() const;
    double solve(double initialGuess);
};

#endif
