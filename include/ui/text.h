#pragma once
#include <cstdio>
#include "ui/rect.h"
#include "raylib.h"

namespace ui {

inline int textYCentered(Rect r, int fontSize) {
  return (int)(r.y + (r.h - fontSize) * 0.5f);
}

inline void drawTextLeft(Rect r, const char* text, int fontSize, Color color) {
  DrawText(text, (int)r.x, textYCentered(r, fontSize), fontSize, color);
}

inline void drawTextCentered(Rect r, const char* text, int fontSize, Color color) {
  Vector2 size = MeasureTextEx(GetFontDefault(), text, (float)fontSize, 1.0f);
  const int x = (int)(r.x + (r.w - size.x) * 0.5f);
  const int y = (int)(r.y + (r.h - size.y) * 0.5f);
  DrawText(text, x, y, fontSize, color);
}

} // namespace ui