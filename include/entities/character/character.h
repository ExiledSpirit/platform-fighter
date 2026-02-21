#include "raylib.h"
#include <string>
#include "entities/character/character_definition.h"
#include <unordered_map>

namespace entities
{

class Character
{
  public:
    Character(const entities::CharacterDefinition& definition);
    ~Character();

    void Update(float dt);
    void Draw();

  private:
    void SetState(entities::CharacterState newState);
    void LoadAnimations();
    int FindAnimationIndexByName(const std::string& name);

    Vector3 position;
    Vector3 velocity;
    bool isGrounded;

    CharacterState state;

    int currentAnimIndex;
    int currentAnimFrame;

    Model model;
    ModelAnimation* animations;
    int animationCount;

    std::unordered_map<CharacterState, int> animationMap;

    float moveSpeed;
    float jumpForce;
};

}