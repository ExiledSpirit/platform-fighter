#include "game_app.h"
#include "config.h";

GameApp::GameApp()
  : frameController(eventBus)
{
  // starts in menu
  mode = GameMode::MainMenu;
}

void GameApp::update()
{
  // stores current frame inputs
  InputFrame input = this->inputSystem.sampleCurrentFrame();

  // handles each game mode individually
  switch(mode)
  {
    case GameMode::MainMenu:
      updateMenu(input);
      break;
    case GameMode::Playing:
      frameController.step(input);
      break;
    case GameMode::Paused:
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
    case GameMode::MainMenu:
      renderMenu();
      break;
    case GameMode::Playing:
      frameController.getBall().Draw();
      break;
    case GameMode::Paused:
      frameController.getBall().Draw();
      break;
  }

  EndDrawing();
}

void GameApp::updateMenu(const InputFrame& input)
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
  mode = GameMode::Playing;
  // Reset frame controller and simulation state, maybe other stuffs
}

void GameApp::endMatch()
{
  mode = GameMode::MainMenu;
}
