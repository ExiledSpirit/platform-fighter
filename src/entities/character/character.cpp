#include "entities/character/character.h"
#include <iostream>
#include "raylib.h"

namespace entities {

Character::Character(const CharacterDefinition& definition)
{
  position = {0, 0, 0};
  velocity = {0, 0, 0};
  isGrounded = true;

  moveSpeed = definition.moveSpeed;
  jumpForce = definition.jumpForce;

  model = LoadModel(definition.modelPath.c_str());
  animations = LoadModelAnimations(definition.modelPath.c_str(), &animationCount);

  LoadAnimations();

  for (auto& [state, animName] : definition.animationNames)
  {
    int index = FindAnimationIndexByName(animName);
    if (index >= 0)
      animationMap[state] = index;
  }

  state = CharacterState::Idle;
  currentAnimIndex = animationMap[state];
  currentAnimFrame = 0;
}

Character::~Character()
{
  UnloadModel(model);
  UnloadModelAnimations(animations, animationCount);
}

void Character::LoadAnimations()
{
  for (int i = 0; i < animationCount; i++)
  {
    std::cout << "Animation " << i << ": "
      << animations[i].name << std::endl;
  }
}

int Character::FindAnimationIndexByName(const std::string& name)
{
  for (int i = 0; i < animationCount; i++)
  {
    if (name == animations[i].name)
      return i;
  }

  std::cerr << "Animation not found: " << name << std::endl;
  return -1;
}

void Character::SetState(CharacterState newState)
{
  if (state == newState) return;

  state = newState;
  currentAnimFrame = 0;

  if (animationMap.find(state) != animationMap.end())
    currentAnimIndex = animationMap[state];
}

void Character::Update(float dt)
{
  this->currentAnimFrame++;
  
  if (currentAnimFrame >= animations[currentAnimIndex].frameCount) currentAnimFrame = 0;

  UpdateModelAnimation(model, animations[currentAnimIndex], currentAnimFrame);
}

void Character::Draw()
{
  DrawModel(model, position, 1.0f, WHITE);
}

} // namespace entities
