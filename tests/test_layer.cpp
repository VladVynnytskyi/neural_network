#include "layer.h"
#include "tests.h"

int main() {
    Layer layer(3, 4, ActivationType::RELU);

    Matrix input(3, 1);
    input.data[0][0] = 0.5;
    input.data[1][0] = -0.2;
    input.data[2][0] = 0.1;

    Matrix output = layer.forward(input);
    check(output.rows == 4 && output.cols == 1, "forward: correct output shape");

    for (int i = 0; i < 4; i++)
        check(output.data[i][0] >= 0.0, "forward RELU: no negative outputs");

    // save weights before backward
    double w00_before = layer.weights.data[0][0];

    Matrix grad(4, 1);
    for (int i = 0; i < 4; i++) grad.data[i][0] = 1.0;
    Matrix grad_input = layer.backward(grad, 0.01);

    check(grad_input.rows == 3 && grad_input.cols == 1, "backward: correct gradient shape");
    check(layer.weights.data[0][0] != w00_before, "backward: weights updated");

    Layer layer2(4, 2, ActivationType::SIGMOID);
    Matrix out2 = layer2.forward(output);
    check(out2.rows == 2 && out2.cols == 1, "forward sigmoid: correct output shape");
    for (int i = 0; i < 2; i++)
        check(out2.data[i][0] > 0.0 && out2.data[i][0] < 1.0, "forward sigmoid: output in (0,1)");

    return summary();
}
