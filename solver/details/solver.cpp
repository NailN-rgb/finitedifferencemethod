#include "../solver.h"

Solver::Solver(UniformMesh um, Equation eq, float tol)
{
    this->mesh = um;
    this->eq = eq;
    this->h = mesh.h;
    this->size = mesh.n - 2;
    this->tol = tol;

    this->a = new float[size];
    this->b = new float[size];
    this->c = new float[size];
    
    this->matrix = Matrix(size);
    this->right = new float[size];
    this->solution = new float[size];
}

void Solver::solve()
{
    switch (solve_type)
    {
    case 1: //Iteration solve method

        matrix_fill();
        right_hand_vector_fill();

        zeidel_method(solution, matrix.matrix, right, size, tol, 1000);
        break;
    
    case 2: //Tridiagonal matrix and sweep method

        tridigonal_vectors(a, b, c);
        right_hand_vector_fill();

        sweep_method(solution, a, b, c, right, size);
        break;

    default:
        std::cout << "Solve type Error" << std::endl;
        break;
    }
}

Matrix Solver::matrix_fill()
{
    for(size_t row = 0; row < size; row++)
    {
        if(row == 0)
        {
            
        }



        for(size_t col = 0; col < size; col++)
        {
            if(row == col)
            {
                auto value = 2 * (eq.p / pow(h, 2)) + (eq.phi / h) - eq.q;
                matrix.set_value(row, col, value);
            }
            else if(row == col + 1)
            {
                auto value = (eq.p / pow(h, 2)) + (eq.phi / h);
                matrix.set_value(row, col, value);
            }
            else if(row == col - 1)
            {
                auto value = eq.p / pow(h, 2);
                matrix.set_value(row, col, value);
            }
            else
            {
                matrix.set_value(row, col, 0);
            }
        }
    }
}

void Solver::tridigonal_vectors(float *a, float *b, float *c)
{
    for(size_t i = 0; i < size ; i++)
    {
        a[i] = 2 * (eq.p / pow(h, 2)) + (eq.phi / h) - eq.q;
        b[i] = (eq.p / pow(h, 2)) + (eq.phi / h);
        c[i] =  eq.p / pow(h, 2);
    }
}

void Solver::right_hand_vector_fill()
{
    for(size_t i = 0; i < size; i++)
    {
        right[i] = eq.f(mesh.mesh[i]);
    }
}

void Solver::display_results()
{
    for(int i = 0; i < size; i++)
    {
        std::cout << mesh.mesh[i] << ":\t" << solution[i] << std::endl;
    }
}