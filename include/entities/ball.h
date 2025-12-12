#pragma once
#include "raylib.h"
#include "ball_state.h"
#include "game_types.h" // For InputFrames Struct

class Ball {
public:
  Ball();

  void Update(const InputFrame& input);
  void Draw() const;
  BallState getState() const;
  void setState(const BallState& s);
private:
  Vector2 position;
  Vector2 velocity;
};
