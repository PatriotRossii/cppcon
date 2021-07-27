namespace internal {
    struct nonFloatingPoint { };
    struct floatingPoint { };

    template<typename T>
    bool equal(const T& a, const T& b, notFloatingPoint) {
        return a == b;
    }

    template<typename T>
    bool equal(const T& a, const T& b, floatingPoint) {
        return std::abs(a - b) < 0.00001;
    }
}

template<typename T>
bool equal(const T& a, const T& b) {
    using namespace internal;

    if constexpr(std::is_floating_point_v<T>) {
        return equal(a, b, floatingPoint{});
    } else {
        return equal(a, b, notFloatingPoint{});
    }
}
