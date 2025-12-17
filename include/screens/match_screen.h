#pragma once
#include "core/screen.h"
#include "core/event_bus.h"
#include "input/input_router.h"
#include "match/frame_controller.h"
#include "match/replay.h"
#include "world/stage.h"

namespace screens {

class MatchScreen : public core::Screen {
public:
    MatchScreen(core::EventBus& bus, input::InputRouter& router);

    void onEnter() override;
    void update() override;
    void render() override;
    void handleUI(const input::UIActionEvent& e) override;

private:
    core::EventBus& events;
    input::InputRouter& inputRouter;

    world::Stage stage;
    match::FrameController fc;
    match::Replay replay;

    // dev toggles
    bool showDebug = true;

    void resetMatch();
    void renderCollisionsBoxes();
};

} // namespace screens
