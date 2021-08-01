#include <memory>

#include <vector>
#include <list>

#include <iostream>

template<
    template<class, class>
    class Container,
    class T,
    class Allocator = std::allocator<T>>
void fun(const Container<T, Allocator>& c) {
    for (const auto& e: c) {
        std::cout << e << '\n';
    }
}

int main() {
    std::vector<int> v{2, 3, 4};
    fun(v);

    std::list<char> l{'a', 'b', 'c'};
    fun(l);
}
