#ifndef MAT_HPP
#define MAT_HPP

#include <ostream>
#include <cmath>

class Mat
{

private:
    double *data;
    size_t rows;
    size_t cols;

public:
    Mat();
    Mat(size_t n);
    Mat(size_t rows, size_t cols);
    Mat(size_t rows, size_t cols, double value);

    ~Mat();

    void print(std::ostream &os) const;

    size_t getRows() const;
    size_t getCols() const;

    void fillRandom(int maxValue = 10);
    void setDiagonal(double value);
    void setValue(double value);

    double &at(size_t i, size_t j);

    double *operator[](const size_t i) const;
    Mat operator*(const Mat &mat) const;

    static Mat getRandom(size_t rows, size_t cols, int maxValue = 10);
    static Mat getIdentity(size_t n);

    friend std::ostream &operator<<(std::ostream &os, const Mat &mat);
};

#endif //MAT_HPP