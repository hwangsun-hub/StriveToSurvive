#include "library.h"

int main()
{
    InitWindow(WINDOW_START_WIDTH, WINDOW_START_HEIGHT, WINDOW_NAME);
    SetTargetFPS(WINDOW_FRAMES_PER_SECOND);
    Player player;

    while (WindowShouldClose() == false) {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            player.Update();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

