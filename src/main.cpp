#include "raylib.h"
#include "config.h"
#include "game_app.h"

int main()
{
    InitWindow(GameConfig::WINDOW_WIDTH, GameConfig::WINDOW_HEIGHT, "hello world!");
    SetTargetFPS(GameConfig::TARGET_FPS);

    GameApp app;
  
    while (!WindowShouldClose())
    {
        app.update();
        app.render();
    }
    
    CloseWindow();
    return 0;
}
