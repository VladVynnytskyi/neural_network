#pragma once
#include <vector>

class Matrix {
public:
    int rows, cols;
    std::vector<std::vector<double>> data;

    Matrix(int rows, int cols);
};
