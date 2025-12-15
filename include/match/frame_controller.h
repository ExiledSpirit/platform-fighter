#pragma once
#include "sim/sim_state.h"
#include "input/game_input.h"

namespace match {

class FrameController {
public:
    FrameController();

    void step(const input::GameInputFrame& p1Input);

    const sim::SimState& state() const { return st; }

    // simple stage for now
    static constexpr float GroundY = 520.0f;
    static constexpr float LeftWall = 40.0f;
    static constexpr float RightWall = 760.0f;
private:
    sim::SimState st;

    void stepCharacter(sim::CharacterState& c, const input::GameInputFrame& in);

};

} // namespace match
