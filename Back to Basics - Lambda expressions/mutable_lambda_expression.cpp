#include <iostream>

int main() {
    int x = 0;
    auto myLamb = [x]() mutable { return ++x; };

    std::cout << "Value of the x: " << x << std::endl;
    myLamb();
    std::cout << "Value of the x after lambda invoking: " << x << std::endl;

    // By default lambda can't mutate captured values
}
