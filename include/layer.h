#pragma once
#include "matrix.h"
#include "activations.h"

enum class ActivationType { LINEAR, SIGMOID, RELU, LEAKY_RELU, TANH };

class Layer {
public:
    Matrix weights;
    Matrix biases;
    ActivationType activation;

    Layer(int inputSize, int outputSize, ActivationType act = ActivationType::LINEAR);

    Matrix forward(const Matrix& input);
    Matrix backward(const Matrix& grad_output, double lr);

private:
    Matrix input_cache;
    Matrix z_cache;

    double applyActivation(double x) const;
    double applyActivationDerivative(double x) const;
};
