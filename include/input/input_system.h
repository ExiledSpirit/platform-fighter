#pragma once
#include "game/game_types.h"

namespace input {

class InputSystem
{
public:
  game::InputFrame sampleCurrentFrame() const;
};

} // namespace input 
