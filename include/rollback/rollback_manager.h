#pragma once
#include <array>
#include<cstdint>
#include "sim/sim_state.h"
#include "game/game_types.h"

namespace rollback {

class RollbackManager {
public:
  static constexpr int MAX_FRAMES = 120; // Assuming game is running at 60fps as intended

  void saveState(uint32_t frame, const sim::SimState& state, const game::InputFrame& input);
  bool loadState(uint32_t frame, sim::SimState& outState, game::InputFrame& outInput) const;

private:
  struct FrameSlot {
    bool valid = false;
    uint32_t frame = 0;
    sim::SimState state;
    game::InputFrame input;
  };

  std::array<FrameSlot, MAX_FRAMES> buffer{};
};

} // namespace rollback
