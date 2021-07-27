#include <barrier>
#include <thread>
#include <iostream>

int main() {
    std::barrier b(2, []() { std::cout << "Green flag, go!\n"; });
    std::thread threadB = std::thread([&]() {
        std::cout << "B is setting up\n";
        b.arrive_and_wait();
        std::cout << "B is running\n";
    });
    std::cout << "A is setting up\n";
    b.arrive_and_wait();
    std::cout << "A is running\n";
    threadB.join();
}
