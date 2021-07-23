#include <optional>

#include <string>

// 1. In a return type, it represents "no answer"

std::optional<std::string> oGetEnv(const char* name) {
    if (/* name is present */ true) {
        return std::string(/* variable's value */ "example");
    } else {
        return std::nullopt;
    }
}

// 2. In a variable, it represents "no setting"

class ConfigManager {
/*
    bool hasIncludePath_ = false;
    std::string includePath_;
*/
    std::optional<std::string> includePath_;
public:
/*
    std::string getIncludePath() const {
        return hasIncludePath_ ? includePath_ : "/usr/include";
    }
*/
    std::string getIncludePath() const {
        return includePath_.value_or("/usr/include");
    }
};

// 3. Or, it represents "not initialized yet" for types with no
// default constructor. This gives us the benefits of dynamic
// lifetime, without any heap usage

struct ComplicatedObject {
    ComplicatedObject(int a, int b) { }
};
class ComplicatedManager {
/*
    std::unique_ptr<ComplicatedObject> obj_ = nullptr
*/
    std::optional<ComplicatedObject> obj_ = std::nullopt;
public:
/*
    void setComplicated(int a, int b) {
        obj_ = std::make_unique<ComplicatedObject>(a, b);
    }
*/
    void setComplicated(int a, int b) {
        obj_.emplace(a, b);
    }
};
