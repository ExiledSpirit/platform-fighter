# TODO - rollback

- [ ] Rollbackmanager ring buffer (states + inputs)
- save(frame, state, input)
- load(frame) => state + input
- [ ] Add "forced rollback" debug command:
  - press key -> load frameIndex - N -> resimulate to now
- [ ] Add serializer interface (even if initial impl is just memcpy-style copy)
  - serialize(SimState) -> bytes
  - deserialize(bytes) -> SimState
- [ ] Add desync detection hooks (hash of SimState)
- [ ] Add input log format for replays (future)
