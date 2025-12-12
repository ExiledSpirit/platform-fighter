# game

Game contains **project-wide shared definitions**:
- configuration constants (window size, target FPS [fixed at 60])
- shared enums/structs that multiple modules depend on

Rule:
- This folder must be small and stable.
- should avoid putting gameplay logic here (these must go in match/entities/screens)
