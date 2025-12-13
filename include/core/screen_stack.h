#pragma once
#include <memory>
#include <vector>

#include "core/screen.h"

namespace core {

class ScreenStack {
public:
  bool empty() const { return stack.empty(); }

  Screen* top() {
    return stack.empty() ? nullptr : stack.back().get();
  }

  void push(std::unique_ptr<Screen> screen);

  void pop();

  void replace(std::unique_ptr<Screen> screen);

  void updateTop();
  void renderTop();

private:
  std::vector<std::unique_ptr<Screen>> stack;
};

} // namespace core