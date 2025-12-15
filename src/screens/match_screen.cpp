#include "screens/match_screen.h"
#include "raylib.h"
#include <cstdio>

namespace screens {

MatchScreen::MatchScreen(core::EventBus& bus, input::InputRouter& router)
  : events(bus), inputRouter(router) {
    TraceLog(LOG_INFO, "MatchScreen CTOR");
    resetMatch();
  }

void MatchScreen::onEnter() {
  inputRouter.setContext(input::Context::Gameplay); // Not UI anymore.
  TraceLog(LOG_INFO, "MatchScreen onEnter");
}

void MatchScreen::resetMatch() {
  fc = match::FrameController{};
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

  if (in.down(input::GameAction::Left)) {
    int test = 0;
  }

  fc.step(in);
}

void MatchScreen::render() {
  const auto& st  = fc.state();

  ClearBackground(DARKGRAY);
  // Stage
  // TODO: unhardcode stage stuff
  DrawLine(20, (int)match::FrameController::GroundY + 20, GetScreenWidth()-20, (int)match::FrameController::GroundY + 20, WHITE);

  // Character (placeholder)
  // TODO: replace for animationControl and spritesheet
  DrawCircle((int)st.p1.x, (int)st.p1.y, 16.0f, RAYWHITE);

  // dev stuff
  if (showDebug) {
    char buf[160];
    std::snprintf(buf, sizeof(buf),
      "Frame: %u | grounded=%d | vX=%.2f vy=%.2f | REC:%d (%zu) PLAY:%d (%zu/%zu)",
      st.frame, (int)st.p1.grounded, st.p1.vx, st.p1.vy,
      (int)replay.isRecording(), replay.size(),
      (int)replay.isPlaying(), replay.position(), replay.size()
    );
    DrawText(buf, 12, GetScreenHeight() - 20, 18, GREEN);
  }
}

void MatchScreen::handleUI(const input::UIActionEvent& e) {
  (void)e;
  // Usefull to handle pause menu later
}

} // namespace screens
