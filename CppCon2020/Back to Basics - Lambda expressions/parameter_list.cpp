#include <string>

int main() {
    // C++11:
    //  * declarations for the arguments passed to the closure
    //  * default parameters were not permitted

    // C++14:
    //  * parameters can have a data type of auto
    //  * default parameters are supported

    auto myLamb = [](const std::string& data,
                     unsigned int max = 20) {
        return data.substr(0, max);
    };
}
