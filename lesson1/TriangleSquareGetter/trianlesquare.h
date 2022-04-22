#ifndef TRIANLESQUARE_H
#define TRIANLESQUARE_H
#include <QtMath>

class TrianleSquare
{
private:
    double _a;
    double _b;
    double _angle;
public:
    TrianleSquare(double a, double b, double angle, bool isRad);
    static double gradToRad(double grad);
    double getSquare();
};

#endif // TRIANLESQUARE_H
