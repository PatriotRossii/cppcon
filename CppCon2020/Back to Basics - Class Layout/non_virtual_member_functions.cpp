struct Salary { };
struct Hourly { };
struct Temp { };

class HR {
public:
    void terminate(Salary*);
    void terminate(Hourly*);
    void terminate(Temp*);

    void terminator(Salary* s, Hourly* h, Temp* t) {
        terminate(s);
        terminate(h);
        terminate(t);
    }
};

// The calling sequence for an n-argument non-virtual member function
// may be the same as that for an (n+1)-argument free function:

void terminate(HR*, Salary*) {}
void terminate(HR*, Hourly*) {} 
void terminate(HR*, Temp*) {}

void terminator(HR* hr, Salary* s, Hourly* h, Temp* t) {
    terminate(hr, s);
    terminate(hr, h);
    terminate(hr, t);
}


int main() { }
