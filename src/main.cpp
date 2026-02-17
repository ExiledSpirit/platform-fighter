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
    // 3D
    Camera3D camera = { };
    camera.position = (Vector3){ 0.0f, 20.0f, 80.0f };
    camera.target = (Vector3){ 0.0f, 10.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    //

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
            app.update();
        EndMode3D();
        app.render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
