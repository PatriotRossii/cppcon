#include <mutex>

#include <vector>
#include <memory>

class TokenPool {
    std::mutex mtx_;
    std::vector<Token> tokens_;

    Token getToken() {
        mtx_.lock();
        if(tokens_.empty())
            tokens_.push_back(Token::create()); // If throws exception
        Token t = std::move(tokens_.back()); // mutex will never be
        tokens_.pop_back();                 // unlocked
        mtx_.unlock();
        return t;
    }

    size_t numTokensAvailable() const {
        return tokens_.size(); // Data race
    }
}
