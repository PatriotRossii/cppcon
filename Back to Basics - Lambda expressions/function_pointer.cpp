#include <cstdlib>

void (*myProcess)(int);

int main() {
    myProcess = std::exit;
    myProcess(42);
}
