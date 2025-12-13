#pragma once
#include "input/ui_action.h"

namespace core {

class Screen {
public:
  virtual ~Screen() = default;

  virtual void onEnter() {}
  virtual void onExit() {}

  virtual void update() = 0;
  virtual void render() = 0;

  virtual void handleUI(const input::UIActionEvent& e) = 0;
};

} // namespace core
