#include <iostream>
#include <ctime>

#include "Mat.hpp"
#include "Vec.hpp"
#include "la.hpp"

int main()
{
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
    Mat L(3, 3, 0), U(3, 3, 0);
    std::cout << "LU decomposition: " << la::LUDecomposition(mat, L, U) << std::endl;
    std::cout << "Mat:\n"
              << mat;
    std::cout << "L:\n"
              << L;
    std::cout << "U:\n"
              << U;
    std::cout << "LU:\n"
              << L * U;

    return 0;
}