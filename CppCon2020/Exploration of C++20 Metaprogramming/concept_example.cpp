#include <iostream>

template<typename T>
concept trivial = std::is_trivial_v<T>;

int main() {
    std::cout << "Trivial: " << trivial<int> << "\n";
}
