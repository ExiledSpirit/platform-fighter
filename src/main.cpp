#include "raylib.h"
#include "game/config.h"

#include "input/input_system.h"
#include "input/input_router.h"
#include "screens/main_menu_screen.h"
#include "app/game_app.h"
#include "entities/character/character.h"

int main() {
    InitWindow(GameConfig::WINDOW_WIDTH, GameConfig::WINDOW_HEIGHT, "Platform Fighter Prototype");
    SetTargetFPS(GameConfig::TARGET_FPS);

    app::GameApp app;
    // 3D
    Camera3D camera = { };
    camera.position = (Vector3){ 0.0f, 6.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 2.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    //

    // 3d model logic
    entities::CharacterDefinition def =
        entities::CharacterDefinition::LoadFromFile("resources/entities/characters/Alien.json");

    entities::Character character(def);

    while (!WindowShouldClose()) {
        // app.update();
        float dt = GetFrameTime();
        character.Update(dt);
        BeginDrawing();
            ClearBackground(RAYWHITE);
                BeginMode3D(camera);
                DrawPlane({0,0,0}, {20,20}, GREEN);
                character.Draw();
                EndMode3D();
            // app.render();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
