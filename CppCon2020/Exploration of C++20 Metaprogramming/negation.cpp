#include <iostream>
#include <type_traits>

template<typename T, typename U>
bool IsNotSame() {
    std::cout << "!IsSame: " << std::negation_v<std::is_same<T, U>> << '\n';
    return std::negation_v<std::is_same<T, U>>;
}

int main() {
    IsNotSame<int, int>();
}
