#include "unordered_map"
#include "entities/character/character_state.h"
#include <string>

namespace entities
{

struct CharacterDefinition
{
  std::string modelPath;
  float moveSpeed;
  float jumpForce;

  std::unordered_map<CharacterState, std::string> animationNames;

  static CharacterDefinition LoadFromFile(const std::string& path);
};

}