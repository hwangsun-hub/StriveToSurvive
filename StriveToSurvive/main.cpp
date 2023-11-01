#include "library.h"

int main()
{
    srand(unsigned int(time(NULL)));
    InitWindow(WINDOW_START_WIDTH, WINDOW_START_HEIGHT, WINDOW_NAME);
    SetTargetFPS(WINDOW_FRAMES_PER_SECOND);

    Texture Map = LoadTexture("resourse/Map.png");
    Player player;
    Camera2D camera = { 0, };
    camera.offset = { float(GetScreenWidth() / 2) , float(GetScreenHeight() / 2) };
    camera.zoom = 1;
    EnemyManager<TestEnemy> zombie(EnemyType::ZOMBIE, &player);
    zombie.SpawnEnemies();

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        player.Move();
        camera.target = player.GetPosition();
        player.UpdateSpawnpoint();
        zombie.MoveEnemies();
        BeginMode2D(camera);
        if (DEBUGING_MODE) {
            //zoom in & out (KEY_PAGE_UP, KEY_PAGE_DOWN)
            if (IsKeyDown(KEY_PAGE_UP)) {
                camera.zoom += 0.01;
            }
            else if (IsKeyDown(KEY_PAGE_DOWN)) {
                camera.zoom -= 0.01;
            }
            else if(IsKeyDown(KEY_HOME)) {
                camera.zoom = 1;
            }
            //draw spawnpoint
            player.DrawSpawnPoint();
            //draw test map
            DrawTexture(Map, -float(Map.width / 2), -float(Map.height / 2), WHITE);
        }
        zombie.DrawEnemies();
        player.Draw();
        EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

