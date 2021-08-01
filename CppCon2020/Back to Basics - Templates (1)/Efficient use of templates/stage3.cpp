#include <cstdint>

#include <array>

using namespace std;

bool write(const char*, size_t) {
    // Some code for writing
    return true;
}

template<size_t N>
bool Send(const std::array<char, N>& data) {
    return write(data.data(), data.size());
}

template<size_t N>
void Read(std::array<char, N>& data) {
    // fill buffer with data
}

int main() {
    std::array<char, 1024> buffer;

    Read(buffer);
    Send(buffer);

    std::array<char, 2048> buffer2;

    Read(buffer2);
    Send(buffer2);
}

// Alternative: Make Read/Send a template with a NTTP for the
// size
