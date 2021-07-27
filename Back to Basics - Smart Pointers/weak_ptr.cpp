#include <iostream>
#include <memory>

int main() {
    auto sharedPtr = std::make_shared<int>(2020);
    std::weak_ptr<int> weakPtr(sharedPtr);

    std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl;
    std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl;
    std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;

    if(std::shared_ptr<int> sharedPtr1 = weakPtr.lock()) {
        std::cout << "*sharedPtr: " << *sharedPtr1 << std::endl;
    } else {
        std::cout << "Don't get the resource" << std::endl;
    }

    sharedPtr.reset();
    if(std::shared_ptr<int> sharedPtr1 = weakPtr.lock()) {
        std::cout << "*sharedPtr: " << *sharedPtr1 << std::endl;
    } else {
        std::cout << "Don't get the resource" << std::endl;
    }
}
