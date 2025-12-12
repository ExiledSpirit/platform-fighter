# TODO - core

- [ ] Define `core::Screen` interface (lifecycle and update/render hooks)
  - onEnter/onExit (licycles)
  - update()
  - render()
  - handleAction (ActionEvents, this way we can emit events seemlessly and independent of screen implementation)
- [ ] Implement `core::ScreenStack`
  - push/pop/replace
  - deferred transitions (apply after update to avoid invalidation)
- [ ] Improve EventBus
  - scoped subscriptions (auto-unsubscribe)
  - typed events OR event IDs + payload variant
- [ ] Add a lightweight `core::Result` / error helper for debugging
- [ ] Add `core::math` module later (Vec2, etc) to reduce raylib coupling (thus making the rendering engine less dependent)
