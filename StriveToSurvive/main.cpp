#include "library.h"

bool DEBUGING_MODE = false;
bool exitWindow = false;

int wave_level = 1;
int talent_score = 5;
bool isMenuReady = false;
GameState before_gamestate = GAMESTATE_TITLE;


//defalt : GAMESTATE_TITLE
GameState gamestate = GAMESTATE_TITLE;


int main()
{
    srand(unsigned int(time(NULL)));
    InitWindow(WINDOW_START_WIDTH, WINDOW_START_HEIGHT, WINDOW_NAME);
    InitAudioDevice();
    SetTargetFPS(WINDOW_FRAMES_PER_SECOND);

    Music ingame_music1 = LoadMusicStream("resources/music/normal1.mp3");
    Music ingame_music2 = LoadMusicStream("resources/music/spider.wav");
    Music ingame_music3 = LoadMusicStream("resources/music/Bottomless_Knight.mp3");
    Music title_music = LoadMusicStream("resources/music/menu2.mp3");
    Music shop_music = LoadMusicStream("resources/music/menu2.mp3");
    Music gameover_music = LoadMusicStream("resources/music/gameover.mp3");
    SetMusicVolume(ingame_music1, 0.3f);
    SetMusicVolume(ingame_music2, 0.5f);
    SetMusicVolume(ingame_music3, 0.5f);
    SetMusicVolume(title_music, 0.7f);
    SetMusicVolume(shop_music, 0.7f);
    SetMusicVolume(gameover_music, 0.5f);

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
    float zoom = 0.75;

    while (!WindowShouldClose() && !exitWindow) {


        BeginDrawing();
        ClearBackground(BLACK);
        //update
        switch (gamestate)
        {
        case GAMESTATE_TITLE:
            camera.zoom = 1.0f;
            camera.target = { WINDOW_START_WIDTH / 2 ,WINDOW_START_HEIGHT / 2 };
            if (isMenuReady) {
                PlayMusicStream(title_music);
                UpdateMusicStream(title_music);

            }
            gametitle.Update();
            BeginMode2D(camera);
            gametitle.Draw();
            EndMode2D();
            EndDrawing();
            break;
        case GAMESTATE_BEFORE_GAME:
            camera.zoom = 1.0f;
            camera.target = { WINDOW_START_WIDTH/2,WINDOW_START_HEIGHT/2 };
            if (before_gamestate != gamestate) {
                StopMusicStream(title_music);
            }
            //update
            ui.UpdateBeforeGameUi();
            BeginMode2D(camera);
            //draw
            EndMode2D();
            ui.DrawBeforeGameUi();
            EndDrawing();
            break;
        case GAMESTATE_INGAME:
            camera.zoom = zoom;
            //update
            if (wave_level < 7) {
                PlayMusicStream(ingame_music1);
                UpdateMusicStream(ingame_music1);

            }
            else if (wave_level == 7 || wave_level == 8) {
                PlayMusicStream(ingame_music2);
                UpdateMusicStream(ingame_music2);

            }
            else if (wave_level == 9 || wave_level == 10) {
                PlayMusicStream(ingame_music3);
                UpdateMusicStream(ingame_music3);

            }
            camera.target = Vector2Lerp(camera.target, player.GetPosition(), 7 * GetFrameTime());
            player.Update();
            wavemanager.Update();
            tilemap.Update();
            ui.UpdateIngameUi();
            BeginMode2D(camera);
            //debug mode toggle (KEY_F5)
            if (IsKeyReleased(KEY_F5)) {
                DEBUGING_MODE = !DEBUGING_MODE;
                zoom = 0.75f;
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
                if (IsKeyReleased(KEY_F4)) {
                    player.Cheat();
                }
                if (IsKeyReleased(KEY_F6)) {
                    wave_level++;
                    if (wave_level == 11) {
                        wave_level = 10;
                    }
                }
                if (IsKeyReleased(KEY_F7)) {
                    zoom = 0.25;
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
            PlayMusicStream(gameover_music);
            UpdateMusicStream(gameover_music);

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
            PlayMusicStream(shop_music);
            UpdateMusicStream(shop_music);

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
        if (before_gamestate != gamestate) {
            StopMusicStream(ingame_music1);
            StopMusicStream(ingame_music2);
            StopMusicStream(ingame_music3);
            StopMusicStream(title_music);
            StopMusicStream(shop_music);
            StopMusicStream(gameover_music);
        }

        before_gamestate = gamestate;
    }

    CloseWindow();
    return 0;
}

