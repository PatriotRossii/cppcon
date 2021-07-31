#include <iostream>

template<class T>
concept contains_data = requires(T t) {
    t.data;
};

template<typename T>
struct DataType {
    DataType(T t): data(t) {
        std::cout << "DataType created" << '\n';
    };
    T data;
};

class wrapper {
public:
    template<typename T>
    wrapper(T t) = delete;

    template<contains_data T>
    wrapper(T t) {
        std::cout << "wrapper from any contains_data, with data: " << t.data << '\n';
    };
};

int main() {
    wrapper Wrap1{DataType{3}};
//  wrapper Wrap2{3};
}
