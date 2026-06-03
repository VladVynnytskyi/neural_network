#include "network.h"

void Network::addLayer(const Layer& layer) {
    layers.push_back(layer);
}

Matrix Network::forward(const Matrix& input) {
    Matrix current = input;
    for (auto& layer : layers)
        current = layer.forward(current);
    return current;
}

Matrix Network::backward(const Matrix& grad_output, double lr) {
    Matrix grad = grad_output;
    for (int i = layers.size() - 1; i >= 0; i--)
        grad = layers[i].backward(grad, lr);
    return grad;
}
