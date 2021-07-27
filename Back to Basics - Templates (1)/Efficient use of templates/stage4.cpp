#include <cstdint>

#include <array>
#include <span>

using namespace std;

bool write(const char*, size_t) {
    // Some code for writing
    return true;
}

bool Send(const span<char>& data) {
    return write(data.data(), data.size());
}

void Read(span<char> data) {
    // fill buffer with data
    int i = 0;
    for(auto& c: data) {
        c = i % 256;
        ++i;
    }
}

int main() {
    std::array<char, 1024> buffer;

    Read(buffer);
    Send(buffer);

    char buffer2[2048];

    Read(buffer2);
    Send(buffer2);
}

// Better: Abstract the size away
//  * Cleaned up the code safely with little overhead
