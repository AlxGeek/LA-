#include <ostream>

class Mat
{

private:
    float *data;
    size_t rows;
    size_t cols;

public:
    Mat(size_t rows, size_t cols);
    Mat(size_t rows, size_t cols, float value);

    ~Mat();

    void print(std::ostream &os) const;

    size_t getRows();
    size_t getCols();

    void fillRandom(int maxValue = 10);

    float at(size_t i, size_t j);

    float *operator[](const size_t i) const;
    Mat operator*(const Mat &mat) const;

    friend std::ostream &operator<<(std::ostream &os, const Mat &mat);
};