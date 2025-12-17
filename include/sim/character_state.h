#pragma once
#include "physics/physics_body.h"
#include <cstdint>

namespace sim {

struct CharacterState {
    physics::PhysicsBody body;

    // Jump buffer/ coyote state
    int jumpBufferFrames = 0;
    int coyoteFrames = 0;

    float moveSpeed = 6.0f;
    float jumpImpulse = -10.0f;
};

} // namespace sim
