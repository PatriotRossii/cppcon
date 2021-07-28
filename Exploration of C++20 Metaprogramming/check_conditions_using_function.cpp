#include <iostream>
#include <type_traits>

template<typename T, typename U>
void IsSame() {
    std::cout << "IsSame: " << std::is_same_v<T, U> << '\n';
}

int main() {
    IsSame<int, bool>();
}
