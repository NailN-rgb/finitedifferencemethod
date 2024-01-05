


void sweep_method(float* solution, float* a, float* b, float* c, float* f, int size)
{
    float *B, *F = new float[size];
    
    // first values
    B[0] = b[0];
    F[0] = f[0];

    // прямой ход прогонки
    for(int i = 1; i < size; i++)
    {
        // прогоночные коэфициенты
        B[i] = b[i] - (a[i] * c[i-1]) / B[i-1];

        F[i] = f[i] - (a[i] * F[i-1]) / B[i-1];
    }


    // обратный ход прогонки
    solution[size - 1] = F[size - 1] / B[size - 1];

    for (int i = size - 2; i >= 0; i--)
    {
        solution[i] = (F[i] - c[i] * solution[i + 1]) / B[i];
    }

    delete[] B, F;  
}