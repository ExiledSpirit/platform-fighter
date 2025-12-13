#include "screens/game_screen.h"
#include "raylib.h"

namespace screens {

void GameScreen::update() {
  // match/ rollback, etc
}

void GameScreen::render() {
  DrawText("GAME SCREEN!!!", 40, 40, 40, RAYWHITE);
  DrawText("Press ESC later to pause/back", 40, 90, 18, RAYWHITE);
}

void GameScreen::handleUI(const input::UIActionEvent&) {
  // for now we just ignore UI stuff
}

} // namespace screens
