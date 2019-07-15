#include "Vec.hpp"

Vec::Vec() : n(0), data(nullptr)
{
}

Vec::Vec(size_t n)
{
    init(n);
}

Vec::Vec(size_t n, double value) : Vec(n)
{
    for (size_t i = 0; i < n; i++)
        data[i] = value;
}

Vec::Vec(size_t n, double *value, bool copy)
{
    if (copy)
    {
        init(n);
        for (size_t i = 0; i < n; i++)
        {
            data[i] = value[i];
        }
    }
    else
    {
        this->n = n;
        data = value;
        persistentMemory = true;
    }
}

Vec::Vec(const Vec &vec) : Vec(vec.getSize())
{
    for (size_t i = 0; i < n; i++)
        data[i] = vec[i];
}

Vec::~Vec()
{
    if (!persistentMemory)
        delete[] data;
}

void Vec::init(size_t n)
{
    this->n = n;
    data = new double[n];
}

size_t Vec::getSize() const
{
    return n;
}

double *Vec::getData()
{
    return data;
}

double Vec::getNorm()
{
    double norm = 0;
    for (size_t i = 0; i < n; i++)
    {
        norm += data[i] * data[i];
    }
    return sqrt(norm);
}

void Vec::normalize()
{
    double norm = getNorm();
    for (size_t i = 0; i < n; i++)
        data[i] /= norm;
}

void Vec::print(std::ostream &os) const
{
    for (size_t i = 0; i < n; i++)
    {
        os << data[i] << " ";
    }
    os << std::endl;
}

double &Vec::at(const size_t i)
{
    if (i < 0 || i >= n)
        throw std::out_of_range("Out of range");
    return data[i];
}

const double &Vec::at(const size_t i) const
{
    if (i < 0 || i >= n)
        throw std::out_of_range("Out of range");
    return data[i];
}

double &Vec::operator[](const size_t i)
{
    return data[i];
}

const double &Vec::operator[](const size_t i) const
{
    return data[i];
}

Vec Vec::operator+(const double &x) const
{
    Vec rest(*this);
    for (size_t i = 0; i < rest.n; i++)
    {
        rest.data[i] += x;
    }
    return rest;
}

double Vec::operator*(const Vec &vec) const
{
    double rest = 0;
    for (size_t i = 0; i < n; i++)
    {
        rest += data[i] * vec.data[i];
    }
    return rest;
}

Vec &Vec::operator=(const Vec &vec)
{
    if (this != &vec)
    {
        delete[] data;
        n = vec.getSize();
        data = new double[n];
        for (size_t i = 0; i < n; i++)
            data[i] = vec[i];
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Vec &vec)
{
    vec.print(os);
    return os;
}