#include <type_traits>
#include <cmath>

#include <iostream>

template<typename T>
requires (not std::is_floating_point_v<T>) bool equal(
  const T& a, const T& b) {
    return a == b;
}

template<typename T>
requires (std::is_floating_point_v<T>) bool equal(
  const T& a, const T& b) {
    return std::abs(a - b) < 0.00001;
}

int main() {
    int a = 2;
    int b = 1;

    std::cout << equal(a, b) << std::endl;

    double d = 3.0;
    double f = 4.0;

    std::cout << equal(d, f) << std::endl;
}
