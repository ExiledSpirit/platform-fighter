#pragma once
#include <cstdint>

namespace input {

enum class ButtonState : std::uint8_t {
  Pressed,
  Released
};

enum class UIAction : std::uint8_t {
  Up,
  Down,
  Left,
  Right,
  Confirm,
  Back
};

struct UIActionEvent {
  UIAction action;
  ButtonState state;
};

} // namespace input
