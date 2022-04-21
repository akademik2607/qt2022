#include "roottaker.h"


RootTaker::RootTaker(double a, double b, double c)
    : _a{a}, _b{b}, _c{c} {}


QPair<double, double> RootTaker::getRoot() {
    if(_a == 0 ){
        state = states::NOT_SQUARE;
        return {((0 - _c) / _b), 0};
    }
    _d = qPow(_b, 2) - 4 * _a * _c;

    if(_d < 0) {
        state = states::NO_ROOTS;
        return {0, 0};
    } else {
        if(_d == 0) state = states::ONE_ROOT;
        else state = states::TWO_ROOTS;

        double result1;
        double result2;
        result1 = (-_b + qSqrt(_d)) / 2 * _a;
        result2 = (-_b - qSqrt(_d)) / 2 * _a;
        return {result1, result2};
    }

}

QPair<states, QPair<double, double>> RootTaker::getResult() {
    return {state, getRoot()};
}
