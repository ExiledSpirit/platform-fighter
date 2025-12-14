#include "screens/main_menu_screen.h"
#include <cmath>

#include "raylib.h"
#include "ui/theme.h"
#include "ui/rect.h"
#include "ui/anchor.h"
#include "ui/panel.h"
#include "ui/menu.h"

namespace screens {

MainMenuScreen::MainMenuScreen(core::EventBus& bus)
    : events(bus)
{
    items = {
        ui::MenuItem{
            "START",
            true,
            [this]{
                events.emit(core::ScreenRequest{ core::ScreenRequestType::Replace, game::ScreenId::Game });
            }
        },
        ui::MenuItem{
            "OPTIONS",
            false,   // disabled for now
            []{}     // later: push options screen
        }
    };
}

void MainMenuScreen::update() {
    if (shakeFramesLeft > 0) {
        --shakeFramesLeft;
        ++shakeFrame;
        if (shakeFramesLeft == 0) shakingIndex = -1;
    }
}

float MainMenuScreen::computeShakeOffsetX() const {
    if (shakeFramesLeft <= 0) return 0.0f;

    const float progress = (float)(SHAKE_TOTAL_FRAMES - shakeFramesLeft) / (float)SHAKE_TOTAL_FRAMES;
    const float damping = 1.0f - progress;
    return std::sinf(shakeFrame * 0.9f) * SHAKE_AMPLITUDE * damping;
}

void MainMenuScreen::triggerShake(int idx) {
    shakingIndex = idx;
    shakeFramesLeft = SHAKE_TOTAL_FRAMES;
    shakeFrame = 0;
}

void MainMenuScreen::render() {
    auto& t = ui::theme();

    // Screen rect
    ui::Rect screen { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };

    ClearBackground(t.bg);

    // Title
    ui::Rect titleRect { 0, 60.0f, screen.w, 50.0f };
    ui::drawTextCentered(titleRect, "MAIN MENU", t.titleSize, t.titleColor);
    
    // Centered menu column
    const float menuW = 420.0f;
    const float menuH = 200.0f;
    ui::Rect menuArea = ui::place(screen, ui::Anchor::Center, menuW, menuH, 0.0f);

    // Move menu a bit upwards
    menuArea.y -= 50.0f;

    std::vector<float> offsets (items.size(), 0.0f);
    if (shakingIndex >= 0 && shakingIndex < (int)offsets.size()) {
        offsets[shakingIndex] = computeShakeOffsetX();
    }

    ui::drawMenu(menuArea, items, selected, &offsets);
}

void MainMenuScreen::handleUI(const input::UIActionEvent& e) {
    if (e.state != input::ButtonState::Pressed) return;
    if (items.empty()) return;

    switch (e.action) {
        case input::UIAction::Up:
            selected = ui::clampWrap(selected - 1, (int)items.size());
            break;
        case input::UIAction::Down:
            selected = ui::clampWrap(selected + 1, (int)items.size());
            break;
        case input::UIAction::Confirm: {
            auto& item = items[selected];
            if (!item.enabled) {
                triggerShake(selected);
                break;
            }
            if (item.onConfirm) item.onConfirm();
            break;
        }
        default:
            break;
    }
}

} // namespace screens
