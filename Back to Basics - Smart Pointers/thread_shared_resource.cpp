#include <iostream>
#include <memory>
#include <thread>

using namespace std::literals::chrono_literals;

void showNumber(std::shared_ptr<int> integer) {
    std::cout << *integer << std::endl;
}

void threadCreator() {
    auto sharedPtr = std::make_shared<int>(2020);

    std::thread t1(showNumber, sharedPtr);
    std::thread t2(showNumber, sharedPtr);

    t1.detach();
    t2.detach();
}

int main() {
    threadCreator();
    std::this_thread::sleep_for(1s);
}
