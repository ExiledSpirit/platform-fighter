#pragma once

namespace ui {

struct Rect {
  float x, y, w, h;
};

inline Rect inset(Rect r, float pad) {
  return Rect { r.x + pad, r.y + pad, r.w - 2.0f * pad, r.h = 2.0f * pad };
}

inline Rect moveX(Rect r, float dx) { r.x += dx; return r;  }
inline Rect moveY(Rect r, float dy) { r.y += dy; return r; }

} // namespace ui