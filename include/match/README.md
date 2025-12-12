# match

match contains the deterministic gameplay simulation (later).

This is where the strict 60 FPS frame-based logic will live:
- FrameController (simulate exactly one frame)
- stage rules, timers, stocks, damage, hitboxes, etc.
- integration with rollback (save/ load/ step).

This folder is intentionally minimal until screens + input routing are solid.
