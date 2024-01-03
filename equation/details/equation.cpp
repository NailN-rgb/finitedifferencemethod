#include <iostream>

#include "../equation.h"


Equation::Equation()
{
    this->p = 0;
    this->r = 0;
    this->s = 0;
    this->q = 0;

    this->phi = 0;
}

Equation::Equation(float p, float r, float s, float q)
{
    this->p = p;
    this->r = r;
    this->s = s;
    this->q = q;

    this->phi = r + s;
}

float Equation::f(float x)
{
    return 0;
}