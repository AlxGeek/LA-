#include "Mat.hpp"

Mat::Mat(size_t n) : Mat(n, n)
{
}

Mat::Mat(size_t rows, size_t cols) : rows(rows), cols(cols)
{
    data = new double[rows * cols];
}

Mat::Mat(size_t rows, size_t cols, double value) : Mat(rows, cols)
{
    setValue(value);
}

Mat::~Mat()
{
    delete data;
}

void Mat::print(std::ostream &os) const
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            os << data[j + i * cols] << " ";
        }
        os << std::endl;
    }
}

size_t Mat::getRows() const
{
    return rows;
}

size_t Mat::getCols() const
{
    return cols;
}

void Mat::fillRandom(int maxValue)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            data[j + i * cols] = rand() % (maxValue + 1);
        }
    }
}

void Mat::setDiagonal(double value)
{
    for (size_t i = 0; i < rows; i++)
    {
        data[i * cols + i] = value;
    }
}

void Mat::setValue(double value)
{
    for (size_t i = 0; i < rows * cols; i++)
    {
        data[i] = value;
    }
}

double &Mat::at(size_t i, size_t j)
{
    if (i < 0 || i >= rows || j < 0 || j >= cols)
        throw std::out_of_range("Out of range");
    return data[j + i * cols];
}

double *Mat::operator[](const size_t i) const
{
    return &data[i * cols];
}

Mat Mat::operator*(const Mat &mat) const
{
    Mat res(rows, mat.cols);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t l = 0; l < mat.cols; l++)
        {
            double sum = 0;
            for (size_t j = 0; j < cols; j++)
            {
                sum += data[j + i * cols] * mat.data[j * mat.cols + l];
            }
            res.data[i * mat.cols + l] = sum;
        }
    }
    return res;
}


Mat Mat::getRandom(size_t rows, size_t cols, int maxValue){
    Mat mat(rows, cols);
    mat.fillRandom(maxValue);
    return mat;
}

Mat Mat::getIdentity(size_t n)
{
    Mat mat(n, n, 0);
    mat.setDiagonal(1);
    return mat;
}


std::ostream &operator<<(std::ostream &os, const Mat &mat)
{
    mat.print(os);
    return os;
}
