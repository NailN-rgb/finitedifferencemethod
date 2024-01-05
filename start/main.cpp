#include <iostream>
#include "../algebra/UniformMesh.h"
#include "../solver/details/zeidel.cpp"

int main()
{
    std::cout << "Hello world!" << std::endl;

    int size = 2;

    float** matrix = new float*[size];

    for(size_t i = 0; i < size; i++)
    {
        matrix[i] = new float[size];
    }

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrix[i][j] = 0;
        }
    }

    matrix[0][0] = 5;
    matrix[1][0] = 3;
    matrix[0][1] = 2;
    matrix[1][1] = 10 ;
    
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << std::endl;
    }


    float * rhs = new float[size];
    rhs[0] = 1; 
    rhs[1] = 1;

    float *solution = new float[size];

    zeidel_method(solution, matrix, rhs, size, 0.1, 10000);

    for(int i = 0; i < size; i++)
    {
        std::cout << solution[i] << std::endl;
    }

    return 0;
}