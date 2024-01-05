#include <iostream>

class Equation
{
    //we look for equation:
    //(pu' + ru)' + su' + qu = f
    //realization for const coeficients, first BC
public:
    float p, r, s, q;
    float phi; //additional param for const coefs

    float ua, ub; //boundary values
public:
    Equation();
    Equation(float p, float r, float s, float q, float ua, float ub);

public:

    float f(float x);
    void equation_view();

};