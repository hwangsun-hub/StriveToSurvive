#include "library.h"

int main()
{
    InitWindow(WINDOW_START_WIDTH, WINDOW_START_HEIGHT, WINDOW_NAME);
    SetTargetFPS(WINDOW_FRAMES_PER_SECOND);

    Texture Map = LoadTexture("resourse/Map.png");
    Player player;
    Camera2D camera = { 0, };
    camera.offset = { float(GetScreenWidth() / 2) , float(GetScreenHeight() / 2) };
    camera.zoom = 1;
    Enemy enemy(&player);


    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        player.Move();
        camera.target = player.GetPosition();
        enemy.UpdateSpawnPoint();
        BeginMode2D(camera);
        if (DEBUGING_MODE) {
            camera.zoom =0.5;
            enemy.drawSpawnPoint();
            DrawTexture(Map, -float(Map.width / 2), -float(Map.height / 2), WHITE);
        }
        player.Draw();
        EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

