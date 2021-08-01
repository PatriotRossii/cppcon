#include <mutex>

#include <vector>
#include <memory>

class TokenPool {
    mutable std::mutex mtx_;
    std::vector<Token> tokens_;

    Token getToken() {
        std::lock_guard<std::mutex> lk(mtx_);
        if(tokens_.empty())
            tokens_.push_back(Token::create());
        Token t = std::move(tokens_.back());
        tokens_.pop_back();
        return t;
    }

    size_t numTokensAvailable() const {
        std::lock_guard lk(mtx_);
        return tokens_.size();
    }
};
