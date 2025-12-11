#pragma once

// manage screens
enum class GameMode {
  MainMenu,
  Playing,
  Paused
};

// basic inputs
struct InputFrame {
  bool moveLeft = false;
  bool moveRight = false;
  bool moveUp = false;
  bool moveDown = false;
  bool pause = false;
  bool reset = false;
};
