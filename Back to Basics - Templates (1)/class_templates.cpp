#include <cstdint>

template<typename T,
         std::size_t SIZE>
struct Array {
    T mData[SIZE];

    const T* data() const {
        return mData;
    }
    T* data();

    constexpr std::size_t size() const {
        return SIZE;
    }

    T* begin() {
        return data();
    }
    T* end() {
        return data() + size();
    }
};

template<typename T, std::size_t SIZE>
T* Array<T, SIZE>::data() {
    return mData;
}

int main() {
    Array<int, 2> ai{3, 5};
    Array<double, 2> ad{2.0};
}
