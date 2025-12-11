#include "raylib.h"
#include "ball.h"
#include "config.h"

// Global gamestate (in this case just a ball object).
static Ball ball;

// Simulates a specific frame.
void simulateFrame(unsigned int frameIndex);

int main()
{
    InitWindow(GameConfig::WINDOW_WIDTH, GameConfig::WINDOW_HEIGHT, "hello world!");
    SetTargetFPS(GameConfig::TARGET_FPS);

    unsigned int frameIndex = 0;
    
    while (!WindowShouldClose())
    {
        // first we simulate things
        simulateFrame(frameIndex);
        
        // then we render with the already simulated game state
        BeginDrawing();
            ClearBackground(GameConfig::CLEAR_COLOR);
            ball.Draw();
        EndDrawing();

        ++frameIndex;
    }
    
    CloseWindow();
    return 0;
}

void simulateFrame(unsigned int frameIndex)
{
    ball.Update();
}
