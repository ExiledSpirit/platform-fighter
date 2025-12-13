#pragma once
#include <vector>
#include <functional>
#include <cstdio>

#include "ui/rect.h"
#include "ui/layout.h"
#include "ui/text.h"
#include "raylib.h"

namespace ui {

struct MenuItem {
  const char* label;
  bool enabled = true;
  std::function<void()> onConfirm; // callback function (only if enabled = true)
};

struct MenuStyle {
  int fontSize = 20;
  float itemHeight = 26.0f;
  float gap = 8.0f;

  Color normal = RAYWHITE;
  Color selected = GOLD;
  Color disabled = DARKGRAY;

  bool drawHighlight = true;
};

struct MenuDrawResult {
  std::vector<Rect> itemRects; // they can be rendered using raylib
};

inline MenuDrawResult drawMenu(
  Rect area,
  const std::vector<MenuItem>& items,
  int selectedIndex,
  const MenuStyle& style,
  int prefixMode = 1
) {
  MenuDrawResult out;
  out.itemRects = vstack(area, (int)items.size(), style.itemHeight, style.gap);

  for (int i = 0; i < (int)items.size(); ++i) {
    Rect r = out.itemRects[i];
    const bool isSelected = (i == selectedIndex);
    const bool isEnabled = items[i].enabled;

    Color c = isEnabled ? (isSelected ? style.selected : style.normal) : style.disabled;

    if (style.drawHighlight && isSelected) {
      DrawRectangle((int)r.x - 8, (int)r.y, (int)r.w + 16, (int)r.h, Fade(WHITE, 0.10f));
    }

    char buf[96];
    if (prefixMode == 1) {
      std::snprintf(buf, sizeof(buf), "%s%s", isSelected ? "> " : " ", items[i].label);
      drawTextLeft(r, buf, style.fontSize, c);
    } else {
      drawTextLeft(r, items[i].label, style.fontSize, c);
    }
  }

  return out;
}

// Wrap-around selection
inline int clampWrap(int idx, int count) {
  if (count <= 0) return 0;
  if (idx < 0) return count - 1;
  if (idx >= count) return 0;
  return idx;
}

} // namespace ui