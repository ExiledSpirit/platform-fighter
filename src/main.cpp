#include "raylib.h"
#include "game/config.h"

#include "input/input_system.h"
#include "input/input_router.h"
#include "screens/main_menu_screen.h"
#include "app/game_app.h"

int main() {
    InitWindow(GameConfig::WINDOW_WIDTH, GameConfig::WINDOW_HEIGHT, "Platform Fighter Prototype");
    SetTargetFPS(GameConfig::TARGET_FPS);

    app::GameApp app;

    while (!WindowShouldClose()) {
        app.update();

        BeginDrawing();
        app.render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
