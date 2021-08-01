// The implementation compares the data members in the lexical
// order x, y, and z even if z is physically placed at offset 0

class Flatland {
public:
    auto operator <=>(const Flatland&) const = default;
    int x;
    int y;
private:
    int z;
};

int main() {}
