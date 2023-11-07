#include "library.h"

bool DEBUGING_MODE;

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
    EnemyManager<TestEnemy> zombie(&player);
    zombie.SpawnEnemies();

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        //update
        player.Update();
        camera.target = player.GetPosition();
        zombie.MoveEnemies();
        BeginMode2D(camera);
        //debug mode toggle (KEY_F5)
        if (IsKeyReleased(KEY_F5)) {
            DEBUGING_MODE = !DEBUGING_MODE;
        }
        //debug mode
        if (DEBUGING_MODE) {
            //Fullscreen (KEY_ENTER)
            if (IsKeyReleased(KEY_ENTER)) {
                ToggleFullscreen();
            }
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
            //player weapon change(KEY_UP, KEY_DOWN)
            if (IsKeyDown(KEY_UP)) {
                player.SetWeapon(TEST_MELEE_WEAPON);
            }
            else if (IsKeyDown(KEY_DOWN)) {
                player.SetWeapon(TEST_RANGED_WEAPON);
            }
            //draw test map
            DrawTexture(Map, -float(Map.width / 2), -float(Map.height / 2), WHITE);
        }

        //draw
        zombie.DrawEnemies();
        player.Draw();
        EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

