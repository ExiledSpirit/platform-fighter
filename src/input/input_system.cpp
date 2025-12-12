#include "input_system.h"
#include "raylib.h"

InputFrame InputSystem::sampleCurrentFrame() const
{
  InputFrame input{};

  input.moveLeft = IsKeyDown(KEY_LEFT);
  input.moveRight = IsKeyDown(KEY_RIGHT);
  input.moveDown = IsKeyDown(KEY_DOWN);
  input.moveUp = IsKeyDown(KEY_UP);
  input.pause = IsKeyDown(KEY_P);
  input.reset = IsKeyDown(KEY_R);

  return input;
}
