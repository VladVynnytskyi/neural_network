#include "activations.h"
#include <cmath>
#include <algorithm>

double Activation::sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

double Activation::sigmoid_derivative(double x) {
    double s = sigmoid(x);
    return s * (1.0 - s);
}

double Activation::relu(double x) {
    return x > 0 ? x : 0;
}

double Activation::relu_derivative(double x) {
    return x > 0 ? 1 : 0;
}

double Activation::leaky_relu(double x) {
    return x > 0 ? x : 0.01 * x;
}

double Activation::leaky_relu_derivative(double x) {
    return x > 0 ? 1 : 0.01;
}

double Activation::tanh_(double x) {
    return std::tanh(x);
}

double Activation::tanh_derivative(double x) {
    double t = std::tanh(x);
    return 1.0 - t * t;
}

std::vector<double> Activation::softmax(const std::vector<double>& x) {
    std::vector<double> res(x.size());
    double max_val = *std::max_element(x.begin(), x.end());
    double sum = 0.0;
    
    for (size_t i = 0; i < x.size(); i++) {
        res[i] = std::exp(x[i] - max_val);
        sum += res[i];
    }
    
    for (size_t i = 0; i < x.size(); i++) {
        res[i] /= sum;
    }
    
    return res;
}