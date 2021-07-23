#include <tuple>

#include <utility>
#include <string>

// simulate a "pack" of data members

template<class R, class... Args>
struct DeferredCall {
    std::tuple<Args...> arguments_;
    R operator()() const { }
};

int main() {
    DeferredCall<int, int, int> call {
        std::make_tuple(1, 2)
    };

    // forward sets of arguments to pair's constructor

    std::pair<std::string, std::string> myPair(
        std::piecewise_construct,
        std::make_tuple("abc", 3),
        std::make_tuple(100, '*')
    );
}
