#include <iostream>
#include <ctime>

#include "Mat.hpp"
#include "Vec.hpp"
#include "la.hpp"

int main()
{
    //Examples
    srand(time(NULL));
    std::cout << "VECTOR TEST" << std::endl;
    Vec vec(5, 1);
    Vec vec2 = vec + 2;
    std::cout << "Vec1: " << vec;
    std::cout << "Vec2: " << vec2;
    std::cout << "Access []: " << vec[2] << std::endl;
    vec[2] = 5;
    std::cout << "Access at: " << vec.at(2) << std::endl;
    std::cout << "dot product: " << vec * vec2 << std::endl;
    std::cout << "Vector plus constant: " << vec + 3;
    std::cout << "Norm: " << vec.getNorm() << std::endl;
    vec.normalize();
    std::cout << "Normalized: " << vec;
    std::cout << "Norm: " << vec.getNorm() << std::endl;

    std::cout << "MATRIX TEST" << std::endl;
    Mat mat = Mat::getRandom(3, 3, 5);
    Mat mat2 = Mat::getRandom(3, 4, 5);
    std::cout << "Mat 1: " << std::endl
              << mat;
    std::cout << "Access []: " << mat[0][1] << std::endl;
    std::cout << "Access at: " << mat.at(0, 1) << std::endl;
    mat.at(0, 1) = 5;
    std::cout << "Access at: " << mat.at(0, 1) << std::endl;
    std::cout << "Mat2: " << std::endl
              << mat2;
    std::cout << "Mat mult:" << std::endl
              << mat * mat2;

    std::cout << "Transpose:" << std::endl
              << mat.T();

    Mat L, U;
    std::cout << "LU decomposition: " << la::LUDecomposition(mat, L, U) << std::endl;
    std::cout << "Mat:\n"
              << mat;
    std::cout << "L:\n"
              << L;
    std::cout << "U:\n"
              << U;
    std::cout << "LU:\n"
              << L * U;

    Mat A(2, 2);
    Vec b(2);
    Vec x;
    A[0][0] = 1;
    A[0][1] = 4;
    A[1][0] = 3;
    A[1][1] = 2;
    b[0] = 3;
    b[1] = 2;
    std::cout << "LU solve: " << la::solveLU(A, b, x) << std::endl;
    std::cout << x;
    Mat inv = la::inverse(mat);
    std::cout << "Mat:" << std::endl
              << mat;
    std::cout << "Inverse:" << std::endl
              << inv;
    std::cout << "Identity:" << std::endl
              << mat * inv;

    return 0;
}