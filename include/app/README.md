# app

app wires the entire program togheter.

GameApp:
- owns a ` ScreenStack` singleton instance
- owns shared services (`EventuBus`, `InputSystem`, `InputRouter`)
- applies screen transition requests
- controls the main "update/ render" flow

Rule:
- app decides which screen is active
- app should not contain gameplay simulation details (that belongs to `match/`), it only oschestrates requests
