#include <array>

#include <cstdint>

template<size_t N>
using CharArray = std::array<char, N>;

int main() {
    CharArray<24> ar;
}
