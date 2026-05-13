#pragma once
#include <vector>

namespace Loss {
    double mse(const std::vector<double>& predicted, const std::vector<double>& target);
    double binary_cross_entropy(const std::vector<double>& predicted, const std::vector<double>& target);
    double categorical_cross_entropy(const std::vector<double>& predicted, const std::vector<double>& target);
}