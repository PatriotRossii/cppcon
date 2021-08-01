#include <iostream>

template<typename T, typename U>
struct FullType {
    FullType() {
        std::cout << "FullType CTOR" << '\n';
    }
};

template<typename T>
struct FullType<T, T> {
    FullType() {
        std::cout << "FullType same type CTOR" << '\n';
    }
};

int main() {
    FullType<int, bool> i;
    FullType<int, int> j;
}
