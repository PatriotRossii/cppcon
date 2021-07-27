#include <thread>

#include <chrono>

int main() {
    using SC = std::chrono::steady_clock;
    auto deadline = SC::now() + std::chrono::seconds(1);

    int counter = 0;

    std::thread threadB = std::thread([&]() {
        while (SC::now() < deadline)
            printf("B: %d\n", ++counter);
    });
    while (SC::now() < deadline)
        printf("A: %d\n", ++counter);
    threadB.join();
}
