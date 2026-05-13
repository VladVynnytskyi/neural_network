#pragma once
#include <vector>
#include "layer.h"

class Network {
public:
    std::vector<Layer> layers;

    void addLayer(const Layer& layer);
    Matrix predict(const Matrix& input) const;
};