#include <iostream>
#include <type_traits>

template<typename T, typename... Ts>
bool IsAllSame() {
    std::cout << "conjuction: " << std::conjunction_v<std::is_same<T, Ts>...> << '\n';
    return std::conjunction_v<std::is_same<T, Ts>...>;
}

template<typename T, typename... Ts>
bool IsAllSame(T, Ts...) {
    std::cout << "conjunction: " << std::conjunction_v<std::is_same<T, Ts>...> << '\n';
    return std::conjunction_v<std::is_same<T, Ts>...>;
}

int main() {
    IsAllSame<int, int, int>();
    IsAllSame<>(5, 20.);
}
