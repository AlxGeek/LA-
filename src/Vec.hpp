#include <cstddef>
#include <ostream>
#include <cmath>
#include <cassert>

class Vec
{
private:
    float *data;
    size_t n;

public:
    Vec(size_t n);
    Vec(size_t n, float value);
    Vec(size_t n, float *value);
    Vec(const Vec &vec);
    ~Vec();

    

    size_t getSize() const;
    float *getData() const;

    float getNorm();
    void normalize();

    void print(std::ostream &os) const;

    float at(const size_t i) const;

    float operator[](const size_t i) const;
    Vec operator+(const float &x) const;
    float operator*(const Vec &vec) const;

    friend std::ostream& operator<<(std::ostream& os, const Vec& vec);

};