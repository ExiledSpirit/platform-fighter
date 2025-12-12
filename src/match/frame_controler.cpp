#include "match/frame_controller.h"

namespace match {

FrameController::FrameController(core::EventBus& eventBus)
  : events(eventBus)
{
  currentState.mode = game::GameMode::Playing;
  currentState.ball = ball.getState();
}

void FrameController::step(const game::InputFrame& input)
{
  if (currentState.mode == game::GameMode::MainMenu)
  {
    if (input.reset) // Handles reset
    {
      changeMode(game::GameMode::Playing); // Reset
    }
    return;
  }

  if (currentState.mode == game::GameMode::Paused)
  {
    if (input.pause) // Handles pause
    {
      changeMode(game::GameMode::Playing); // Unpause
    }
    return;
  }

  if (input.pause)
  {
    changeMode(game::GameMode::Paused); // Pause
    return;
  }

  applyInputAndSimulate(input);
}
void FrameController::applyInputAndSimulate(const game::InputFrame& input)
{
  ball.setState(currentState.ball);
  ball.Update(input);
  currentState.ball = ball.getState();
}

void FrameController::changeMode(game::GameMode newMode)
{
  if (currentState.mode == newMode) return;
  currentState.mode = newMode;

  core::Event e{ core::EventType::GameModeChanged };
  events.emit(e);
}

} //namespace match
