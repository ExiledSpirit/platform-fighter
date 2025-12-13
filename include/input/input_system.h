#pragma once

namespace input {

class InputSystem {
public:
    bool isKeyDown(int key) const;
    bool isKeyPressed(int key) const;
    bool isKeyReleased(int key) const;
};

} // namespace input
