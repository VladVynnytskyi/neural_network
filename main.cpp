#include <iostream>
#include <vector>
#include "matrix.h"
#include "layer.h"
#include "network.h"
#include "activations.h"
#include "loss.h"

int main() {
    Network net;
    net.addLayer(Layer(3, 4, ActivationType::RELU));
    net.addLayer(Layer(4, 2, ActivationType::SIGMOID));

    Matrix input(3, 1);
    input.data[0][0] = 0.5;
    input.data[1][0] = -0.2;
    input.data[2][0] = 0.1;

    std::vector<double> target = {1.0, 0.0};

    Matrix output = net.forward(input);
    std::cout << "Output before training:\n";
    output.print();

    Matrix grad(2, 1);
    for (int i = 0; i < 2; i++)
        grad.data[i][0] = 2.0 * (output.data[i][0] - target[i]) / 2.0;

    net.backward(grad, 0.01);

    Matrix output_after = net.forward(input);
    std::cout << "\nOutput after one backward pass:\n";
    output_after.print();

    return 0;
}
