#include <mutex>
#include <thread>

#include <iostream>

int main() {
    std::mutex mtx; mtx.lock();
    std::thread threadB = std::thread([&]() {
       mtx.lock(); mtx.unlock();
       std::cout << "Hello from B\n";
    });
    std::cout << "Hello from A\n";
    mtx.unlock(); // Now go!
    threadB.join();
    std::cout << "Hello again from A\n";
}

// Mutex is a mutual exclusion mechanism
