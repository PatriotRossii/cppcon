#include <cstdio>

#include <cmath>

template<typename T>
bool equal(const T& a, const T& b) {
    return a == b;
}

template<>
bool equal(const double& a, const double& b) {
    return std::abs(a - b) < 0.00001;
}

int main() {
    int a = 2;
    int b = 1;

    printf("%d\n", equal(a, b));

    double d = 3.0;
    double f = 4.0;

    printf("%d\n", equal(d, f));
}
