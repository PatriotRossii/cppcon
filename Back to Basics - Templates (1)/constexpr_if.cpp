#include <type_traits>
#include <string>

#include <cassert>

template<typename T>
auto getValue(T t) {
    if constexpr(std::is_pointer_v<T>) {
        assert(nullptr != t);
        return *t;
    } else {
        return t;
    }
}

template<typename T>
std::string str(T t) {
    if constexpr(std::is_convertible_v<T, std::string>) {
        return t;
    } else {
        return std::to_string(t);
    }
}

int main() {
    int i = 4;
    int* ip = &i;

    auto iv = getValue(i);
    auto ipv = getValue(ip);
    auto itv = getValue(43);

    auto s = str(std::string{"42"});
    auto d = str(42);
}
