#include "input/input_router.h"
#include "core/screen.h"
#include "raylib.h"

namespace input {

InputRouter::InputRouter(InputSystem& inputSystem)
    : input(inputSystem) {}

void InputRouter::setContext(Context ctx) { context = ctx; }
Context InputRouter::getContext() const { return context; }

void InputRouter::routeTo(core::Screen& screen) {
    if (context == Context::UI) {
        routeUI(screen);
    }
    // Gameplay routing later
}

void InputRouter::routeUI(core::Screen& screen) {
    auto emitPressed = [&](UIAction a, int key) {
        if (input.isKeyPressed(key)) {
            screen.handleUI(UIActionEvent{ a, ButtonState::Pressed });
        }
    };

    emitPressed(UIAction::Up, KEY_UP);
    emitPressed(UIAction::Down, KEY_DOWN);
    emitPressed(UIAction::Left, KEY_LEFT);
    emitPressed(UIAction::Right, KEY_RIGHT);
    emitPressed(UIAction::Confirm, KEY_ENTER);
    emitPressed(UIAction::Back, KEY_ESCAPE);
}

} // namespace input
