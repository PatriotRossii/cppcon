#include <mutex>

#include <optional>
#include <string>

struct NetworkConnection {
    NetworkConnection(const std::string&) { }
};

class Logger {
    std::mutex mtx_;
    std::optional<NetworkConnection> conn_;

    static std::string defaultHost;

    NetworkConnection& getConn() {
        std::lock_guard lk(mtx_);
        if(!conn_.has_value()) {
            conn_ = NetworkConnection(defaultHost);
        }
        return *conn_;
    }
}; // Safe, but slower than it could be

std::string Logger::defaultHost{"127.0.0.1"};

int main() { }
