#pragma once
#include <vector>

namespace Activation {
    double sigmoid(double x);
    double sigmoid_derivative(double x);
    
    double relu(double x);
    double relu_derivative(double x);
    
    double leaky_relu(double x);
    double leaky_relu_derivative(double x);
    
    double tanh_(double x);
    double tanh_derivative(double x);
    
    std::vector<double> softmax(const std::vector<double>& x);
}