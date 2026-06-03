#include "data_loader.h"
#include <fstream>
#include <sstream>
#include <map>

Dataset DataLoader::loadIris(const std::string& path) {
    Dataset dataset;
    std::ifstream file(path);
    std::string line;

    std::getline(file, line);

    std::map<std::string, int> label_map = {
        {"Iris-setosa", 0},
        {"Iris-versicolor", 1},
        {"Iris-virginica", 2}
    };

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string token;

        Matrix input(4, 1);
        for (int i = 0; i < 4; i++) {
            std::getline(ss, token, ',');
            input.data[i][0] = std::stod(token);
        }

        std::getline(ss, token);
        token.erase(token.find_last_not_of(" \r\n") + 1);

        int label = label_map[token];
        Matrix target(3, 1);
        target.data[label][0] = 1.0;

        dataset.inputs.push_back(input);
        dataset.targets.push_back(target);
    }

    return dataset;
}
