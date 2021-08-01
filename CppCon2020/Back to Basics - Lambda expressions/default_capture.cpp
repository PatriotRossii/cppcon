int main() {
    int x = 0, m_data = 0;

    // default capture by value
    // captures all variables used in the body of the lambda expr
    auto myLamb = [=]() { return x + m_data; };

    // default capture by reference
    // captures all variables used in the body of the lambda expr
    auto anotherLamb = [&]() { return x + m_data; };
}
