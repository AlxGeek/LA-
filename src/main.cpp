#include <iostream>
#include "Vec.hpp"
#include "Mat.hpp"

#include <ctime>


int main()
{
    srand(time(NULL));

    Vec vec(5, 1);
    Vec vec2 = vec + 2;
    std::cout << "Vec1: " << vec;
    std::cout << "Vec2: " << vec2;
    std::cout << "Access []: " << vec[2] << std::endl;
    std::cout << "Access at: " << vec.at(2) << std::endl;
    std::cout << "dot product: " << vec * vec2 << std::endl;
    std::cout << "Vector plus constant: " << vec + 3;
    std::cout << "Norm: " << vec.getNorm() << std::endl;
    vec.normalize();
    std::cout << "Normalized: " << vec;
    std::cout << "Norm: " << vec.getNorm() << std::endl;

    Mat mat(2, 3);
    Mat mat2(3, 4);
    mat.fillRandom(4);
    mat2.fillRandom(4);
    std::cout << "Mat 1: " << std::endl << mat;
    std::cout << "Access []: " << mat[0][1] << std::endl;
    std::cout << "Access at: " << mat.at(0, 1) << std::endl;
    std::cout << "Mat2: " << std::endl << mat2;
    std::cout << "Mat mult:" << std::endl << mat * mat2;


    return 0;
}