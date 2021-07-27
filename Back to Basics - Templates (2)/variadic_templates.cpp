#include <string>

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

int main() { }
