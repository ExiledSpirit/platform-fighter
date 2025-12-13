#pragma once
#include "core/screen.h"
#include "core/event_bus.h"

namespace screens {

class MainMenuScreen : public core::Screen {
public:
    explicit MainMenuScreen(core::EventBus& bus);

    void update() override;
    void render() override;
    void handleUI(const input::UIActionEvent& e) override;

private:
    core::EventBus& events;

    int selected = 0; // 0 = Start, 1 = Options (change for enum later)

    // shake animations
    // TODO: Change for ShakeService later
    int shakeFramesLeft = 0;
    int shakeFrame = 0;
    int shakingOption = 0; // 0 = Start, 1 = Options
    static constexpr int SHAKE_TOTAL_FRAMES = 8;
    static constexpr float SHAKE_AMPLITUDE = 10.0f;

    void triggerShake(int optionToShake);
    float computeShakeOffsetX() const;
};

} // namespace screens
