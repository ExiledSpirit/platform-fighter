# TODO - sim

- [ ] Define `SimState` minimal version:
  - game time/frame index
  - ball state (for our current prototype phase)
  - RNG state placeholder (for later determinism)
- [ ] Decide whether to use raylib types (Vector2) or our own custom types (possibly `core::math`)
  - long-term: prefer custom math to reduce coupling (from the rendering engine raylib) and improve determinism control
- [ ] Add helper: `bool equals(const SimState&, const SimState&)` for desync checks (if player 1 and player 2 state are different rollback)
