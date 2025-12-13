#pragma once
#include <vector>

#include "core/screen.h"
#include "core/event_bus.h"
#include "ui/menu.h"

namespace screens {

class MainMenuScreen : public core::Screen {
public:
    explicit MainMenuScreen(core::EventBus& bus);

    void update() override;
    void render() override;
    void handleUI(const input::UIActionEvent& e) override;

private:
    core::EventBus& events;

    std::vector<ui::MenuItem> items;
    int selected = 0; // 0 = Start, 1 = Options (change for enum later)
};

} // namespace screens
