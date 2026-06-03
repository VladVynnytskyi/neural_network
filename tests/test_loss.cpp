#include "loss.h"
#include "tests.h"

int main() {
    std::vector<double> perfect = {1.0, 0.0, 0.0};
    std::vector<double> target  = {1.0, 0.0, 0.0};
    check(approx(Loss::mse(perfect, target), 0.0), "mse: perfect prediction = 0");

    std::vector<double> pred2 = {1.0, 0.0};
    std::vector<double> tgt2  = {0.0, 0.0};
    check(approx(Loss::mse(pred2, tgt2), 0.5), "mse: known value");

    std::vector<double> p1 = {0.9999};
    std::vector<double> t1 = {1.0};
    check(Loss::binary_cross_entropy(p1, t1) < 0.01, "binary_cross_entropy: near-perfect ≈ 0");

    std::vector<double> p2 = {0.9999, 0.0001};
    std::vector<double> t2 = {1.0, 0.0};
    check(Loss::categorical_cross_entropy(p2, t2) < 0.01, "categorical_cross_entropy: near-perfect ≈ 0");

    std::vector<double> p3 = {0.5, 0.5};
    std::vector<double> t3 = {1.0, 0.0};
    double bce = Loss::binary_cross_entropy(p3, t3);
    check(bce > 0.0, "binary_cross_entropy: imperfect > 0");

    return summary();
}
