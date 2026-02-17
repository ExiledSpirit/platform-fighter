#include "input/input_router.h"
#include "input/game_input.h"
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

input::GameInputFrame input::InputRouter::sampleGameplay() const {
    input::GameInputFrame f;
    f.set(GameAction::Left,  input.isKeyDown(KEY_LEFT));
    f.set(GameAction::Right, input.isKeyDown(KEY_RIGHT));
    f.set(GameAction::Down, input.isKeyDown(KEY_DOWN));
    f.set(GameAction::Up, input.isKeyDown(KEY_UP));
    f.set(GameAction::Jump,  input.isKeyPressed(KEY_SPACE));
    f.set(GameAction::Attack,input.isKeyPressed(KEY_J));
    f.set(GameAction::Dash,input.isKeyPressed(KEY_A));
    return f;
}
} // namespace input
