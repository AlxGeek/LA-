#ifndef LA_HPP
#define LA_HPP

#include "Mat.hpp"
#include "Vec.hpp"

namespace la
{

const double epsilon = 1e-8;

bool solveDiagonal(const Mat &D, const Vec &b, Vec &x, bool init = true);

bool solveLowerTriangular(const Mat &L, const Vec &b, Vec &x, bool init = true);

bool solveUpperTriangular(const Mat &U, const Vec &b, Vec &x, bool init = true);

bool LUDecomposition(const Mat &A, Mat &L, Mat &U, bool init = true);

bool solveLU(const Mat &A, const Vec &b, Vec &x, bool init = true);

Mat inverse(const Mat &A);

} // namespace la

#endif //LA_HPP