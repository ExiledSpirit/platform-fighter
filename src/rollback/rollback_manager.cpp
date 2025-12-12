#include "rollback/rollback_manager.h"

namespace rollback {

void RollbackManager::saveState(uint32_t frame, const sim::SimState& state, const game::InputFrame& input) {

}

bool RollbackManager::loadState(uint32_t frame, sim::SimState& outState, game::InputFrame& outInput) const {
  const size_t index = frame % MAX_FRAMES;
  const auto& slot = buffer[index]; 

  if (!slot.valid || slot.frame != frame) {
    return false;
  }

  outState = slot.state;
  outInput = slot.input;
  return true;
}

} //namespace rollback
