#include "library.h"

bool DEBUGING_MODE = false;
bool exitWindow = false;

int wave_level = 1;
int talent_score = 5;

//defalt : GAMESTATE_TITLE
GameState gamestate = GAMESTATE_TITLE;


int main()
{
    srand(unsigned int(time(NULL)));
    InitWindow(WINDOW_START_WIDTH, WINDOW_START_HEIGHT, WINDOW_NAME);
    InitAudioDevice();
    SetTargetFPS(WINDOW_FRAMES_PER_SECOND);

    Music ingame_music = LoadMusicStream("resources/ypurmo.mp3");
    SetMusicVolume(ingame_music, 0.1f);

    camera = { 0, };
    Player player;
    camera.offset = { float(GetScreenWidth() / 2) , float(GetScreenHeight() / 2) };
    camera.zoom = 1.0;
    TileMap tilemap(&player);
    WaveManager wavemanager(&player);
    Shop shop(&player);
    GameTitle gametitle;
    Ui ui(&player);
    int id = 0;
    while (!WindowShouldClose() && !exitWindow) {
        BeginDrawing();
        ClearBackground(BLACK);
        //update
        switch (gamestate)
        {
        case GAMESTATE_TITLE:
            camera.zoom = 1.0f;
            camera.target = { WINDOW_START_WIDTH / 2 ,WINDOW_START_HEIGHT / 2 };
            gametitle.Update();
            BeginMode2D(camera);
            gametitle.Draw();
            EndMode2D();
            EndDrawing();
            break;
        case GAMESTATE_BEFORE_GAME:
            camera.zoom = 1.0f;
            camera.target = { WINDOW_START_WIDTH/2,WINDOW_START_HEIGHT/2 };
            //update
            ui.UpdateBeforeGameUi();
            BeginMode2D(camera);
            //draw
            EndMode2D();
            ui.DrawBeforeGameUi();
            EndDrawing();
            break;
        case GAMESTATE_INGAME:
            camera.zoom = 0.75f;
            //update
            UpdateMusicStream(ingame_music);
            PlayMusicStream(ingame_music);
            camera.target = Vector2Lerp(camera.target, player.GetPosition(), 7 * GetFrameTime());
            player.Update();
            wavemanager.Update();
            tilemap.Update();
            ui.UpdateIngameUi();
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
                //Spawn a Enemy (KEY_F1,F2,F3)
                if (IsKeyReleased(KEY_F1)) {
                    wavemanager.runner_enemymanager->SpawnEnemies(1);
                }
                if (IsKeyReleased(KEY_F2)) {
                    wavemanager.tanker_enemymanager->SpawnEnemies(1);
                }
                if (IsKeyReleased(KEY_F3)) {
                    wavemanager.spider_enemymanager->SpawnEnemies(1);
                }
                // Restart music playing (stop and play) (KEY_F10)
                if (IsKeyPressed(KEY_F10)) {
                    StopMusicStream(ingame_music);
                    PlayMusicStream(ingame_music);
                }
            }

            //draw
            tilemap.Draw();
            player.Draw();
            wavemanager.Draw();
            EndMode2D();
            //drawui
            ui.DrawIngameUi();
            EndDrawing();
            break;
        case GAMESTATE_GAMEOVER:
            camera.zoom = 1.0f;
            camera.target = { WINDOW_START_WIDTH / 2,WINDOW_START_HEIGHT / 2 };
            //update
            ui.UpdateGameoverUi();
            BeginMode2D(camera);
            //draw
            EndMode2D();
            ui.DrawGameoverUi();
            EndDrawing();
            break;
        case GAMESTATE_SHOPPING:
            camera.zoom = 1.0f;
            if (IsKeyReleased(KEY_ENTER)) {
                ToggleFullscreen();
            }
            camera.target = { WINDOW_START_WIDTH / 2 ,WINDOW_START_HEIGHT / 2 };
            shop.Update();
            ui.UpdateShopUi();
            BeginMode2D(camera);
            shop.Draw();
            EndMode2D();
            ui.DrawShopUi();
            EndDrawing();
            break;
        case GAMESTATE_SETTING:
            camera.zoom = 1.0f;
            camera.target = { WINDOW_START_WIDTH / 2,WINDOW_START_HEIGHT / 2 };
            //update
            ui.UpdateOptionUi();
            BeginMode2D(camera);
            //draw
            EndMode2D();
            ui.DrawOptionUi();
            EndDrawing();
            break;
        case GAMESTATE_CREDIT:
            camera.zoom = 1.0f;
            camera.target = { WINDOW_START_WIDTH / 2,WINDOW_START_HEIGHT / 2 };
            //update
            ui.UpdateCreditUi();
            BeginMode2D(camera);
            //draw
            EndMode2D();
            ui.DrawCreditUi();
            EndDrawing();
            break;
        case GAMESTATE_CLEAR:
            camera.zoom = 1.0f;
            camera.target = { WINDOW_START_WIDTH / 2,WINDOW_START_HEIGHT / 2 };
            //update
            ui.UpdateClearUi();
            BeginMode2D(camera);
            //draw
            EndMode2D();
            ui.DrawClearUi();
            EndDrawing();
            break;
        }


       
    }

    CloseWindow();
    return 0;
}

