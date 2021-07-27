#include <vector>
#include <algorithm>

#include <string>

bool myCallback(int i) {
    return i > 5;
}

int count_str_starting_with(const std::vector<std::string>& data, char ch) {
    return std::count_if(data.begin(), data.end(),
      [ch](const std::string& str) {
       return !str.empty() && str[0] == ch;
    });
}

int main() {
    std::vector<int> data{1, 15, 3, 9, 11};

    // Example A - passing a free function as a function pointer
    int resultA = std::count_if(data.begin(), data.end(), myCallback);
    // Example B - using a lambda expression
    int resultB = std::count_if(data.begin(), data.end(), [](int i) { return i > 5; });
}
