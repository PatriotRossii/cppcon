#include <cstdint>

using namespace std;

bool write(const char*, size_t) {
    // Some code for writing
    return true;
}

bool Send(const char* data, size_t size) {
    if(!data) { return false; }
    return write(data, size);
}

void Read(char* data, size_t size) {
    if(!data) { return; }
    // fill buffer with data
}

int main() {
    char buffer[1024]{};

    Read(buffer, sizeof(buffer));
    Send(buffer, sizeof(buffer));

    char buffer2[2048]{};

    Read(buffer, sizeof(buffer2));
    Read(buffer, sizeof(buffer2));
}

// The pattern of passing value and length is:
//  * Typical C API
//  * Error-prone
//  * More to write & read
