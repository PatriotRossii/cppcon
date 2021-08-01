template<typename T>
class Foo {
public:
    void func() {}
};

template<typename T>
class Bar: public Foo<T> {
public:
    void barFunc() {
//      func();
        this->func();
        Foo<T>::func();
    }
};

int main() {
    Bar<int> b{};
    b.barFunc();
}
