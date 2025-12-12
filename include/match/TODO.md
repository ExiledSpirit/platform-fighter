# TODO - match

- [ ] Add FrameController skeleton (simulate 1 frame)
  - owns SimState
  - applies input -> updates entities -> outputs new SimState
- [ ] Integrate rollback save/load with FrameController step
- [ ] Add deterministic "ball movement" demo:
  - ball moves by action input
  - state snapshot stored each frame (optimization stuff required prob.)
- [ ] Add replay hooks:
  - record inputs per frame
  - playback by feeding inputs into FrameController
`