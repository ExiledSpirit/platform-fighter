#include "screens/main_menu_screen.h"
#include  <cmath>
#include "raylib.h"

namespace screens {

MainMenuScreen::MainMenuScreen(core::EventBus& bus)
    : events(bus) {}

void MainMenuScreen::update() {
    if (shakeFramesLeft > 0) {
        --shakeFramesLeft;
        ++shakeFrame;
    }
}

float MainMenuScreen::computeShakeOffsetX() const {
    if (shakeFramesLeft <= 0) return 0.0f;

    const float progress = (1.0f - shakeFramesLeft) / SHAKE_TOTAL_FRAMES; // 0..1 normalized
    const float damping = 1.0f - progress; // fade
    return std::sinf(shakeFrame * 0.9f) * SHAKE_AMPLITUDE * damping; // The greater the damping the greater the offset
}

void MainMenuScreen::triggerShake(int optionToShake) {
    shakeFramesLeft = SHAKE_TOTAL_FRAMES;
    shakeFrame = 0;
    shakingOption = optionToShake;
}

void MainMenuScreen::render() {
    DrawText("MAIN MENU", 40, 40, 30, RAYWHITE);
    // 0 = Start Button
    DrawText(selected == 0 ? "> Start" : "  Start", 40, 100, 20, selected == 0 ? GOLD : RAYWHITE);
    
    // 1 = Options Button
    const float offsetX = 40.0f + computeShakeOffsetX();
    DrawText(selected == 1 ? "> Options" : "  Options", offsetX, 130, 20, selected == 1 ? DARKGRAY : GRAY);


    DrawText("Enter = confirm | Esc = back", 40, 200, 18, RAYWHITE);
}

void MainMenuScreen::handleUI(const input::UIActionEvent& e) {
    // sanity check
    if (e.state != input::ButtonState::Pressed) return;

    switch (e.action) {
        case input::UIAction::Up:
        case input::UIAction::Down:
            selected = (selected + 1) % 2;
            break;
        case input::UIAction::Confirm:
            switch (selected) {
                case 0:
                    // Make request to change into game screen
                    events.emit(core::ScreenRequest{
                        core::ScreenRequestType::Replace,
                        game::ScreenId::Game
                    });
                    break;
                case 1:
                    triggerShake(1);
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }
}

} // namespace screens
