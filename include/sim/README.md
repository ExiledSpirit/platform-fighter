# sim

sim contains types that represent the **deterministic simulation snapshot**

`SimState` is the complete world state at a given frame.
This is what rollback stores/restores and what replays can reconstruct.

Rule:
- SimState must be deterministic and serializable (`JSON` or other formats).
- Prefer simple POD-like structs.
