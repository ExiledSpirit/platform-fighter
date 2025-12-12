#include "app/game_app.h"
#include "game/config.h"

namespace app {

GameApp::GameApp()
  : frameController(eventBus)
{
  // starts in menu
  mode = game::GameMode::MainMenu;
}

void GameApp::update()
{
  // stores current frame inputs
  game::InputFrame input = this->inputSystem.sampleCurrentFrame();

  // handles each game mode individually
  switch(mode)
  {
    case game::GameMode::MainMenu:
      updateMenu(input);
      break;
    case game::GameMode::Playing:
      frameController.step(input);
      break;
    case game::GameMode::Paused:
      updateMenu(input);
      break;
  }
}

void GameApp::render()
{
  BeginDrawing();
  ClearBackground(GameConfig::CLEAR_COLOR);

  switch (mode)
  {
    case game::GameMode::MainMenu:
      renderMenu();
      break;
    case game::GameMode::Playing:
      frameController.getBall().Draw();
      break;
    case game::GameMode::Paused:
      frameController.getBall().Draw();
      break;
  }

  EndDrawing();
}

void GameApp::updateMenu(const game::InputFrame& input)
{
  if (input.reset)
  {
    startMatch();
  }
}

void GameApp::renderMenu()
{
  DrawText("MAIN MENU!!!", 100, 100, 20, RAYWHITE);
}

void GameApp::startMatch()
{
  mode = game::GameMode::Playing;
  // Reset frame controller and simulation state, maybe other stuffs
}

void GameApp::endMatch()
{
  mode = game::GameMode::MainMenu;
}

} // namespace app