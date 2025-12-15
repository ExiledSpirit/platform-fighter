#pragma once
#include <cstdint>

namespace sim {

struct CharacterState {
    float x = 200.0f;
    float y = 200.0f;
    float vx = 0.0f;
    float vy = 0.0f;

    bool grounded = false;

    // jump buffering / coyote time (very “fighter” friendly)
    std::uint8_t coyoteFrames = 0;
    std::uint8_t jumpBufferFrames = 0;
};

} // namespace sim
