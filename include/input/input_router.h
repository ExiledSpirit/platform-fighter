#pragma once
#include "input/context.h"
#include "input/ui_action.h"
#include "input/input_system.h"
#include "input/game_input.h"

namespace core { class Screen; }

namespace input {

class InputRouter {
public:
  explicit InputRouter(InputSystem& inputSystem);

  void setContext(Context ctx);
  Context getContext() const;

  void routeTo(core::Screen& screen);
  input::GameInputFrame sampleGameplay() const;
private:
  InputSystem& input;
  Context context = Context::UI;

  void routeUI(core::Screen& screen);
};

}