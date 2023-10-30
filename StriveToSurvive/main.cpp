#include "library.h"

int main()
{
    InitWindow(WINDOW_START_WIDTH, WINDOW_START_HEIGHT, WINDOW_NAME);
    SetTargetFPS(WINDOW_FRAMES_PER_SECOND);
    Player player;
    FollowCamera camera;

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        BeginMode2D(camera.GetCamera());   
            player.Update();
            camera.Update();
        EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

