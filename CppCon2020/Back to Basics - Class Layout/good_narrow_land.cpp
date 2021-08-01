#include <cstring>

#include <type_traits>

class NarrowLand {
    unsigned char x;      // offset 0
    unsigned long long y; // offset 8 (still!)
    unsigned long long z; // offset 16
    friend bool operator ==(NarrowLand const& lhs, NarrowLand const &rhs);
};

bool operator ==(NarrowLand const &lhs, NarrowLand const &rhs) {
    if constexpr (std::has_unique_object_representations_v<NarrowLand>)
        return !memcmp(&lhs, &rhs, sizeof(NarrowLand));
    else
        return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

int main() {}
