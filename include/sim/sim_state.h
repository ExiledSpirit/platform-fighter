#pragma once
#include <cstdint>
#include <vector>
#include "sim/character_state.h"

namespace sim {

struct SimState {
    std::uint32_t frame = 0;
    std::vector<CharacterState> players;
};

} // namespace sim
