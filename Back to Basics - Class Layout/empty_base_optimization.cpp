#include <iostream>

class Empty1 {};
class Empty2 {};
class Empty3 {};

class NonEmpty1 { char x; };
class NonEmpty2 { char x; };

class Derived: public NonEmpty1, public NonEmpty2, public Empty1 { };

class OtherDerived: public Empty1, public Empty2, public Empty3 {
    char member_;
};

int main() {
    std::cout << "Size of Derived: " << sizeof(Derived) << '\n';
    std::cout << "Size of OtherDerived: " << sizeof(OtherDerived) << '\n';
}
