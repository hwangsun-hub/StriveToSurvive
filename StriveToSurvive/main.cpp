#include "library.h"

int main()
{
    InitWindow(window_start_width, window_start_height, window_name);
    SetTargetFPS(window_frames_per_second);

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

