#pragma once
#include "core/screen.h"

namespace screens {

class MainMenuScreen : public core::Screen {
public:
    void update() override;
    void render() override;
    void handleUI(const input::UIActionEvent& e) override;

private:
    int selected = 0;
};

} // namespace screens
