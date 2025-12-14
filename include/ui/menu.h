#pragma once
#include <vector>
#include <functional>
#include <cstdio>

#include "ui/rect.h"
#include "ui/layout.h"
#include "ui/text.h"
#include "ui/theme.h"
#include "raylib.h"

namespace ui {

struct MenuItem {
    const char* label;
    bool enabled = true;
    std::function<void()> onConfirm;
};

// Optional per-item x offsets (for shake, etc.)
inline std::vector<Rect> vstack(Rect container, int count, float itemH, float gap); // from layout.h

inline int clampWrap(int idx, int count) {
    if (count <= 0) return 0;
    if (idx < 0) return count - 1;
    if (idx >= count) return 0;
    return idx;
}

// Returns the rects for each item (useful for hit testing later)
inline std::vector<Rect> drawMenu(
    Rect area,
    const std::vector<MenuItem>& items,
    int selectedIndex,
    const std::vector<float>* offsetX = nullptr // optional
) {
    auto& t = theme();

    auto rows = ui::vstack(area, (int)items.size(), t.itemH, t.gap);

    for (int i = 0; i < (int)items.size(); ++i) {
        Rect r = rows[i];

        if (offsetX && i < (int)offsetX->size()) {
            r.x += (*offsetX)[i];
        }

        const bool isSelected = (i == selectedIndex);
        const bool isEnabled  = items[i].enabled;

        // Highlight strip (behind text)
        if (isSelected) {
            DrawRectangleRounded(
                Rectangle{ r.x - 10.0f, r.y - 10.0f, r.w + 20.0f, r.h + 20.0f },
                0.18f, 6,
                Fade(t.highlight, t.highlightAlpha)
            );
        }

        Color c;
        if (!isEnabled) c = t.disabled;
        else c = isSelected ? t.selected : t.text;

        char buf[96];
        std::snprintf(buf, sizeof(buf), "%s%s", isSelected ? "> " : "  ", items[i].label);
        drawTextLeft(r, buf, t.itemSize, c);
    }

    return rows;
}

} // namespace ui
