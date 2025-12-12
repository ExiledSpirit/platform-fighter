#include "game/config.h"
#include "app/game_app.h"
#include "raylib.h"

int main()
{
    InitWindow(GameConfig::WINDOW_WIDTH, GameConfig::WINDOW_HEIGHT, "hello world!");
    SetTargetFPS(GameConfig::TARGET_FPS);

    app::GameApp app;
  
    while (!WindowShouldClose())
    {
        app.update();
        app.render();
    }
    
    CloseWindow();
    return 0;
}
