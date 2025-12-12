#pragma once
#include "raylib.h"
#include "sim/ball_state.h"
#include "game/game_types.h" // For InputFrames Struct

namespace entities
{

class Ball {
public:
  Ball();

  void Update(const game::InputFrame& input);
  void Draw() const;
  sim::BallState getState() const;
  void setState(const sim::BallState& s);
private:
  Vector2 position;
  Vector2 velocity;
};

} // namespace entities