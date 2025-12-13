#pragma once
#include <vector>
#include "ui/rect.h"

namespace ui {

// auxiliar function that centers a rect of (w,h) inside bounds
inline Rect center(Rect bounds, float w, float h) {
  return Rect {
    bounds.x + (bounds.w - w) * 0.5f,
    bounds.y + (bounds.h - h) * 0.5f,
    w, h
  };
}

// like flex-direction: column; with fixed item height + gap
inline std::vector<Rect> vstack(Rect container, int count, float itemH, float gap) {
  std::vector<Rect> out;
  out.reserve((size_t) count); // initializes vector of size count

  float y = container.y;
  for (int i = 0; i < count; i++) {
    out.push_back(Rect{ container.x, y, container.w, itemH });
    y += itemH + gap;
  }
  return out;
}

} // namespace ui
