#include <iostream>
#include "matrix.h"

int main() {
    Matrix a(2, 2);
    a.data[0][0] = 1; a.data[0][1] = 2;
    a.data[1][0] = 3; a.data[1][1] = 4;

    Matrix b(2, 2);
    b.data[0][0] = 10; b.data[0][1] = 20;
    b.data[1][0] = 30; b.data[1][1] = 40;

    Matrix c = a.add(b);
    c.print();

    return 0;
}
