#include <iostream>
#include <typeinfo>

template<typename T>
struct Wrapper {
    Wrapper(T t_): t(t_) {
        std::cout << "Wrapper: " << typeid(T).name() << '\n';
    }
    T t;
};

template<typename T>
void foo(T t) {
    std::cout << "Foo: " << typeid(T).name() << '\n';
}

template<typename T>
void foo(Wrapper<T> t) {
    std::cout << "Foo with wrapper: " << typeid(T).name() << '\n';
}

int main() {
    int d; foo(d);
    Wrapper j(5); foo(j);
}
