#include <cstddef>

// * Only non-static data declarations in a class definition add
// anything to the size of class objects

struct Salary { };
struct Hourly { };
struct Temp { };

struct Employee { };

class HR {
public:
    void terminator(Salary*, Hourly*, Temp*);
private:
    enum { max = 16383 };
    static size_t num_dispatched;

    Employee* emps[max];
    size_t size;
};

enum { HR_max = 16383 };
extern size_t HR_num_dispatched;

struct HR_TYPE {
    Employee* emps[HR_max];
    size_t size;
};

int main() {
    static_assert(sizeof(HR) == sizeof(HR_TYPE), "error is impossible");
}
