#include "screens/main_menu_screen.h"
#include "raylib.h"

namespace screens {

void MainMenuScreen::update() {
    // for now nothing
}

void MainMenuScreen::render() {
    DrawText("MAIN MENU", 40, 40, 30, RAYWHITE);
    DrawText(selected == 0 ? "> Start" : "  Start", 40, 100, 20, RAYWHITE);
    DrawText(selected == 1 ? "> Options" : "  Options", 40, 130, 20, RAYWHITE);
    DrawText("Enter = confirm | Esc = back", 40, 200, 18, RAYWHITE);
}

void MainMenuScreen::handleUI(const input::UIActionEvent& e) {
    if (e.state != input::ButtonState::Pressed) return;

    if (e.action == input::UIAction::Up) {
        selected = (selected + 1) % 2;
    } else if (e.action == input::UIAction::Down) {
        selected = (selected + 1) % 2;
    } else if (e.action == input::UIAction::Confirm) {
        // later: emit screen transition request
    }
}

} // namespace screens
