#include <string>

#include <map>

auto compare = [](const std::string& a, const std::string& b) {
    return a.size() < b.size();
};

struct MyCompare {
    bool operator()(const std::string& a, const std::string& b) const {
        return a.size() < b.size();
    }
};

int main() {
    std::map<std::string, int, MyCompare> myMapA = {
        {"orange", 45}, {"apple", 95}, {"kiwi", 40},
        {"grapefruit", 22}
    };

    std::map<std::string, int, decltype(compare)> myMapB = {
        {"orange", 45}, {"apple", 95}, {"kiwi", 40},
        {"grapefruit", 22}
    };
}
