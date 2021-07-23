#include <utility>
#include <tuple>

#include <functional>
#include <cassert>

#include <string>

std::pair<int, bool> foo() {
    std::tuple<int, int, int> t = {1, 2, 3};
    return {42, false};
}

auto foo_deduced() {
    std::tuple t = std::make_tuple(1, 2, 3);
    return std::make_pair(42, false);
}

void pairs_and_tuples_of_references() {
    int a = 1, b = 2, c = 3, d = 4;

    std::tuple<int&, int&> ab {a, b};
    std::tuple<int&, int&> cd {c, d};

    ab = cd;
    assert(a == 3 && b == 4);
}

void making_tuple_of_references() {
    int a = 1, b = 2;

    auto ab1 = std::make_tuple(std::ref(a), std::ref(b));
    // ^ always captures values, except that decays reference_wrapper<T>
    // into T&

    auto ab2 = std::tie(a, b);
    // ^ works only on lvalues, and captures lvalue references

    auto ab3 = std::forward_as_tuple(a, b);
    // ^ always captures references

    static_assert(std::is_same_v<decltype(ab1), std::tuple<int&, int&>>);
}

void forward_as_tuple_for_argument_lists() {
    std::string otherString, thirdString;
    int len = 100;

    std::pair<std::string, std::string> p(
        std::piecewise_construct,
        std::forward_as_tuple(otherString, len),
        std::forward_as_tuple(std::move(thirdString))
    );
}

std::tuple<int, int, std::string> getXYZ() {
    return {1, 1, "hello"};
}

void multiple_assignment_with_tie() {
    int x, y;
    std::tie(x, y, std::ignore) = getXYZ();
}
