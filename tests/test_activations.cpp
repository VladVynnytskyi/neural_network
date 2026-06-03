#include "activations.h"
#include "tests.h"

int main() {
    check(approx(Activation::sigmoid(0.0), 0.5), "sigmoid(0) = 0.5");
    check(Activation::sigmoid(100.0) > 0.999, "sigmoid(large) ≈ 1");
    check(approx(Activation::sigmoid_derivative(0.0), 0.25), "sigmoid_derivative(0) = 0.25");

    check(Activation::relu(-5.0) == 0.0, "relu(-5) = 0");
    check(Activation::relu(3.0) == 3.0, "relu(3) = 3");
    check(Activation::relu_derivative(1.0) == 1.0, "relu_derivative(1) = 1");
    check(Activation::relu_derivative(-1.0) == 0.0, "relu_derivative(-1) = 0");

    check(approx(Activation::leaky_relu(-2.0), -0.02), "leaky_relu(-2) = -0.02");
    check(approx(Activation::leaky_relu_derivative(-1.0), 0.01), "leaky_relu_derivative(-1) = 0.01");

    check(approx(Activation::tanh_(0.0), 0.0), "tanh_(0) = 0");
    check(approx(Activation::tanh_derivative(0.0), 1.0), "tanh_derivative(0) = 1");

    std::vector<double> x = {1.0, 2.0, 3.0};
    std::vector<double> s = Activation::softmax(x);
    double sum = s[0] + s[1] + s[2];
    check(approx(sum, 1.0), "softmax: sums to 1");
    check(s[2] > s[1] && s[1] > s[0], "softmax: preserves order");

    return summary();
}
