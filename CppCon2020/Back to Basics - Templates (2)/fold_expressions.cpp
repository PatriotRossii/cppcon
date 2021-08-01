#include <iostream>
#include <string>

auto Normalize(const std::string& t) { return t; }
auto Normalize(const char* t) { return std::string{t}; }

template<class T>
auto Normalize(const T& t) {
    return std::to_string(t);
}

template<typename T, typename... Ts>
void print(const T& targ, const Ts&... args) {
    std::cout << targ;
    auto coutSpaceAndArg = [](const auto& arg) {
        std::cout << ' ' << arg;
    };
    (..., coutSpaceAndArg(args));
}

template<typename T, typename... Ts>
auto buildCSVLine(const T& targ, const Ts&... args) {
    auto ret{Normalize(targ)};
    auto addColonAndNormalize = [&](const auto& arg) {
        ret += ',';
        ret += Normalize(arg);
    };
    (..., addColonAndNormalize(args));
    return ret;
}

int main() {
    print("Hello", "C++", 20);

    auto s = buildCSVLine("Hello", std::string{"C++"}, 20, "@CppCon");
    std::cout << '\n' << s.c_str() << '\n';
}
