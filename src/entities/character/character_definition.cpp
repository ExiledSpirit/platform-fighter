#include "entities/character/character_definition.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

using json = nlohmann::json;

namespace entities
{
static CharacterState StringToState(const std::string& str)
{
  if (str == "Idle") return CharacterState::Idle;
  if (str == "Walk") return CharacterState::Walk;

  throw std::runtime_error("Unknown CharacterState: " + str);
}

CharacterDefinition CharacterDefinition::LoadFromFile(const std::string& path)
{
  CharacterDefinition def;

  // Load json file from path
  std::ifstream file(path);
   if (!file.is_open())
    throw std::runtime_error("Failed to open JSON file: " + path);

  json data;
  file >> data;

  def.modelPath = data["model"];
  def.moveSpeed = data["moveSpeed"];
  def.jumpForce = data["jumpForce"];

  for (auto& [key, value] : data["animations"].items())
  {
    CharacterState state = StringToState(key);
    def.animationNames[state] = value;
  }

  return def;
}

}