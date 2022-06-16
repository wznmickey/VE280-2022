#ifndef LAB5_STANDARDFORM_H
#define LAB5_STANDARDFORM_H

#include "rootType.h"

class QuadraticFunction {
    // OVERVIEW: the standard form of a quadratic function f(x) = ax^2 + bx + c
    float a;
    float b;
    float c;

public:
    QuadraticFunction(float a_in, float b_in, float c_in);
    // REQUIRES: a_in is not 0
    // EFFECTS: creates a quadratic function in standard form

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


#endif //LAB5_STANDARDFORM_H
