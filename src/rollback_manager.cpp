#include "rollback_manager.h"

void RollbackManager::saveState(uint32_t frame, const SimState& state, const InputFrame& input) {

}

bool RollbackManager::loadState(uint32_t frame, SimState& outState, InputFrame& outInput) const {
  const size_t index = frame % MAX_FRAMES;
  const auto& slot = buffer[index]; 

  if (!slot.valid || slot.frame != frame) {
    return false;
  }

  outState = slot.state;
  outInput = slot.input;
  return true;
}
