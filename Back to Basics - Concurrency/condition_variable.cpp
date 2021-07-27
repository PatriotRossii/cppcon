#include <mutex>
#include <condition_variable>
#include <vector>

struct Token { };
struct TokenPool {
    std::vector<Token> tokens_;
    std::mutex mtx_;
    std::condition_variable cv_;

    void returnToken(Token t) {
        std::unique_lock lk(mtx_);
        tokens_.push_back(t);
        lk.unlock();
        cv_.notify_one();
    }

    Token getToken() {
        std::unique_lock lk(mtx_);
        while (tokens_.empty()) {
            cv_.wait(lk);
        }
        Token t = std::move(tokens_.back());
        tokens_.pop_back();
        return t;
    }
};

int main() { }
