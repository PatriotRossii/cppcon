#include <string>

struct Ginger {
    void operator()(std::string str) {}
};


int main() {
    Ginger widget;
    widget.operator()("hello"); // equals to next
    widget("hello");            // equals to previous
}
