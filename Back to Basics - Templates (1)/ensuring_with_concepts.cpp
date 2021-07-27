#include <cstdint>
#include <type_traits>

#include <memory>

using namespace std;

template<typename T, size_t SIZE>
requires(not std::is_pointer_v<T>) struct Array {
    T* data() const { return std::addressof(mData[0]); }
    const T* data() { return std::addressof(mData[0]); }

    constexpr size_t size() const { return SIZE; }
    T* begin() { return data(); }
    T* end() { return data() + size(); }
    T& operator[](size_t idx) { return mData[idx]; }

    T mData[SIZE];
};

int main() {
    int x{22};

//  Array<int*, 2> invalid{&x};
    Array<int, 2> valid{x};
}
