#include <string>

#include <utility>

auto Normalize(const std::string& t) { return t; }
auto Normalize(const char* t) { return std::string{t}; }

template<class T>
auto Normalize(const T& t) {
    return std::to_string(t);
}

template<typename T, typename... Ts> auto _StrCat(
    std::string& ret, const T& targ, const Ts&... args
) {
    ret += Normalize(targ);
    if constexpr(sizeof...(args) > 0) {
        _StrCat(ret, args...);
    }
}

template<typename T, typename... Ts> auto StrCat(
    const T& targ, const Ts&... args
) {
    std::string ret{Normalize(targ)};

    _StrCat(ret, args...);

    return ret;
}

namespace details::array_single_compare {
    template<typename T, size_t N, typename U, size_t... I>
    constexpr bool Compare(const T (&a)[N], const U& b, std::index_sequence<I...>) {
        return ((a[I] == b) && ... );
    }
}

template<typename T, size_t N, typename U>
constexpr bool Compare(const T (&a)[N], const U& b) {
    return details::array_single_compare::Compare(a, b, std::make_index_sequence<N>{});
}


namespace details::array_compare {
    template<typename T, size_t N, size_t... I>
    constexpr bool Compare(const T (&a)[N], const T (&b)[N], std::index_sequence<I...>) {
        return ((a[I] == b[I]) && ...);
    }
}

template<typename T, size_t N>
constexpr bool Compare(const T (&a)[N], const T (&b)[N]) {
    return details::array_compare::Compare(a, b, std::make_index_sequence<N>{});
}

struct MACAddress {
    unsigned char value[6];
};

int main() {
    constexpr MACAddress macA{2, 2, 2, 2, 2, 2};
    constexpr MACAddress macB{2, 2, 2, 2, 2, 4};
    constexpr MACAddress macC{2, 2, 2, 2, 2, 2};

    // Compare each element against value
    static_assert(Compare(macA.value, 2));
    static_assert(!Compare(macB.value, 2));

    // Compare two equally sized arrays
    static_assert(!Compare(macA.value, macB.value));
    static_assert(Compare(macA.value, macC.value));
}
