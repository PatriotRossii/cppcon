#include <latch>
#include <thread>
#include <iostream>

int main() {
    std::latch myLatch(2);
    std::thread threadB = std::thread([&]() {
        myLatch.arrive_and_wait();
        std::cout << "Hello from B\n";
    });
    std::cout << "Hello from A\n";
    myLatch.arrive_and_wait();
    threadB.join();
    std::cout << "Hello again from A\n";
}
