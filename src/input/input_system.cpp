#include "input/input_system.h"
#include "raylib.h"

namespace input {

bool InputSystem::isKeyDown(int key) const { return IsKeyDown(key); }
bool InputSystem::isKeyPressed(int key) const { return IsKeyPressed(key); }
bool InputSystem::isKeyReleased(int key) const { return IsKeyReleased(key); }

} // namespace input
