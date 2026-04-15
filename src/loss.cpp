#include "loss.h"
#include <cmath>

double Loss::mse(const std::vector<double>& predicted, const std::vector<double>& target) {
    double sum = 0.0;
    for (size_t i = 0; i < predicted.size(); i++)
        sum += std::pow(predicted[i] - target[i], 2);
    return sum / predicted.size();
}
