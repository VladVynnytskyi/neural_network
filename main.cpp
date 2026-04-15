#include <iostream>
#include "matrix.h"

int main() {
    Matrix m(3, 3);

    m.data[0][0] = 1;
    m.data[0][1] = 2;
    m.data[0][2] = 3;
    m.data[1][0] = 4;
    m.data[1][1] = 5;
    m.data[1][2] = 6;
    m.data[2][0] = 7;
    m.data[2][1] = 8;
    m.data[2][2] = 9;

    m.print();

    return 0;
}
