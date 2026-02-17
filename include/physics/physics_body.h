#pragma once
#include "math/vec3.h"

namespace physics {

struct PhysicsBody {
    math::Vec3 pos;
    math::Vec3 vel;
    math::Vec3 halfSize;

    bool grounded = false;
    bool prevGrounded = false;
};

} // namespace physics
