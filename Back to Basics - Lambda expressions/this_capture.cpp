#include <iostream>

struct Onion {
    Onion() {
        std::cout << "I'm a new onion here\n";
    }
    Onion(const Onion& another) {
        std::cout << "Yay! Creating an onion copy!\n";
    }
    void greetings() {
        std::cout << "Hello, my friends!\n";
    }
    void grow() {
        auto lambda = [this]() {
            this->greetings();
        }; // C++11
        lambda();

        auto another_lambda = [self = *this]() mutable {
            self.greetings();
        }; // C++14
        another_lambda();

        auto yet_another_lambda = [*this]() mutable {
            this->greetings();
        };
        yet_another_lambda();
    }
};

int main() {
    Onion onion;
    onion.grow();
}
