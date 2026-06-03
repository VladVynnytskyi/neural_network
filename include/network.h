#pragma once
#include <vector>
#include "layer.h"

class Network {
public:
    std::vector<Layer> layers;

    void addLayer(const Layer& layer);
    Matrix forward(const Matrix& input);
    Matrix backward(const Matrix& grad_output, double lr);
};
