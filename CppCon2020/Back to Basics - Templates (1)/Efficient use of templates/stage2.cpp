#include <cstdint>

#include <array>

using namespace std;

bool write(const char*, size_t) {
    // Some code for writing
    return true;
}

bool Send(const std::array<char, 1024>& data) {
    return write(data.data(), data.size());
}

void Read(std::array<char, 1024>& data) {
    // fill buffer with data
}

int main() {
    std::array<char, 1024> buffer;

    Read(buffer);
    Send(buffer);

    std::array<char, 2048> buffer2;

//  Read(buffer2);
//  Read(buffer2);
}

// It's better with std::array
//  Disadvantage here: The size must always be the same
