#pragma once
#include "ui/rect.h"

namespace ui {

enum class Anchor {
  TopLeft, Top, TopRight,
  Left, Center, Right,
  BottomLeft, Bottom, BottomRight
};

inline Rect place(Rect bounds, Anchor a, float w, float h, float margin = 0.0f) {
  float x = bounds.x, y = bounds.y;

  const float left    = bounds.x + margin;
  const float right   = bounds.x + bounds.w - w - margin;
  const float top     = bounds.y + margin;
  const float bottom  = bounds.y + bounds.h - h - margin;
  const float cx      = bounds.x + (bounds.w - w) * 0.5f;
  const float cy      = bounds.y + (bounds.h - h) * 0.5f;

  switch (a) {
    case Anchor::TopLeft:     x = left;  y = top;    break;
    case Anchor::Top:         x = cx;    y = top;    break;
    case Anchor::TopRight:    x = right; y = top;    break;
    case Anchor::Left:        x = left;  y = cy;     break;
    case Anchor::Center:      x = cx;    y = cy;     break;
    case Anchor::Right:       x = right; y = cy;     break;
    case Anchor::BottomLeft:  x = left;  y = bottom; break;
    case Anchor::Bottom:      x = cx;    y = bottom; break;
    case Anchor::BottomRight: x = right; y = bottom; break;
  }

  return Rect { x, y, w, h };
}

} // namespace ui
