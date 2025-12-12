# TODO - app

- [ ] implement GameApp
  - init services singleton (EventBus, InputRouter, ScreenStack)
  - push MainMenu into `core::ScreenStack` at start
- [ ] Define and handle screen transitions requests
  - RequestPush(ScreenId)
  - RequestPop()
  - RequestReplace(ScreenId)
- [ ] Centralize debug overlay toggles (frame index, fps, rollback count)
- [ ] Add a simple logging layer (wrap raylib TraceLog)
