﻿#include "library.h"

bool DEBUGING_MODE = true;

int main()
{
    srand(unsigned int(time(NULL)));
    InitWindow(WINDOW_START_WIDTH, WINDOW_START_HEIGHT, WINDOW_NAME);
    InitAudioDevice();
    Music music = LoadMusicStream("resourse/ypurmo.mp3");
    SetMusicVolume(music, 0.01f);
    SetTargetFPS(WINDOW_FRAMES_PER_SECOND);
    Texture Map = LoadTexture("resourse/Map.png");
    Camera2D camera = { 0, };
    Player player(camera);
    camera.offset = { float(GetScreenWidth() / 2) , float(GetScreenHeight() / 2) };
    camera.zoom = 1;
    EnemyManager<TestEnemy> testenemy(&player);
    bool isMusicPause = false;

    while (WindowShouldClose() == false) {
        BeginDrawing();
        ClearBackground(BLACK);
        //update
        UpdateMusicStream(music);
        
        player.Update();
        camera.target = player.GetPosition();
        testenemy.UpdateEnemies();
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
            //zoom in & out & reset (KEY_PAGE_UP, KEY_PAGE_DOWN, KEY_HOME)
            if (IsKeyDown(KEY_PAGE_UP)) {
                camera.zoom += 0.01f;
            }
            else if (IsKeyDown(KEY_PAGE_DOWN)) {
                camera.zoom -= 0.01f;
            }
            else if(IsKeyDown(KEY_HOME)) {
                camera.zoom = 1.0f;
            }
            //player weapon change(KEY_UP, KEY_DOWN)
            if (IsKeyDown(KEY_UP)) {
                player.SetWeapon(TEST_MELEE_WEAPON);
            }
            else if (IsKeyDown(KEY_DOWN)) {
                player.SetWeapon(TEST_RANGED_WEAPON);
            }
            //Spawn a Enemy (KEY_F1)
            if (IsKeyReleased(KEY_F1)) {
                testenemy.SpawnEnemies(1);
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
        testenemy.DrawEnemies();
        player.Draw();
        EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

