#include <iostream>

class Empty { };     // sizeof(Empty) is probably 1
Empty e;             // sizeof(e) is probably 1

class Empties { // sizeof(Empties) is probably 3
    Empty e1_;  // offset 0
    Empty e2_;  // offset 1
    Empty e3_;  // offset 2
};

class Empties20 {    // sizeof(Empties) is now probably 1
    [[no_unique_address]] Empty e1_;
    [[no_unique_address]]  Empty e2_;
    [[no_unique_address]]  Empty e3_;
};

int main() {
    std::cout << "Size of Empty: " << sizeof(Empty) << std::endl;
    std::cout << "Size of Empties: " << sizeof(Empties) << std::endl;
    std::cout << "Size of Empties20: " << sizeof(Empties20) << '\n';
}
