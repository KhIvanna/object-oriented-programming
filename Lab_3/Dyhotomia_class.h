#ifndef DY
#define DY

class Dyhotomia_class {
private:
    double a;
    double b;
    double eps;
    int iterations;

public:
    Dyhotomia_class();
    ~Dyhotomia_class();

    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double tolerance);

    double getA() const;
    double getB() const;
    double getEps() const;
    int getIterations() const;
    void setIterations(int val);
};

#endif 