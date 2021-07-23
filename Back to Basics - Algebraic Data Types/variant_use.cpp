#include <variant>

// 1. When you need a "sum type"

struct Simple { int fromx, fromy, tox, toy; };
struct Capture { int fromx, fromy, tox, toy; bool enpassant; };
struct Castle { bool kingside; };

class ChessMove {
    std::variant<Simple, Capture, Castle> details_;

    bool isSimple() const { return details_.index() == 0; }
    bool isCapturing() const { return details_.index() == 1; }
    bool isCastling() const { return details_.index() == 2; }
};
