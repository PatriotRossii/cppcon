#include <map>
#include <vector>
#include <utility>

int main() {
    using M = std::map<int, int>;

    M myMap = {{1, 2}, {2, 4}, {3, 6}};
    std::pair<int, int> item = *myMap.begin();

    std::pair<M::iterator, bool> ii = myMap.insert({2, 3});

    std::vector<int> a = {1, 2, 3, 5, 7};
    std::vector<long> b = {1, 2, 3, 4, 5};

    std::pair<decltype(a)::iterator, decltype(b)::iterator> mm =
        std::mismatch(a.begin(), a.end(), b.begin(), b.end());
}
