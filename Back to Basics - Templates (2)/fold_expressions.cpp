#include <iostream>

template<typename T, typename... Ts>
void print(const T& targ, const Ts&... args) {
    std::cout << targ;
    auto coutSpaceAndArg = [](const auto& arg) {
        std::cout << ' ' << arg;
    };
    (..., coutSpaceAndArg(args));
}

int main() {
    print("Hello", "C++", 20);
}
