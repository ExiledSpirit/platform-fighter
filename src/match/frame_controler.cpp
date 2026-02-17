#include "match/frame_controller.h"
#include <algorithm>

constexpr int JUMP_BUFFER = 6;
constexpr int COYOTE_FRAMES = 6;
constexpr int SHORT_HOP_FRAMES = 8;

constexpr float JUMP_VEL_SHORT = -7.0f;
constexpr float JUMP_VEL_FULL  = -9.0f;

constexpr int DASH_FRAMES = 12;
constexpr float DASH_SPEED = 9.5f;

constexpr float FAST_FALL_SPEED = 12.0f;
constexpr int DASH_ENDLAG = 8;

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
    auto& player = st.players[0]; // only p1 for now.

    updateBuffers(player, in);
    resolveActions(player, in);
    applyMovement(player, in);
    physics.step(st.players[0].body, stage);
    postPhysics(player);

    st.frame++;
}

void FrameController::updateBuffers(
        sim::CharacterState& c,
        const input::GameInputFrame& in
    )
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
}

void FrameController::resolveActions(sim::CharacterState& c,
                                     const input::GameInputFrame& in)
{
    // --- DASH START
    if (c.action == sim::ActionState::Normal &&
        c.canDash &&
        in.down(input::GameAction::Dash))
    {
        c.action = sim::ActionState::Dashing;
        c.dashFrames = DASH_FRAMES;
        c.canDash = false;

        float dir = 0.0f;
        if (in.down(input::GameAction::Left)) {
            dir = -1.0f;
            c.facing = sim::Facing::Left;
        }
        if (in.down(input::GameAction::Right)) {
            dir = 1.0f;
            c.facing = sim::Facing::Right;
        }
        if (dir == 0.0f) dir = (int)c.facing; // facing later

        c.body.vel.x = dir * DASH_SPEED;
        c.body.vel.y = 0.0f;
        return;
    }

    // --- JUMP START
    if (c.jumpBufferFrames > 0 && c.coyoteFrames > 0) {
        if (c.action == sim::ActionState::Dashing) {
            c.action = sim::ActionState::Normal;
        }

        c.jumping = true;
        c.jumpHoldFrames = 0;
        c.jumpBufferFrames = 0;
        c.coyoteFrames = 0;

        c.body.vel.y = JUMP_VEL_SHORT;
        c.body.grounded = false;
    }
}

void FrameController::applyMovement(sim::CharacterState& c,
                                    const input::GameInputFrame& in)
{
    // --- LANDING LAG
    if (c.landingLagFrames > 0) {
        c.landingLagFrames--;
        return; // blocks movement & actions, NOT physics
    }

    // --- DASH CONTINUE
    if (c.action == sim::ActionState::Dashing) {
        c.dashFrames--;
        if (c.dashFrames <= 0) {
            c.action = sim::ActionState::Normal;
            c.landingLagFrames = DASH_ENDLAG;
        }
        return; // IMPORTANT skips movement logic so friction doesnt apply
    }

    // --- JUMP HOLD
    if (c.jumping && c.body.vel.y < 0 && in.down(input::GameAction::Jump)) {
        c.jumpHoldFrames++;
    }

    // --- RELEASE JUMP
    if (c.jumping &&
        (!in.down(input::GameAction::Jump) ||
         c.jumpHoldFrames > SHORT_HOP_FRAMES))
    {
        if (c.body.vel.y < JUMP_VEL_FULL) {
            c.body.vel.y = JUMP_VEL_FULL;
        }
        c.jumping = false;
    }

    // --- HORIZONTAL MOVEMENT
    float dir = 0.0f;
    if (in.down(input::GameAction::Left))  dir -= 1.0f;
    if (in.down(input::GameAction::Right)) dir += 1.0f;

    // FACING DIRECTION
    if (dir != 0.0f)  c.facing = (dir < 0) ? sim::Facing::Left : sim::Facing::Right;

    constexpr float airAccel = 0.6f;
    constexpr float groundAccel = 0.6f;
    constexpr float maxSpeed = 6.0f;
    constexpr float friction = 0.85f;

    const float accel = c.body.grounded ? groundAccel : airAccel;

    c.body.vel.x += dir * accel;
    c.body.vel.x = std::clamp(c.body.vel.x, -maxSpeed, maxSpeed);

    if (dir == 0.0f && c.body.grounded) {
        c.body.vel.x *= friction;
        if (std::abs(c.body.vel.x) < 0.1f)
            c.body.vel.x = 0.0f;
    }

    // --- FAST FALL
    if (!c.body.grounded &&
        c.body.vel.y > 0 &&
        in.down(input::GameAction::Down)) {
        c.body.vel.y = FAST_FALL_SPEED;
    }
}

void FrameController::postPhysics(sim::CharacterState& c)
{
    if (c.body.grounded) {
        c.jumping = false;
        c.canDash = true;

        if (c.body.prevGrounded == false) {
            c.landingLagFrames = 6;
        }
    }
    c.body.prevGrounded = c.body.grounded;
}
}