#include "screens/main_menu_screen.h"
#include  <cmath>

namespace screens {

MainMenuScreen::MainMenuScreen(core::EventBus& bus)
    : events(bus)
{
    items = {
        ui::MenuItem{
            "Start",
            true,
            [this]{
                events.emit(core::ScreenRequest{ core::ScreenRequestType::Replace, game::ScreenId::Game });
            }
        },
        ui::MenuItem{
            "Options",
            false,      // disabled
            []{}        // options doesnt exist yet so no callback
        }
    };
}

void MainMenuScreen::update() {
    // Update stuff
}

void MainMenuScreen::render() {
    DrawText("MAIN MENU", 40, 40, 30, RAYWHITE);
    
    // Screen bounds as a rect
    ui::Rect screen { 0, 0, (float)GetScreenWidth(), (float)GetScreenHeight() };

    // Centered panel
    ui::Rect panel = ui::center(screen, 520, 220);
    panel = ui::inset(panel, 20);

    // Menu area inside panel
    ui::Rect menuArea { panel.x, panel.y + 40, panel.w, 120 };

    // Draw menu
    ui::MenuStyle style;
    style.selected = GOLD;
    style.normal = RAYWHITE;
    style.disabled = DARKGRAY;

    // Draws each menu item and applies shaking offset
    auto drawResult = ui::drawMenu(menuArea, items, selected, style);
}

void MainMenuScreen::handleUI(const input::UIActionEvent& e) {
    // sanity check
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
                // Trigger shake effects and sfx
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
