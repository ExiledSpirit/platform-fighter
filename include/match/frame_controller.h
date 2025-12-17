#pragma once
#include "sim/sim_state.h"
#include "input/game_input.h"
#include "world/stage.h"
#include "physics/physics_system.h"

namespace match {

class FrameController {
public:
    FrameController(const world::Stage& stage);

    void step(const input::GameInputFrame& p1Input);
    const sim::SimState& state() const { return st; }
private:
    sim::SimState st;
    const world::Stage& stage;
    physics::PhysicsSystem physics;

    void stepCharacter(sim::CharacterState& c, const input::GameInputFrame& in);
};

} // namespace match
