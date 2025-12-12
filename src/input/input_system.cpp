#include "input/input_system.h"
#include "raylib.h"

namespace input {

game::InputFrame InputSystem::sampleCurrentFrame() const
{
  game::InputFrame input{};

  input.moveLeft = IsKeyDown(KEY_LEFT);
  input.moveRight = IsKeyDown(KEY_RIGHT);
  input.moveDown = IsKeyDown(KEY_DOWN);
  input.moveUp = IsKeyDown(KEY_UP);
  input.pause = IsKeyDown(KEY_P);
  input.reset = IsKeyDown(KEY_R);

  return input;
}

} // input
