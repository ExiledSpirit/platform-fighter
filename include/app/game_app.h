#pragma once
#include <optional>
#include <memory>

#include "core/screen_stack.h"
#include "core/event_bus.h"
#include "core/screen_request.h"
#include "game/screen_id.h"

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

  core::EventBus eventBus; // handle listeners
  core::ScreenStack screenStack;

  std::optional<core::ScreenRequest> pendingRequest;

  std::unique_ptr<core::Screen> createScreen(game::ScreenId id);
  void applyPendingRequest();
  void drawFPSCounter();
};

} // namespace app
