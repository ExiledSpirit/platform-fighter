# entities

Entities are gameplay objects that exist in the world/simulation:
  - Ball (current prototype entity)
  - later: Player, Projectile, Stage hazards, etc.

Rule:
  - Entities should expose their simulation state cleanly (get/set state)
  - Avoid direct knowledge of screens/menus (decoupling)
