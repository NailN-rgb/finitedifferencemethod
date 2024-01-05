#include "../algebra/UniformMesh.h"
#include "../equation/equation.h"
#include "../algebra/matrix.h"
#include "details/sweep_method.cpp"
#include "details/zeidel.cpp"

#include <cmath>

class Solver
{
public:
    UniformMesh mesh;
    Equation eq;
    float h;
    unsigned int size; //for first BC

    Matrix matrix;
    float *right;//rhs

    float *a, *b, *c;

    float *solution; // solution vector

    int solve_type; //1 - sweep_method, 2 - zeidel iterational method
    float tol;

public:
    Solver(UniformMesh um, Equation eq, float tol = 0.01);
    
public:
    void solve();

    void tridigonal_vectors(float *a, float *b, float *c);

    Matrix matrix_fill();

    void right_hand_vector_fill();

    void display_results();

};