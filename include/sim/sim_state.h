#pragma once
#include <cstdint>
#include "sim/character_state.h"

namespace sim {

struct SimState {
    std::uint32_t frame = 0;
    CharacterState p1;
};

} // namespace sim
