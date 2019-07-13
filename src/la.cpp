#include "la.hpp"

bool la::solveDiagonal(const Mat &D, const Vec &b, Vec &x)
{
    size_t n = b.getSize();
    x = Vec(n);
    for (int i = 0; i < n; i++)
    {
        if (fabs(D[i][i]) < epsilon)
        {
            return false;
        }
        x[i] = b[i] / D[i][i];
    }
    return true;
}

bool la::solveLowerTriangular(const Mat &L, const Vec &b, Vec &x)
{
    size_t n = b.getSize();
    x = Vec(n);
    for (size_t i = 0; i < n; i++)
    {
        if (fabs(L[i][i]) < epsilon)
        {
            return false;
        }
        double sum = 0;
        for (size_t j = 0; j < i; j++)
        {
            sum += L[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / L[i][i];
    }
    return true;
}

bool la::solveUpperTriangular(const Mat &U, const Vec &b, Vec &x)
{
    size_t n = b.getSize();
    x = Vec(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (fabs(U[i][i]) < epsilon)
        {
            return false;
        }
        double sum = 0;
        for (int j = i + 1; j < n; j++)
        {
            sum += U[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / U[i][i];
    }
    return true;
}

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

bool la::solveLU(const Mat &A, const Vec &b, Vec &x)
{
    Vec y;
    Mat L, U;
    if (!LUDecomposition(A, L, U))
    {
        return false;
    }
    if (!solveLowerTriangular(L, b, y))
    {
        return false;
    }
    if (!solveUpperTriangular(U, y, x))
    {
        return false;
    }
    return true;
}