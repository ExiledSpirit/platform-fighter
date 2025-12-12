#pragma once
#include "game/game_types.h"
#include "core/event_bus.h"
#include "match/frame_controller.h"
#include "input/input_system.h"

namespace app
{

class GameApp
{
public:
  GameApp();

  void update();
  void render();
private:
  game::GameMode mode = game::GameMode::MainMenu; // starts on menu

  core::EventBus eventBus;
  input::InputSystem inputSystem;

  match::FrameController frameController;

  void updateMenu(const game::InputFrame& input);
  void renderMenu();
  void startMatch();
  void endMatch();
};

} // namespace app
