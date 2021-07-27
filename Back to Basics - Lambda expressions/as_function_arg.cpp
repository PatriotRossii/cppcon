#include <functional>

template<typename F>
void doThingA(F arg) { } // example A

void doThingB(std::function<int (double)> arg) { } // example B

int main() {
    auto myLamb = [](double data) {
        return int(data);
    };

    doThingA(myLamb);
    doThingB(myLamb);
}
