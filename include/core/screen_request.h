#pragma once
#include "game/screen_id.h"

namespace core {

enum class ScreenRequestType {
  Push,
  Pop,
  Replace
};

struct ScreenRequest {
  ScreenRequestType type;
  game::ScreenId target; // for push and replace only
};

} // namespace core
