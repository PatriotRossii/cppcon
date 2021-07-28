#include <iostream>
#include <type_traits>

#include <functional>

struct NonTrivial {
    virtual void hello() { }
};

template<class T>
std::enable_if_t<std::is_trivial_v<T>, void>
PrintTriviality(T t) {
    std::cout << "Trivial case: " << typeid(t).name() << '\n';
}

template<class T>
std::enable_if_t<!std::is_trivial_v<T>, void>
PrintTriviality(T t) {
    std::cout << "Non trivial case: " << typeid(t).name() << '\n';
}

int main() {
    PrintTriviality(5);
    PrintTriviality(NonTrivial{});
}
