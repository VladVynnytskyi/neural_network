#pragma once
#include "matrix.h"
#include <vector>
#include <string>

struct Dataset {
    std::vector<Matrix> inputs;
    std::vector<Matrix> targets;
};

namespace DataLoader {
    Dataset loadIris(const std::string& path);
}
