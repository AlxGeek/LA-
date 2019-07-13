#ifndef LA_HPP
#define LA_HPP

#include "Mat.hpp"

namespace la{

    const double epsilon = 1e-8;

    bool LUDecomposition(const Mat &A, Mat &L, Mat &U);

}

#endif //LA_HPP