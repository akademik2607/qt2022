#include "trianlesquare.h"

TrianleSquare::TrianleSquare(double a, double b, double angle, bool isRad=false)
    : _a{a}, _b{b}
{
    if(isRad) {
        _angle = angle;
    } else {
        _angle = gradToRad(angle);
    }

}

double TrianleSquare::gradToRad(double grad){
    return M_PI / 180 * grad;
}

double TrianleSquare::getSquare() {
   return qSqrt(qPow(_a, 2) + qPow(_b, 2) - 2 * _a * _b * qCos(_angle));
}
