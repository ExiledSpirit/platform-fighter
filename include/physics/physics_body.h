#pragma once
#include "math/vec2.h"

namespace physics {

struct PhysicsBody {
    math::Vec2 pos;
    math::Vec2 vel;
    math::Vec2 halfSize;

    bool grounded = false;
};

} // namespace physics
