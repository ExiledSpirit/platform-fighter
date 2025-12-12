#pragma once
#include "core/event_bus.h"
#include "game/game_types.h"
#include "sim/sim_state.h"
#include "entities/ball.h"
#include "rollback/rollback_manager.h"

namespace match {

class FrameController {
public:
  FrameController(core::EventBus& eventBus);

  void step(const game::InputFrame& input);

  const sim::SimState& getCurrentState() const { return currentState; }
  const entities::Ball& getBall() const { return ball; }

private:
  uint32_t frameIndex = 0;

  sim::SimState currentState{};
  entities::Ball ball;
  rollback::RollbackManager rollback;
  core::EventBus& events;

  void applyInputAndSimulate(const game::InputFrame& input);
  void changeMode(game::GameMode newMode);
};

} // namespace match
