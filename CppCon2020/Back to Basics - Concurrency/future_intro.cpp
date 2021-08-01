#include <future>

#include <iostream>

int main() {
    std::future<int> f1 = std::async([]() {
        std::cout << "Hello from thread A!\n";
        return 1;
    });

    std::future<int> f2 = std::async([]() {
        std::cout << "Hello from thread B!\n";
        return 2;
    });

    int result = f1.get() + f2.get();
    std::cout << "Result: " << result;
}
