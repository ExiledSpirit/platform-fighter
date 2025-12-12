#pragma once
#include "event_bus.h"
#include "game_types.h"
#include "sim_state.h"
#include "ball.h"
#include "rollback_manager.h"

class FrameController {
public:
  FrameController(EventBus& eventBus);

  void step(const InputFrame& input);

  const SimState& getCurrentState() const { return currentState; }
  const Ball& getBall() const { return ball; }

private:
  uint32_t frameIndex = 0;

  SimState currentState{};
  Ball ball;
  RollbackManager rollback;
  EventBus& events;

  void applyInputAndSimulate(const InputFrame& input);
  void changeMode(GameMode newMode);
};
