#pragma once
#include "raylib.h"

namespace GameConfig {
  // Window logical resolution
  inline constexpr int WINDOW_WIDTH = 1280;
  inline constexpr int WINDOW_HEIGHT = 720;

  // Simulation render FPS (one tick per frame)
  inline constexpr int TARGET_FPS = 60;

  // Colors
  inline constexpr Color CLEAR_COLOR { 20, 160, 133, 255 };
}
