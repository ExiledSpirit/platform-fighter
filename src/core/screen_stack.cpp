#include "core/screen_stack.h"

namespace core {

void ScreenStack::push(std::unique_ptr<Screen> screen) {
  if (!screen) return;

  stack.push_back(std::move(screen));
  stack.back()->onEnter();
}

void ScreenStack::pop() {
  if (stack.empty()) return;

  stack.back()->onExit();
  stack.pop_back();
}

void ScreenStack::replace(std::unique_ptr<Screen> screen) {
  if (!screen) return;

  if (!stack.empty()) {
    stack.back()->onExit();
    stack.pop_back();
  }

  stack.push_back(std::move(screen));
  stack.back()->onEnter();
}

void ScreenStack::updateTop() {
  if (auto* s = top()) {
    s->update();
  }
}

void ScreenStack::renderTop() {
  if (auto* s = top()) {
    s->render();
  }
}

} // namespace core