#include <atomic>
#include <thread>

#include <iostream>

int main() {
    std::atomic<bool> ready{false};
    std::thread threadB = std::thread([&]() {
        while(!ready) { }
       std::cout << "Hello from B\n";
    });
    std::cout << "Hello from A\n";
    ready = true;
    threadB.join();
    std::cout << "Hello again from A\n";
}

// Huge waste of time on a single-core system
// Compiler can see that if this threaed never sleeps then ready
// will never change, and hoist it out of the loop
// Still have UB there. Don't do this

