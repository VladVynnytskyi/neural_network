#include "activations.h"
#include <cmath>

double Activation::sigmoid(double x) {
    return 1.0 / (1.0 + std::exp(-x));
}

double Activation::relu(double x) {
    return x > 0 ? x : 0;
}

double Activation::tanh_(double x) {
    return std::tanh(x);
}
