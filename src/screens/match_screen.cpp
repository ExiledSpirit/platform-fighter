#include "screens/match_screen.h"
#include "raylib.h"
#include <cstdio>

namespace screens {

MatchScreen::MatchScreen(core::EventBus& bus, input::InputRouter& router)
  : events(bus)
  , inputRouter(router)
  , stage(world::Stage::makeTestStage())
  , fc(stage) {
    TraceLog(LOG_INFO, "MatchScreen CTOR");
    resetMatch();
  }

void MatchScreen::onEnter() {
  inputRouter.setContext(input::Context::Gameplay); // Not UI anymore.
  TraceLog(LOG_INFO, "MatchScreen onEnter");
}

void MatchScreen::resetMatch() {
  replay.stopPlayback();
  replay.stopRecording();
}

void MatchScreen::update() {
  // match/ rollback, etc
  input::GameInputFrame in{};

  if (replay.isPlaying()) {
    if (!replay.next(in)) {
      // playback ended
    }
  } else {
    in = inputRouter.sampleGameplay();
    replay.push(in);
  }

  fc.step(in);
}

void MatchScreen::render() {
  const auto& st  = fc.state();

  ClearBackground(DARKGRAY);
  // Stage
  // TODO: unhardcode stage stuff
  DrawLine(0, 520, GetScreenWidth(), 520, WHITE);

  // Character (placeholder)
  // TODO: replace for animationControl and spritesheet
  for (const auto& player : st.players) {
    const auto& b = player.body;
    DrawCircle((int)b.pos.x, (int)b.pos.y, 16.0f, RAYWHITE);
  }

  // Colliders
  renderCollisionsBoxes();

  // dev stuff
  if (showDebug) {
    if (!st.players.empty()) {
      char buf[160];
      const auto& b = st.players[0].body;
      std::snprintf(buf, sizeof(buf),
        "Frame: %u | grounded=%d | vX=%.2f vY=%.2f",
        st.frame,
        (int)b.grounded,
        b.vel.x,
        b.vel.y
      );

      DrawText(buf, 12, GetScreenHeight() - 20, 18, GREEN);
    }
  }
}

void MatchScreen::renderCollisionsBoxes() {
  const auto& colliders = stage.colliders();

  for (const auto& collider : colliders) {
    DrawRectangle(collider.x, collider.y, collider.w, collider.h, GREEN);
  }
}

void MatchScreen::handleUI(const input::UIActionEvent& e) {
  (void)e;
  // Usefull to handle pause menu later
}

} // namespace screens
