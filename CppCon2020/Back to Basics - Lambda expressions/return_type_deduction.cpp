int main() {
    // C++11:
    //  * if you have more than one return statement you must
    //    specify the return type

    // C++14:
    //  * if there is more than one return statement they must
    //    deduce to the exact same data type or it must be specified

    auto myLamb = [](bool sloppy) -> double {
        if (sloppy) { return 3; }
        return 3.14;
    };
}
