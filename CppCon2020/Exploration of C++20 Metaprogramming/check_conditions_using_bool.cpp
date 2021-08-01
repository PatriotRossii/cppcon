#include <iostream>
#include <type_traits>

template<typename T, typename U>
bool IsSame = std::is_same_v<T, U>;

int main() {
    std::cout << "IsSame: " << IsSame<int, double>; // IsSame: 0
}
