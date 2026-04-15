#include "matrix.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data.assign(rows, std::vector<double>(cols, 0.0));
}
