#include <cstring>

class BadFlatland {
public:
    auto operator <=>(const BadFlatland& rhs) const {
        return memcmp(this, &rhs, sizeof(BadFlatland));
    }
    int x;
    int y;
private:
    int z;
};

class EitherBadFlatland {
public:
    auto operator <=>(const EitherBadFlatland& rhs) const {
        return memcmp(this, &rhs, sizeof(EitherBadFlatland));
    }
    auto x() const { return x_; }
    auto y() const { return y_; }
private:
    int x_;
    int y_;
    int z_;
};

int main() {}
