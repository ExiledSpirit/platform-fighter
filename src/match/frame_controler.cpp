#include "match/frame_controller.h"
#include <algorithm>

constexpr int JUMP_BUFFER = 6;
constexpr int COYOTE_FRAMES = 6;

constexpr int SHORT_HOP_FRAMES = 8; // if holding between 1~7 frames perform short hop

constexpr float JUMP_VEL_SHORT = -7.0f;
constexpr float JUMP_VEL_FULL = -9.0f;

constexpr float FAST_FALL_SPEED = 12.0f;

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

void FrameController::stepCharacter(sim::CharacterState& c,
                                    const input::GameInputFrame& in)
{
    // --- COYOTE
    if (c.body.grounded) c.coyoteFrames = COYOTE_FRAMES;
    else if (c.coyoteFrames > 0) c.coyoteFrames--;

    // --- JUMP BUFFER
    if (in.down(input::GameAction::Jump)) {
        c.jumpBufferFrames = JUMP_BUFFER;
    } else if (c.jumpBufferFrames > 0) {
        c.jumpBufferFrames--;
    }

    // --- JUMP HANDLING
    if (c.jumpBufferFrames > 0 && c.coyoteFrames > 0) {
        c.grounded = false;
        c.jumping = true;
        c.jumpHoldFrames = 0;
        c.jumpBufferFrames = 0;
        c.coyoteFrames = 0;

        // Initial velocity
        c.body.vel.y = JUMP_VEL_SHORT;
        c.body.grounded = false;
    }

    // --- JUMP HOLD
    if (c.jumping && c.body.vel.y < 0 && in.down(input::GameAction::Jump)) {
        c.jumpHoldFrames++;
    }

    // --- RELEASE JUMP (short/med/full hop handling)
    if (c.jumping && (!in.down(input::GameAction::Jump) || c.jumpHoldFrames > SHORT_HOP_FRAMES)) {
        float vel;

        if (c.jumpHoldFrames <= SHORT_HOP_FRAMES)
            vel = JUMP_VEL_SHORT;
        else
            vel = JUMP_VEL_FULL;

        c.body.vel.y = vel;
        c.jumping = false;
    }

    // --- HORIZONTAL MOVEMENT
    float dir = 0.0f;

    if (in.down(input::GameAction::Left))  dir -= 1.0f;
    if (in.down(input::GameAction::Right)) dir += 1.0f;
    const bool changedDirection = !((dir >= 0 && c.body.vel.x >= 0) || (dir <= 0 && c.body.vel.x <= 0));

    constexpr float airAccel    = 0.6;
    constexpr float groundAccel = 0.6f;
    constexpr float maxSpeed    = 6.0f;
    constexpr float groundFriction    = 0.85f;

    const bool isNotMoving = (dir == 0.0f);
    const bool isFalling = c.body.vel.y >= 0;
    const bool isGrounded = c.body.grounded;
    const float accel = c.body.grounded ? groundAccel : airAccel;

    // Reset vel if change directions
    if (changedDirection) c.body.vel.x = 0;

    // Accelerate
    c.body.vel.x += dir * accel;

    // Clamp speed
    c.body.vel.x = std::clamp(c.body.vel.x, -maxSpeed, maxSpeed);

    // Friction (only on ground)
    if (isNotMoving && (isGrounded || isFalling)) {
        c.body.vel.x *= groundFriction;
        if (std::abs(c.body.vel.x) < 0.10f)
            c.body.vel.x = 0.0f;
    }

    // handle fast fall
    if (isFalling && in.down(input::GameAction::Down)) {
        c.body.vel.y = FAST_FALL_SPEED;
    }
}

}