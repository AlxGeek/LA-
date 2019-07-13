#include "la.hpp"

bool la::LUDecomposition(const Mat &A, Mat &L, Mat &U)
{
    size_t n = A.getRows();
    U = Mat::getIdentity(n);
    L = Mat(n, n, 0.0);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j <= i; j++)
        {
            double sum = 0;
            for (size_t k = 0; k < j; k++)
            {
                sum += L[i][k] * U[k][j];
            }
            L[i][j] = A[i][j] - sum;
        }
        for (size_t j = i + 1; j < n; j++)
        {
            if (fabs(L[i][i]) < epsilon)
            {
                return false;
            }
            double sum = 0;
            for (size_t k = 0; k < i; k++)
            {
                sum += L[i][k] * U[k][j];
            }
            U[i][j] = (A[i][j] - sum) / L[i][i];
        }
    }
    return true;
}