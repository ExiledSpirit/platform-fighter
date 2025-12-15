#include "match/frame_controller.h"
#include <algorithm>

namespace match {

FrameController::FrameController() {
    st.frame = 0;
    st.p1.x = 200.0f;
    st.p1.y = 200.0f;
}

void FrameController::step(const input::GameInputFrame& p1Input) {
    stepCharacter(st.p1, p1Input);
    st.frame++;
}

void FrameController::stepCharacter(sim::CharacterState& c, const input::GameInputFrame& in) {
    // Tunables (frame-based)
    constexpr float accel = 0.7f;
    constexpr float airAccel = 0.45f;
    constexpr float maxVx = 6.0f;
    constexpr float friction = 0.90f;
    constexpr float gravity = 0.45f;
    constexpr float maxFall = 12.0f;
    constexpr float jumpVel = -10.5f;

    // Update jump buffer / coyote
    if (c.grounded) c.coyoteFrames = 6;
    else if (c.coyoteFrames > 0) c.coyoteFrames--;

    if (in.down(input::GameAction::Jump)) {
        c.jumpBufferFrames = 6;
    } else if (c.jumpBufferFrames > 0) {
        c.jumpBufferFrames--;
    }

    // Horizontal input
    float ax = 0.0f;
    if (in.down(input::GameAction::Left))  ax -= 1.0f;
    if (in.down(input::GameAction::Right)) ax += 1.0f;

    const float useAccel = c.grounded ? accel : airAccel;
    c.vx += ax * useAccel;

    // Clamp speed
    c.vx = std::clamp(c.vx, -maxVx, maxVx);

    // Friction if grounded and no input
    if (c.grounded && ax == 0.0f) {
        c.vx *= friction;
        if (c.vx > -0.05f && c.vx < 0.05f) c.vx = 0.0f;
    }

    // Jump (buffered + coyote)
    if (c.jumpBufferFrames > 0 && c.coyoteFrames > 0) {
        c.vy = jumpVel;
        c.grounded = false;
        c.coyoteFrames = 0;
        c.jumpBufferFrames = 0;
    }

    // Gravity
    c.vy += gravity;
    if (c.vy > maxFall) c.vy = maxFall;

    // Integrate
    c.x += c.vx;
    c.y += c.vy;

    // Walls
    if (c.x < LeftWall)  { c.x = LeftWall;  c.vx = 0; }
    if (c.x > RightWall) { c.x = RightWall; c.vx = 0; }

    // Ground collision
    if (c.y >= GroundY) {
        c.y = GroundY;
        c.vy = 0.0f;
        c.grounded = true;
    } else {
        c.grounded = false;
    }
}

} // namespace match
