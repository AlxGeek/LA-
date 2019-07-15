#ifndef VEC_HPP
#define VEC_HPP

#include <cstddef>
#include <ostream>
#include <cmath>

class Vec
{
private:
    bool persistentMemory = false;
    size_t n;
    double *data;

    void init(size_t n);

public:
    Vec();
    Vec(size_t n);
    Vec(size_t n, double value);
    Vec(size_t n, double *value, bool copy = true);
    Vec(const Vec &vec);
    ~Vec();

    size_t getSize() const;
    double *getData();

    double getNorm();
    void normalize();

    void print(std::ostream &os) const;

    double &at(const size_t i);
    const double &at(const size_t i) const;

    double &operator[](const size_t i);
    const double &operator[](const size_t i) const;
    Vec operator+(const double &x) const;
    double operator*(const Vec &vec) const;

    Vec &operator=(const Vec &vec);

    friend std::ostream &operator<<(std::ostream &os, const Vec &vec);
};

#endif //VEC_HPP