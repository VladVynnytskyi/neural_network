#include "matrix.h"
#include <iostream>

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data.assign(rows, std::vector<double>(cols, 0.0));
}

Matrix Matrix::add(const Matrix& other) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = data[i][j] + other.data[i][j];
    return result;
}

Matrix Matrix::multiply(const Matrix& other) const {
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < other.cols; j++)
            for (int k = 0; k < cols; k++)
                result.data[i][j] += data[i][k] * other.data[k][j];
    return result;
}

void Matrix::print() const {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << "\n";
    }
}
