#include "../algebra/UniformMesh.h"
#include "../equation/equation.h"
#include "../algebra/matrix.h"

#include <cmath>

class Solver
{
public:
    UniformMesh mesh;
    Equation eq;
    float h;
    unsigned int size = mesh.n - 2; //for first BC

    float *right = new float(size); //rhs

    float *a, *b, *c;

    int solve_type; //1 - sweep_method, 2 - zeidel iterational method
    float tol;

public:
    Solver(UniformMesh um, Equation eq);
    
public:
    void solve();

    void tridigonal_vectors(float *a, float *b, float *c);

    Matrix matrix_fill();

    void right_hand_vector_fill();

    void display_results();

};