#include <cstring>

class NarrowLand {
    unsigned long long x; // offset 0
    unsigned long long y; // offset 8
    unsigned long long z; // offset 16
    friend bool operator ==(NarrowLand const& lhs, NarrowLand const &rhs);
};

bool operator ==(NarrowLand const &lhs, NarrowLand const &rhs) {
    return !memcmp(&lhs, &rhs, sizeof(NarrowLand));
}

int main() {}
