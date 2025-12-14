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
    int selected = 0;

    // Shake
    int shakeFramesLeft = 0;
    int shakeFrame = 0;
    int shakingIndex = -1;

    static constexpr int SHAKE_TOTAL_FRAMES = 18;
    static constexpr float SHAKE_AMPLITUDE = 10.0f;

    float computeShakeOffsetX() const;
    void triggerShake(int idx);
};

} // namespace screens
