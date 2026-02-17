#pragma once
#include "physics/physics_body.h"
#include <cstdint>

namespace sim {

enum class ActionState {
    Normal,
    Dashing
};

enum class Facing {
    Left = -1,
    Right = 1
};

struct CharacterState {
    physics::PhysicsBody body;

    ActionState action = ActionState::Normal;
    Facing facing = Facing::Right;

    // Jump
    bool jumping = false;
    int jumpHoldFrames = 0;
    int jumpBufferFrames = 0;
    int coyoteFrames = 0;

    // Dash
    int dashFrames = 0;
    bool canDash = true;

    // Movement
    float moveSpeed = 6.0f;

    // Landing
    bool grounded = false;
    int landingLagFrames = 0;
};


} // namespace sim
