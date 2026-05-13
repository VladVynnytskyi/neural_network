#pragma once
#include <vector>

class Matrix {
public:
    int rows;
    int cols;
    std::vector<std::vector<double>> data;

    Matrix(int rows, int cols);

    void print() const;

    Matrix add(const Matrix& other) const;
    Matrix multiply(const Matrix& other) const;
    
    Matrix transpose() const;
    Matrix elementWiseMultiply(const Matrix& other) const;
    void randomize();
};