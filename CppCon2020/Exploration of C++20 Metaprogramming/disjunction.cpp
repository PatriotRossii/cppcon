#include <iostream>
#include <type_traits>

template<typename T, typename... Ts>
bool IsTwoSame() {
    std::cout << "disjunction: " << std::disjunction_v<std::is_same<T, Ts>...> << '\n';
    return std::disjunction_v<std::is_same<T, Ts>...>;
}

int main() {
    IsTwoSame<int, bool, int>();
}
