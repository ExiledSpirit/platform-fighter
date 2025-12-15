#pragma once
#include "core/screen.h"

namespace screens {

class MatchScreen : public core::Screen {
public:
  void update() override;
  void render() override;
  void handleUI(const input::UIActionEvent& e) override;
};

} // namespace screens
