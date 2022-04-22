#ifndef ROOTTAKER_H
#define ROOTTAKER_H

#include <QtMath>

 enum class states {
  TWO_ROOTS,
  ONE_ROOT,
  NO_ROOTS,
  NOT_SQUARE
};


class RootTaker
{
private:
    double _a;
    double _b;
    double _c;
    double _d;
    states state;
    QPair<double, double> getRoot();
public:
    RootTaker(double a, double b, double c);
    QPair<states, QPair<double, double>> getResult();
};

#endif // ROOTTAKER_H
