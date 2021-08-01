#include <mutex>

#include <optional>
#include <string>

struct NetworkConnection {
    NetworkConnection(const std::string&) { }
};

class Logger {
    std::once_flag once_;
    std::optional<NetworkConnection> conn_;

    static std::string defaultHost;

    NetworkConnection& getConn() {
        std::call_once(once_, [this]() {
            conn_ = NetworkConnection(defaultHost);
        });
        return *conn_;
    }
}; // The first access to conn_ is protected by a once_flag

std::string Logger::defaultHost{"127.0.0.1"};

int main() { }
