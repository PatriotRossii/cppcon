#include <iostream>
#include <type_traits>

using namespace std;

struct NonTrivial {
    virtual void hello() { }
};

template<typename T>
void PrintTriviality(T t) {
    if constexpr (std::is_trivial_v<T>) {
        std::cout << "Trivial case: " << typeid(t).name() << '\n';
    } else {
        std::cout << "Non trivial case: " << typeid(t).name() << '\n';
    }
}

int main() {
    PrintTriviality(5);
    PrintTriviality(NonTrivial{});
}
