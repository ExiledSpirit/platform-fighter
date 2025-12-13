#include "app/game_app.h"
#include "game/config.h"

namespace app {

GameApp::GameApp()
  : inputRouter(inputSystem)
{
  inputRouter.setContext(input::Context::UI);
  mainMenu.onEnter();
}

void GameApp::update()
{
  inputRouter.routeTo(mainMenu);
  mainMenu.update();
}

void GameApp::render()
{
  mainMenu.render();
}

} // namespace app