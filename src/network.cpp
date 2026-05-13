#include "network.h"

void Network::addLayer(const Layer& layer) {
    layers.push_back(layer);
}

Matrix Network::predict(const Matrix& input) const {
    Matrix current = input;
    for (const auto& layer : layers) {
        current = layer.forward(current);
    }
    return current;
}