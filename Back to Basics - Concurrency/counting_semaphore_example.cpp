#include <semaphore>

using Sem = std::counting_semaphore<256>;
struct SemReleaser {
    bool operator()(Sem* s) const { s->release(); }
};
class AnonymousTokenPool {
    Sem sem_{100};

    using Token = std::unique_ptr<Sem, SemReleaser>;

    Token borrowToken() {
        sem_.acquire(); // may block
        return Token(&sem_);
    }
};

int main() { }
