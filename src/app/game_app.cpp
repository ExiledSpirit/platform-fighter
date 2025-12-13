#include "app/game_app.h"

#include "input/context.h"
#include "screens/main_menu_screen.h"
#include "screens/game_screen.h"
#include <stdio.h>
#include "raylib.h"

namespace app {

GameApp::GameApp()
  : inputRouter(inputSystem)
{
  inputRouter.setContext(input::Context::UI);

  eventBus.subscribeScreenRequests([this](const core::ScreenRequest& req) {
    // Defer: apply after update
    pendingRequest = req;
  });

  // Starts in Main Menu
  screenStack.push(createScreen(game::ScreenId::MainMenu));
}

std::unique_ptr<core::Screen> GameApp::createScreen(game::ScreenId id) {
  switch (id) {
    case game::ScreenId::MainMenu:
      return std::make_unique<screens::MainMenuScreen>(eventBus);
    case game::ScreenId::Game:
      return std::make_unique<screens::GameScreen>();
    default:
      return nullptr;
  }
}

void GameApp::applyPendingRequest() {
  // check if there's a pending request
  if (!pendingRequest.has_value()) return;

  // stores a ptr to the request
  const auto req = *pendingRequest;

  switch (req.type) {
    case core::ScreenRequestType::Push:
      screenStack.push(createScreen(req.target));
      break;
    case core::ScreenRequestType::Pop:
      screenStack.pop();
      break;
    case core::ScreenRequestType::Replace:
      screenStack.replace(createScreen(req.target));
      break;
  }
}

void GameApp::update() {
  auto* top = screenStack.top();
  if (!top) return;

  inputRouter.routeTo(*top);

  screenStack.updateTop();

  applyPendingRequest();
}

void GameApp::render() {
  screenStack.renderTop();
  drawFPSCounter();
}

void GameApp::drawFPSCounter() {
  const int fps = GetFPS();
  const float ms = GetFrameTime() * 1000.0f;
  
  char buf[64];
  snprintf(buf, sizeof(buf), "FPS: %d (%.2f ms)", fps, ms);

  DrawText(buf, 10, 10, 18, GREEN);
}

} // namespace app