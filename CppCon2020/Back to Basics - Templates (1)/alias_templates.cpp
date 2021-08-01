#include <array>

#include <cstdint>

template<size_t N>
using CharArray =
#ifdef PRODUCT_A
    Array<char, N>;
#else
    std::array<char, N>;
#endif

int main() {
    CharArray<24> ar;
}
