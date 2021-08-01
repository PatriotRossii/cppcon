#include <cstddef>
#include <cstdint>

#include <type_traits>

using special_register = uint32_t volatile;

class UART {
public:
    special_register ULCON;
    special_register UCON;
    special_register USTAT;
    special_register UTXBUF;
    special_register URXBUF;
    special_register RBRDIV;
};

int main() {
    static_assert(sizeof(special_register) == 4,
                  "special register must be 4 bytes in size");
    static_assert(alignof(special_register) == 4,
                  "special register must be word-aligned");
    static_assert(std::is_unsigned_v<special_register>,
                  "special_register must be unsigned");
    static_assert(std::is_standard_layout_v<UART>,
                  "UART must be standard layout");
    static_assert(offsetof(UART, UCON) == 4,
                  "UCON member must be at offset 4 within UART");
}
