template<typename T>
class Foo {
public:
    Foo(const T& x): mX{x} { }

    template<typename U>
    Foo<T>& operator=(const U& u) {
        mX = static_cast<T>(u);
        return *this;
    }
private:
    T mX;
};

int main() {
    Foo<int> fi{3};
    fi = 2.5;
}
