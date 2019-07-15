#ifndef MAT_HPP
#define MAT_HPP

#include <ostream>
#include <cmath>

class Mat
{

private:
    size_t rows;
    size_t cols;
    double *data;

    void init(size_t rows, size_t cols);
    void copyData(const Mat &mat);

public:
    Mat();
    Mat(size_t n);
    Mat(size_t rows, size_t cols);
    Mat(size_t rows, size_t cols, double value);
    Mat(const Mat &mat);

    ~Mat();

    std::ostream &print(std::ostream &os) const;

    size_t getRows() const;
    size_t getCols() const;
    double *getData();

    void fillRandom(int maxValue = 10);
    void setDiagonal(double value);
    void setValue(double value);

    Mat T() const;

    double &at(size_t i, size_t j);

    double *operator[](const size_t i) const;
    Mat operator*(const Mat &mat) const;

    Mat &operator=(const Mat &mat);
    static Mat getRandom(size_t rows, size_t cols, int maxValue = 10);
    static Mat getIdentity(size_t n);

    friend std::ostream &operator<<(std::ostream &os, const Mat &mat);
};

#endif //MAT_HPP