#pragma once
#include "screens/main_menu_screen.h"
#include "input/input_system.h"
#include "input/input_router.h"

namespace app
{

class GameApp
{
public:
  GameApp();

  void update();
  void render();
private:
  input::InputSystem inputSystem;
  input::InputRouter inputRouter;

  screens::MainMenuScreen mainMenu;
};

} // namespace app
