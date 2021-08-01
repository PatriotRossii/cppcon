#include <variant>

#include <iostream>
#include <string>

#include <memory>
#include <cassert>

void get_visitation() {
    std::variant<int, double, std::string> v;

    if(v.index() == 0) {
        std::cout << std::get<int>(v) << '\n';
    } else if (v.index() == 1) {
        std::cout << std::get<double>(v) << '\n';
    } else if (v.index() == 2) {
        std::cout << std::get<std::string>(v) << '\n';
    }
}

void get_if_visitation() {
    std::variant<int, double, std::string> v;

    if(int *pi = std::get_if<int>(&v)) {
        std::cout << *pi << '\n';
    } else if (double *pd = std::get_if<double>(&v)) {
        std::cout << *pd << '\n';
    } else if (auto *ps = std::get_if<std::string>(&v)) {
        std::cout << *ps << '\n';
    }
}

void visit_visitation() {
    std::variant<int, double, std::string> v;

    auto printme = [](const auto& x) {
        std::cout << x << '\n';
    };

    std::visit(printme, v);
}

void valueless() {
    std::variant<std::unique_ptr<int>, std::string> v;

    v = std::make_unique<int>(127);
    std::string x = "long enough to require heap allocation";

    try {
        v.emplace<1>(x);
    } catch (const std::bad_alloc&) {
        assert(v.valueless_by_exception());
        assert(v.index() == size_t(-1));
    }
}

int main() { }
