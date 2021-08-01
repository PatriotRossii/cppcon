#include <iostream>

#include <cstring>

class NarrowLand {
public:
    unsigned char x;        // offset 0
    unsigned long long y;   // offset 8 (still!)
    unsigned long long z;   // offset 16
    friend bool operator ==(NarrowLand const& lhs, NarrowLand const &rhs);
};

bool operator ==(NarrowLand const &lhs, NarrowLand const &rhs) {
    return !memcmp(&lhs, &rhs, sizeof(NarrowLand));
}

NarrowLand global { 'x', 12345ULL, 54321ULL };

bool g() {
    NarrowLand local { 'x', 12345ULL, 54321ULL };
    return local == global;
}

int main() {
    if (g()) {
        std::cout << "normal" << '\n';
    } else {
        std::cout << "eat shit" << '\n';
    }
}
