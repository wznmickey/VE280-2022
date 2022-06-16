#ifndef LAB5_FACTOREDFORM_H
#define LAB5_FACTOREDFORM_H

#include "rootType.h"
#include <cmath>
class QuadraticFunction {
    // OVERVIEW: the factored form of a quadratic function f(x) = ax^2 + bx + c
    float a;
    complexNum r1;
    complexNum r2;

public:
    QuadraticFunction(float a_in, float b_in, float c_in);
    // REQUIRES: a_in is not 0
    // EFFECTS: creates a quadratic function in factored form

    float getA()const;
    // EFFECTS: returns the value of a

    float getB()const;
    // EFFECTS: returns the value of b

    float getC()const;
    // EFFECTS: returns the value of c

    float evaluate(float x);
    // EFFECTS: returns the value of f(x)

    Root getRoot();
    // EFFECTS: returns the roots of the quadratic function

    bool intersect(QuadraticFunction q);
    // EFFECTS: returns whether q and this intersect
};


#endif //LAB5_FACTOREDFORM_H
