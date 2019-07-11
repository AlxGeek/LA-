#include "Vec.hpp"

Vec::Vec(size_t n) : n(n)
{
    data = new float[n];
}

Vec::Vec(size_t n, float value) : Vec(n)
{
    for (size_t i = 0; i < n; i++)
        data[i] = value;
}

Vec::Vec(size_t n, float *value) : Vec(n)
{
    for (size_t i = 0; i < n; i++)
        data[i] = value[i];
}

Vec::Vec(const Vec &vec) : Vec(vec.getSize(), vec.getData())
{
}

Vec::~Vec()
{
    delete data;
}

size_t Vec::getSize() const
{
    return n;
}

float *Vec::getData() const
{
    return data;
}

float Vec::getNorm()
{
    float norm = 0;
    for (size_t i = 0; i < n; i++)
    {
        norm += data[i] * data[i];
    }
    return sqrt(norm);
}

void Vec::normalize()
{
    float norm = getNorm();
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

float Vec::at(const size_t i) const{
    if(i < 0 || i >= n)
        throw std::out_of_range("Out of range");
    return data[i];
}


float Vec::operator[](const size_t i) const
{
    return data[i];
}


Vec Vec::operator+(const float &x) const
{
    Vec rest(*this);
    for (size_t i = 0; i < rest.n; i++)
    {
        rest.data[i] += x;
    }
    return rest;
}

float Vec::operator*(const Vec &vec) const
{
    float rest = 0;
    for (size_t i = 0; i < n; i++)
    {
        rest += data[i] * vec.data[i];
    }
    return rest;
}

std::ostream &operator<<(std::ostream &os, const Vec &vec)
{
    vec.print(os);
    return os;
}