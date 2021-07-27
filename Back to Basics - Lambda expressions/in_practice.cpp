#include <vector>
#include <algorithm>

bool myCallback(int i) {
    return i > 5;
}

int main() {
    std::vector<int> data{1, 15, 3, 9, 11};

    // Example A - passing a free function as a function pointer
    int resultA = std::count_if(data.begin(), data.end(), myCallback);
    // Example B - using a lambda expression
    int resultB = std::count_if(data.begin(), data.end(), [](int i) { return i > 5; });
}
