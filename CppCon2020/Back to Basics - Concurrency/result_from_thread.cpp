#include <thread>

#include <iostream>

int main() {
    int result = 0;
    std::thread threadB = std::thread([&]() {
        std::cout << "Hello from threadB!\n";
        result = 42;
    });
    printf("Hello from threadA!\n");
    threadB.join();
    printf("The result of threadB was %d\n", result);
}
