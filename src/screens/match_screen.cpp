#include "screens/match_screen.h"
#include "raylib.h"

namespace screens {

void MatchScreen::update() {
  // match/ rollback, etc
}

void MatchScreen::render() {
  DrawText("MATCH SCREEN!!!", 40, 40, 40, RAYWHITE);
}

void MatchScreen::handleUI(const input::UIActionEvent&) {
  // for now we just ignore UI stuff
}

} // namespace screens
