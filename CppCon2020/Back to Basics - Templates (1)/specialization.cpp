#include <cstring>
#include <iostream>

template<typename T>
T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

template<>
const char* min<const char*>(const char* const& a, const char* const& b) {
    return strcmp(a, b) < 0 ? a : b;
}

int main() {
    const char* a = "XYZ";
    const char* b = "DEF";

    std::cout << min(a, b) << std::endl;
}
