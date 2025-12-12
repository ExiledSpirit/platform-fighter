# TODO - entities

- [ ] Keep Ball deterministic and frame-based (to keep rollback-friendly)
  - Update(InputFrame or Actions) should represent exactly 1 simulation frame
- [ ] Add unit-style "state roundtrip" test concept:
  - save state -> mutate -> restore -> ensure equality
- [ ] Plan future: Player entity API (not implementation yet)
  - getState/setState
  - Update(InputAction)
  - Draw(debugFlag)
