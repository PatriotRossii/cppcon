#include <iostream>

int main() {
    int x = 42;

    auto myLamb = [x]() {
        std::cout << "Hello from a lambda expression, value = " << x << std::endl;
    };
    auto myAnotherLamb = [&x]() {
        std::cout << "Hello from an another lambda expression, value = " << x << std::endl;
    };

    x = 7;

    myLamb();
    myAnotherLamb();
}
