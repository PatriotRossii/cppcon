#include <latch>
#include <thread>
#include <iostream>

int main() {
    std::latch myLatch(1);
    std::thread threadB = std::thread([&]() {
        myLatch.wait();
        std::cout << "Hello from B\n";
    });
    std::cout << "Hello from A\n";
    myLatch.arrive();
    threadB.join();
    std::cout << "Hello again from A\n";
}
