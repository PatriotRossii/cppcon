#include <cstdio>

template<typename T>
T min(const T& a, const T& b) {
    return (a < b) ? a : b;
}

int main() {
    const int a = 2;
    const int b = 1;

    printf("%d\n", min(a, b));
}
