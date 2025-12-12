#pragma once
#include "game_types.h"
#include "frame_controller.h"
#include "input_system.h"

class GameApp
{
public:
  GameApp();

  void update();
  void render();
private:
  GameMode mode = GameMode::MainMenu; // starts on menu

  EventBus eventBus;
  InputSystem inputSystem;

  FrameController frameController;

  void updateMenu(const InputFrame& input);
  void renderMenu();
  void startMatch();
  void endMatch();
};
