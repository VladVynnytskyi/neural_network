#include "layer.h"
#include <algorithm>

Layer::Layer(int inputSize, int outputSize, ActivationType act)
    : weights(outputSize, inputSize), biases(outputSize, 1),
      activation(act), input_cache(1, 1), z_cache(1, 1) {
    weights.randomize();
    biases.randomize();
}

double Layer::applyActivation(double x) const {
    switch (activation) {
        case ActivationType::SIGMOID:    return Activation::sigmoid(x);
        case ActivationType::RELU:       return Activation::relu(x);
        case ActivationType::LEAKY_RELU: return Activation::leaky_relu(x);
        case ActivationType::TANH:       return Activation::tanh_(x);
        default:                         return x;
    }
}

double Layer::applyActivationDerivative(double x) const {
    switch (activation) {
        case ActivationType::SIGMOID:    return Activation::sigmoid_derivative(x);
        case ActivationType::RELU:       return Activation::relu_derivative(x);
        case ActivationType::LEAKY_RELU: return Activation::leaky_relu_derivative(x);
        case ActivationType::TANH:       return Activation::tanh_derivative(x);
        default:                         return 1.0;
    }
}

Matrix Layer::forward(const Matrix& input) {
    input_cache = input;
    z_cache = weights.multiply(input).add(biases);

    Matrix activated(z_cache.rows, z_cache.cols);
    for (int i = 0; i < z_cache.rows; i++)
        for (int j = 0; j < z_cache.cols; j++)
            activated.data[i][j] = applyActivation(z_cache.data[i][j]);

    return activated;
}

Matrix Layer::backward(const Matrix& grad_output, double lr) {
    double clip = 5.0;

    Matrix delta(grad_output.rows, grad_output.cols);
    for (int i = 0; i < grad_output.rows; i++)
        for (int j = 0; j < grad_output.cols; j++) {
            double d = grad_output.data[i][j] * applyActivationDerivative(z_cache.data[i][j]);
            delta.data[i][j] = std::max(-clip, std::min(clip, d));
        }

    Matrix grad_weights = delta.multiply(input_cache.transpose());
    Matrix grad_input = weights.transpose().multiply(delta);

    for (int i = 0; i < weights.rows; i++)
        for (int j = 0; j < weights.cols; j++)
            weights.data[i][j] -= lr * grad_weights.data[i][j];

    for (int i = 0; i < biases.rows; i++)
        biases.data[i][0] -= lr * delta.data[i][0];

    return grad_input;
}
