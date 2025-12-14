#pragma once
#include "ui/rect.h"
#include "ui/text.h"
#include "ui/theme.h"
#include "raylib.h"

namespace ui {
inline void drawPanel(Rect r, const char* title = nullptr) {
    auto& t = theme();

    // Background
    DrawRectangleRounded(
        Rectangle{ r.x, r.y, r.w, r.h },
        0.0f,
        8,
        t.panelBg
    );

    if (title) {
        Rect titleRect{ r.x, r.y, r.w, 44.0f };
        drawTextCentered(titleRect, title, t.titleSize, t.titleColor);
    }
}


} // namespace ui
