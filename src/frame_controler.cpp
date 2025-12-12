#include "frame_controller.h"

FrameController::FrameController(EventBus& eventBus)
  : events(eventBus)
{
  currentState.mode = GameMode::Playing;
  currentState.ball = ball.getState();
}

void FrameController::step(const InputFrame& input)
{
  if (currentState.mode == GameMode::MainMenu)
  {
    if (input.reset) // Handles reset
    {
      changeMode(GameMode::Playing); // Reset
    }
    return;
  }

  if (currentState.mode == GameMode::Paused)
  {
    if (input.pause) // Handles pause
    {
      changeMode(GameMode::Playing); // Unpause
    }
    return;
  }

  if (input.pause)
  {
    changeMode(GameMode::Paused); // Pause
    return;
  }

  applyInputAndSimulate(input);
}
void FrameController::applyInputAndSimulate(const InputFrame& input)
{
  ball.setState(currentState.ball);
  ball.Update(input);
  currentState.ball = ball.getState();
}

void FrameController::changeMode(GameMode newMode)
{
  if (currentState.mode == newMode) return;
  currentState.mode = newMode;

  Event e{ EventType::GameModeChanged };
  events.emit(e);
}
