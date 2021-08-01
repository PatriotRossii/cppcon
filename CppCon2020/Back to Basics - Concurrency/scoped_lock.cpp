#include <mutex>

#include <vector>
#include <memory>

class Token {
public:
    static Token create() {
        return Token{};
    }
};

class TokenPool {
    mutable std::mutex mtx_;
    std::vector<Token> tokens_;

    Token getToken() {
        std::scoped_lock lk(mtx_);
        if(tokens_.empty())
            tokens_.push_back(Token::create());
        Token t = std::move(tokens_.back());
        tokens_.pop_back();
        return t;
    }

    size_t numTokensAvailable() const {
        std::scoped_lock lk(mtx_);
        return tokens_.size();
    }

    void mergeTokensFrom(TokenPool& rhs) {
        std::scoped_lock lk(mtx_, rhs.mtx_);
        tokens_.insert(tokens_.begin(),
                       rhs.tokens_.begin(),
                       rhs.tokens_.end());
        rhs.tokens_.clear();
    }
};

int main() {}
