#include <type_traits>
#include <iostream>

template<typename T>
std::enable_if_t<not std::is_floating_point_v<T>, bool>
  equal(const T& a, const T& b) {
    return a == b;
}

template<typename T>
std::enable_if_t<std::is_floating_point_v<T>, bool>
  equal(const T& a, const T& b) {
    return std::abs(a - b) < 0.00001;
}

int main() {
    int a = 2;
    int b = 1;

    std::cout << equal(a, b) << '\n';

    double d = 3.0;
    double f = 4.0;

    std::cout << equal(d, f) << '\n';
}
