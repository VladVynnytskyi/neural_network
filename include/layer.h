#pragma once
#include "matrix.h"

class Layer {
public:
    Matrix weights;
    Matrix biases;

    Layer(int inputSize, int outputSize);

    Matrix forward(const Matrix& input) const;
};