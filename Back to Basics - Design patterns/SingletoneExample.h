#pragma once

#include <memory>

class ConfigurationManager {
public:
    template<typename... Args>
    static ConfigurationManager& instance(Args&&... args) {
        static ConfigurationManager instance{std::forward<Args...>(args...)};
        return instance;
    }

    int getWindowWidth();
    int getWindowHeight();

    void setWindowWidth(int w);
    void setWindowHeight(int h);
private:
    ConfigurationManager();
    ~ConfigurationManager();

    int m_windowWidth;
    int m_windowHeight;
};
