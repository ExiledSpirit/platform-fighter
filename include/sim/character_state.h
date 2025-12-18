#pragma once
#include "physics/physics_body.h"
#include <cstdint>

namespace sim {

struct CharacterState {
    physics::PhysicsBody body;

    // Movement system
    float moveSpeed = 6.0f;
    int facing = -1; // -1 = left / 1 = right

    // Jump system
    int jumpBufferFrames = 0;
    int coyoteFrames = 0;
    int jumpHoldFrames = 0;

    bool grounded = false;
    bool jumping = false;
};

} // namespace sim
