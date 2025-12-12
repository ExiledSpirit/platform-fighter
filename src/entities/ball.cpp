#include "ball.h"

Ball::Ball() {
  position = {0.0f, 0.0f};
  velocity = {0.0f, 0.0f};
}

void Ball::Update(const InputFrame& input) {
  const float speed = 4.0f;

  if (input.moveLeft) position.x -= speed;
  if (input.moveRight) position.x += speed;
  if (input.moveDown) position.y += speed;
  if (input.moveUp) position.y -= speed;
}

void Ball::Draw() const {
  DrawCircleV(position, 20.0f, RAYWHITE); // TODO: update with sprite later.
}

BallState Ball::getState() const {
  return BallState{ position, velocity };
}

void Ball::setState(const BallState& s) {
  position = s.position;
  velocity = s.velocity;
}
