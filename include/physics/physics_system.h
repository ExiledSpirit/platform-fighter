#pragma once
#include <algorithm>
#include "world/stage.h"
#include "physics_body.h"
#include "collision.h"

namespace physics {
class PhysicsSystem {
public:
  void step(PhysicsBody& body, const world::Stage& stage) {
    applyGravity(body);
    integrate(body);
    resolveCollisions(body, stage.colliders());
  }

private:
  void resolveCollisions(PhysicsBody& body, const std::vector<world::AABB>& colliders) {
    for (const auto& c : colliders) {
      if (!intersects(
        body.pos.x - body.halfSize.x,
        body.pos.y - body.halfSize.y,
        body.halfSize.x * 2,
        body.halfSize.y * 2,
        c.x, c.y, c.w, c.h
      )) continue;
      
      if (body.vel.y >= 0) {
        body.pos.y = c.y - body.halfSize.y;
        body.vel.y = 0;
        body.grounded = true;
      }
    }
  }
  void integrate(PhysicsBody& body) {
    // Integrate X
    body.pos.x += body.vel.x;

    // Integrate Y
    body.pos.y += body.vel.y;
    body.grounded = false;
  }

  void applyGravity(PhysicsBody& body) {
    constexpr float gravity = 0.45f;
    constexpr float maxFall = 12.0f;

    // Apply gravity
    body.vel.y += gravity;
    body.vel.y = std::min(body.vel.y, maxFall);
  }
};
} // module physics
