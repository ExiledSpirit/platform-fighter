#pragma once
#include "raylib.h"

namespace ui {

struct Theme {
  int titleSize = 48;
  int itemSize = 30;
  int hintSize = 18;

  float panelPad = 20.0f;
  float itemH = 28.0f;
  float gap = 20.0f;


  // Tokens
  Color PROTO_ACCENT      = Color { 255, 212, 133, 255 };
  Color PROTO_PRIMARY      = Color { 229, 30, 65, 255 };
  Color PROTO_SECONDARY   = Color { 114, 131, 164, 255 };
  Color PROTO_WHITE       = Color { 254, 254, 254, 255 };
  Color PROTO_BLACK       = Color { 19, 0, 6, 255 };

  // Colors
  Color bg          = PROTO_BLACK;
  Color panelBg     = PROTO_BLACK;
  Color panelBorder = PROTO_BLACK;

  Color titleColor  = PROTO_ACCENT;
  Color text        = PROTO_SECONDARY;
  Color hint        = GRAY;
  Color selected    = PROTO_WHITE;
  Color disabled    = DARKGRAY;

  Color highlight   = Color { 255, 255, 255, 255 };
  float highlightAlpha = 0.10f;
};

inline Theme& theme() {
  static Theme t{};
  return t;
}

} // namespace ui