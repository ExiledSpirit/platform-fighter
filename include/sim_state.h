#pragma once
#include "ball_state.h"
#include "game_types.h"

struct SimState {
  GameMode mode;
  BallState ball;
};
