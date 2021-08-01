#include <cstdint>

#pragma pack(push, 1)
struct timer {
    alignas(4) uint8_t MODE;
    alignas(4) uint32_t DATA;
    alignas(4) uint32_t COUNT;
};
#pragma pack(pop)

int main() {
    static_assert(offsetof(timer, DATA) == 4, "DATA must be at offset 4");
}
