# Platform Fighter - Frame-Oriented Game Prototype

This repository a personal study project of mine: a **frame-based platform fighter from scratch** in C++ using **raylib** game engine.
My goal is to understand and implement the core architectural foundations used in professional fighting games such as **Street Fighter**, **Guilty Gear Strive** and others. The topics I aim to cover in this project are:

- Fixed-step 60 FPS simulation
- Frame-accurate mechanics
- Deterministic gameplay
- Rollback-friendly architecture
- Clean separation between game state, rendering, and input

If I can recreate even a tenth of the actual structural quality found in the titles cited, this project will already be a success.

---

# How to run

Ensure you have makefile installed so you can compile by just running make on your bash. After that, a main.exe will
appear in the root directory, execute it and voilà.

---

# Dependencies and Game Engine

- **C++17**
- **raylib** (only for windowing, rendering, and input)
- **MinGW / MSYS2** for compilation
- **Makefile**-based build system

For the initial setup I followed this guide:
[https://www.youtube.com/watch?v=AniAoJC6QAc](https://www.youtube.com/watch?v=AniAoJC6QAc)
