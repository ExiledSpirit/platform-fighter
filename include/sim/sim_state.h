#pragma once
#include "sim/ball_state.h"
#include "game/game_types.h"

namespace sim {

struct SimState {
  game::GameMode mode;
  sim::BallState ball;
};

} //namespace sim
