#include "layer.h"

Layer::Layer(int inputSize, int outputSize) 
    : weights(outputSize, inputSize), biases(outputSize, 1) {
    weights.randomize();
    biases.randomize();
}

Matrix Layer::forward(const Matrix& input) const {
    Matrix result = weights.multiply(input);
    return result.add(biases);
}