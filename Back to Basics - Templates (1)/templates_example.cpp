#include <cstdint>

template<typename T,
         std::size_t N>
constexpr auto size(const T (&)[N]) {
    return N;
}

int main() {
    char buffer[16]{};

    // prefer a range-based for-loop
    for(int i = 0; i != size(buffer); ++i) {
        // do something with buffer
    }
}
