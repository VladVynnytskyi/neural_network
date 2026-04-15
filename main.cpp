#include <iostream>
#include "matrix.h"

int main() {
    Matrix weights(2, 2);
    weights.data[0][0] = 1; weights.data[0][1] = 2;
    weights.data[1][0] = 3; weights.data[1][1] = 4;

    Matrix input(2, 1);
    input.data[0][0] = 5;
    input.data[1][0] = 6;

    Matrix output = weights.multiply(input);
    output.print();

    return 0;
}
