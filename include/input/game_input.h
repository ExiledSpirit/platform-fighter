#pragma once
#include <cstdint>

namespace input {

enum class GameAction : std::uint8_t {
    Left = 0,
    Right = 1,
    Jump = 2,
    Attack = 3,
};

struct GameInputFrame {
    std::uint32_t bits = 0;

    void set(GameAction a, bool down) {
        const std::uint32_t mask = 1u << (std::uint32_t)a;
        bits = down ? (bits | mask) : (bits & ~mask);
    }

    bool down(GameAction a) const {
        return (bits & (1u << (std::uint32_t)a)) != 0;
    }
};

} // namespace input
