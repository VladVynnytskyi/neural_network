#include "matrix.h"
#include "tests.h"

int main() {
    // constructor zeros
    Matrix m(2, 3);
    check(m.rows == 2 && m.cols == 3, "constructor: correct dimensions");
    check(m.data[0][0] == 0.0 && m.data[1][2] == 0.0, "constructor: initialized to zero");

    // add
    Matrix a(2, 2), b(2, 2);
    a.data[0][0] = 1; a.data[0][1] = 2;
    a.data[1][0] = 3; a.data[1][1] = 4;
    b.data[0][0] = 5; b.data[0][1] = 6;
    b.data[1][0] = 7; b.data[1][1] = 8;
    Matrix c = a.add(b);
    check(c.data[0][0] == 6 && c.data[1][1] == 12, "add: correct values");

    // multiply
    Matrix p(2, 3), q(3, 2);
    p.data[0][0]=1; p.data[0][1]=2; p.data[0][2]=3;
    p.data[1][0]=4; p.data[1][1]=5; p.data[1][2]=6;
    q.data[0][0]=7; q.data[0][1]=8;
    q.data[1][0]=9; q.data[1][1]=10;
    q.data[2][0]=11; q.data[2][1]=12;
    Matrix r = p.multiply(q);
    check(r.rows == 2 && r.cols == 2, "multiply: correct shape");
    check(r.data[0][0] == 58 && r.data[1][1] == 154, "multiply: correct values");

    // transpose
    Matrix t = a.transpose();
    check(t.rows == 2 && t.cols == 2, "transpose: shape preserved for square");
    check(t.data[0][1] == a.data[1][0], "transpose: values flipped");

    Matrix rect(2, 3);
    rect.data[0][0]=1; rect.data[0][1]=2; rect.data[0][2]=3;
    rect.data[1][0]=4; rect.data[1][1]=5; rect.data[1][2]=6;
    Matrix tr = rect.transpose();
    check(tr.rows == 3 && tr.cols == 2, "transpose: shape flipped for non-square");
    check(tr.data[2][0] == 3 && tr.data[2][1] == 6, "transpose: correct values for non-square");

    // elementWiseMultiply
    Matrix e = a.elementWiseMultiply(b);
    check(e.data[0][0] == 5 && e.data[1][1] == 32, "elementWiseMultiply: correct values");

    return summary();
}
