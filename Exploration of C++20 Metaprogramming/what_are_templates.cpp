template<typename T>
class TemplatedClass {
    // Define members, using T
};

template<typename T>
void TemplatedFunction() {
    // Use T
};

template<typename T>
void TemplatedFunction(T x) {
    // Use T
};

template<typename T> // declaration, not enough
void foo(T t);

template<typename T> // definition
void foo(T t) { }

template void foo<int>(int i); // implicit instantiation
// template void foo(int i);   // implicit instantiation

int main() {
    int i; float j;
    foo<int>(i);        // implicit instantiation by call
    foo(i);             // implicit by call (+ argument deduction)
    void(*ptr)(int) = foo;  // implicit by ptr (+ arg deduction)
}
