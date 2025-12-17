#include "match/frame_controller.h"
#include <algorithm>

namespace match {
FrameController::FrameController(const world::Stage& s)
    : stage(s)
{
    st.players.resize(1);
    auto& p = st.players[0];

    p.body.pos = { 200, 200 };
    p.body.halfSize = { 16, 16 };
}

void FrameController::step(const input::GameInputFrame& in) {
    stepCharacter(st.players[0], in);
    physics.step(st.players[0].body, stage);
    st.frame++;
}

void FrameController::stepCharacter(sim::CharacterState& c, const input::GameInputFrame& in) {
    float dir = 0.0f;
    // Horizontal movement
    if (in.down(input::GameAction::Left))  dir -= 1.0f;
    if (in.down(input::GameAction::Right)) dir += 1.0f;

    constexpr float airAccel    = 0.25;
    constexpr float groundAccel = 0.6f;
    constexpr float maxSpeed    = 6.0f;
    constexpr float groundFriction    = 0.85f;

    const bool isNotMoving  = dir == 0.0f;
    const float accel = c.body.grounded ? groundAccel : airAccel;

    // Accelerate
    c.body.vel.x += dir * accel;

    // Clamp speed
    c.body.vel.x = std::clamp(c.body.vel.x, -maxSpeed, maxSpeed);

    // Friction (only on ground)
    if (isNotMoving && c.body.grounded) {
        c.body.vel.x *= groundFriction;
        if (std::abs(c.body.vel.x) < 0.05f)
            c.body.vel.x = 0.0f;
    }

    // Update coyote and grounded check
    if (c.body.grounded)
        c.coyoteFrames = 6;
    else if (c.coyoteFrames > 0)
        c.coyoteFrames--;

    // Update jump buffer
    if (in.down(input::GameAction::Jump))
        c.jumpBufferFrames = 6;
    else if (c.jumpBufferFrames > 0)
        c.jumpBufferFrames--;
    
    // Apply jump
    if (c.jumpBufferFrames > 0 && c.coyoteFrames > 0) {
        c.body.vel.y = c.jumpImpulse;
        c.jumpBufferFrames = 0;
        c.coyoteFrames = 0;
    }
}

}