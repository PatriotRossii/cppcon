#include <iostream>

#include <string>

int main() {
    int x = 25;
    int y = 100;

    std::string sample{"Hello, World!"};

    auto myLamb = [varA = 10, varB = x,
                   &varC = y, varD = std::move(sample)]() {
        std::cout << "varA: " << varA << std::endl;
        std::cout << "varB: " << varB << std::endl;
        std::cout << "varC: " << varC << std::endl;
        std::cout << "varD: " << varD << std::endl;;

        ++varC;
    };
    myLamb();

    std::cout << "\nx: " << x << std::endl;
    std::cout << "y: " << y << std::endl;
    std::cout << "sample: " << sample << std::endl;
}
