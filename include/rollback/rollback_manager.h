#pragma once
#include <array>
#include<cstdint>
#include "sim_state.h"
#include "game_types.h"

class RollbackManager {
public:
  static constexpr int MAX_FRAMES = 120; // Assuming game is running at 60fps as intended

  void saveState(uint32_t frame, const SimState& state, const InputFrame& input);
  bool loadState(uint32_t frame, SimState& outState, InputFrame& outInput) const;

private:
  struct FrameSlot {
    bool valid = false;
    uint32_t frame = 0;
    SimState state;
    InputFrame input;
  };

  std::array<FrameSlot, MAX_FRAMES> buffer{};
};
