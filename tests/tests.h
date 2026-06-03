#pragma once
#include <iostream>
#include <cmath>
#include <string>

inline int tests_passed = 0;
inline int tests_failed = 0;

inline void check(bool cond, const std::string& name) {
    if (cond) { std::cout << "[PASS] " << name << "\n"; tests_passed++; }
    else       { std::cout << "[FAIL] " << name << "\n"; tests_failed++; }
}

inline bool approx(double a, double b, double eps = 1e-6) {
    return std::abs(a - b) < eps;
}

inline int summary() {
    std::cout << "\n" << tests_passed << "/" << (tests_passed + tests_failed) << " tests passed\n";
    return tests_failed > 0 ? 1 : 0;
}
