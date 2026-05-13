#include "loss.h"
#include <cmath>
#include <algorithm>

double Loss::mse(const std::vector<double>& predicted, const std::vector<double>& target) {
    double sum = 0.0;
    for (size_t i = 0; i < predicted.size(); i++)
        sum += std::pow(predicted[i] - target[i], 2);
    return sum / predicted.size();
}

double Loss::binary_cross_entropy(const std::vector<double>& predicted, const std::vector<double>& target) {
    double loss = 0.0;
    double epsilon = 1e-15;
    for (size_t i = 0; i < predicted.size(); i++) {
        double p = predicted[i];
        if (p < epsilon) p = epsilon;
        if (p > 1.0 - epsilon) p = 1.0 - epsilon;
        loss += target[i] * std::log(p) + (1.0 - target[i]) * std::log(1.0 - p);
    }
    return -loss / predicted.size();
}

double Loss::categorical_cross_entropy(const std::vector<double>& predicted, const std::vector<double>& target) {
    double loss = 0.0;
    double epsilon = 1e-15;
    for (size_t i = 0; i < predicted.size(); i++) {
        double p = predicted[i];
        if (p < epsilon) p = epsilon;
        if (p > 1.0 - epsilon) p = 1.0 - epsilon;
        loss += target[i] * std::log(p);
    }
    return -loss;
}