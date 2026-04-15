#pragma once
#include <vector>

namespace Loss {
    double mse(const std::vector<double>& predicted, const std::vector<double>& target);
}
