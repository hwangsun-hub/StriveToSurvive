#include "library.h"

bool DEBUGING_MODE = true;
bool exitWindow = false;

//defalt : GAMESTATE_TITLE
GameState gamestate = GAMESTATE_INGAME;


int main()
{
    srand(unsigned int(time(NULL)));
    InitWindow(WINDOW_START_WIDTH, WINDOW_START_HEIGHT, WINDOW_NAME);
    InitAudioDevice();
    SetTargetFPS(WINDOW_FRAMES_PER_SECOND);

    Music music = LoadMusicStream("resources/ypurmo.mp3");
    SetMusicVolume(music, 0.01f);

    
    Texture Map = LoadTexture("resources/Map.png");
    Camera2D camera = { 0, };
    Player player(camera);
    camera.offset = { float(GetScreenWidth() / 2) , float(GetScreenHeight() / 2) };
    camera.zoom = 1;
    TileMap tilemap(&player);
    EnemyManager<TestEnemy> testenemy(&player);
    Shop shop(&player);
    GameTitle gametitle;
    bool isMusicPause = false;
    bool isGamePause = false;
    int id = 0;
    while (!WindowShouldClose() && !exitWindow) {
        BeginDrawing();
        ClearBackground(BLACK);
        //update
        switch (gamestate)
        {
        case GAMESTATE_TITLE:
            camera.target = { WINDOW_START_WIDTH / 2 ,WINDOW_START_HEIGHT / 2 };
            gametitle.Update();
            BeginMode2D(camera);
            gametitle.Draw();
            EndMode2D();
            EndDrawing();
            break;
        case GAMESTATE_BEFORE_GAME:
            camera.target = { 0,0 };
            //update
            BeginMode2D(camera);
            //draw
            EndMode2D();
            EndDrawing();
            break;
        case GAMESTATE_INGAME:
            //update
            UpdateMusicStream(music);
            player.Update();
            camera.target = Vector2Lerp(camera.target, player.GetPosition(), 10 * GetFrameTime());
            testenemy.UpdateEnemies();
            tilemap.Update();
            BeginMode2D(camera);
            //debug mode toggle (KEY_F5)
            if (IsKeyReleased(KEY_F5)) {
                DEBUGING_MODE = !DEBUGING_MODE;
            }
            //debug mode
            if (DEBUGING_MODE) {
                if (IsKeyReleased(KEY_SPACE)) {
                    isGamePause = !isGamePause;
                }
                //Fullscreen (KEY_ENTER)
                if (IsKeyReleased(KEY_ENTER)) {
                    ToggleFullscreen();
                }
                //zoom in & out & reset (KEY_PAGE_UP, KEY_PAGE_DOWN, KEY_HOME)
                if (IsKeyDown(KEY_PAGE_UP)) {
                    camera.zoom += 0.01f;
                }
                else if (IsKeyDown(KEY_PAGE_DOWN)) {
                    camera.zoom -= 0.01f;
                }
                else if (IsKeyDown(KEY_HOME)) {
                    camera.zoom = 1.0f;
                }
                //player weapon change(KEY_UP, KEY_DOWN)
                if (IsKeyPressed(KEY_UP)) {
                    if (id < NONE_WEAPON) {
                        id++;
                    }
                    player.SetWeapon(static_cast<WeaponId>(id));
                }
                else if (IsKeyPressed(KEY_DOWN)) {
                    if (id > COMMON_KATANA_KATANA) {
                        id--;
                    }
                    player.SetWeapon(static_cast<WeaponId>(id));
                }
                //Spawn a Enemy (KEY_F1)
                if (IsKeyReleased(KEY_F1)) {
                    testenemy.SpawnEnemies(2);
                }
                // Restart music playing (stop and play) (KEY_F10)
                if (IsKeyPressed(KEY_F10)) {
                    StopMusicStream(music);
                    PlayMusicStream(music);
                }
                else if (IsKeyPressed(KEY_F11)) {
                    isMusicPause = !isMusicPause;
                    if (isMusicPause) {
                        PauseMusicStream(music);
                    }
                    else {
                        ResumeMusicStream(music);
                    }
                }

                //draw test map
                DrawTextureEx(Map, { -float(Map.width / 2), -float(Map.height / 2) }, 0, 1, WHITE);
            }

            //draw
            tilemap.Draw();
            player.Draw();
            testenemy.DrawEnemies();
            EndMode2D();
            EndDrawing();
            break;
        case GAMESTATE_SHOPPING:

            if (IsKeyReleased(KEY_ENTER)) {
                ToggleFullscreen();
            }
            camera.target = { WINDOW_START_WIDTH / 2 ,WINDOW_START_HEIGHT / 2 };
            shop.Update();
            BeginMode2D(camera);
            shop.Draw();
            EndMode2D();
            EndDrawing();
            break;
        
        }
       
    }

    CloseWindow();
    return 0;
}

