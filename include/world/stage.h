#pragma once
#include <vector>
#include "world/AABB.h"

namespace world {

class Stage {
public:
    const std::vector<AABB>& colliders() const { return m_colliders; }

    static Stage makeTestStage() {
        Stage s;

        // Ground
        s.m_colliders.push_back({ 0, 520, 800, 40 });

        // Left wall
        // s.m_colliders.push_back({ -20, 520 - 300, 40, 300 });

        // Right wall
        // s.m_colliders.push_back({ 780, 520 - 300, 40, 300 });

        return s;
    }

private:
    std::vector<AABB> m_colliders;
};

} // namespace world
