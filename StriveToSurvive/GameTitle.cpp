#include "library.h"

Camera2D camera;

void GameTitle::Update() {
    //gametitle
    if (isDigiPenLogoEnd) {
        game_title_timer.SetTimer(0.15);
        game_title_timer.UpdateTimer();
        if (game_title_timer.TimerDone()) {
            game_title_sprite_vertical_index++;
            if (game_title_sprite_vertical_index == GAME_TITLE_SPRITE_VERTICAL_MAXNUM) {
                game_title_sprite_vertical_index = 0;
                game_title_sprite_horizon_index++;
                if (game_title_sprite_horizon_index == GAME_TITLE_SPRITE_HORIZON_MAXNUM) {
                    game_title_sprite_horizon_index = 0;
                }
            }
        }

        //button
        for (int i = 0; i < buttons.size(); i++) {
            if (CheckCollisionPointRec(GetMousePosition(), buttons[i]) && IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                switch (i)
                {
                    //start button
                case 0:
                    gamestate = GAMESTATE_BEFORE_GAME;
                    break;
                    //option button
                case 1:
                    gamestate = GAMESTATE_SETTING;
                    break;
                    //credit button
                case 2:
                    gamestate = GAMESTATE_CREDIT;
                    break;
                    //quit button
                case 3:
                    exitWindow = true;
                    break;
                }
            }
        }
    }
    else if(!isDigiPenLogoEnd){
        digipen_logo_timer.SetTimer(3);
        digipen_logo_timer.UpdateTimer();
        if (digipen_logo_timer.TimerDone()) {
            isDigiPenLogoEnd = true;
            UnloadTexture(DigiPen_logo_sprite);
        }
    }
}

void GameTitle::Draw() {
    if (isDigiPenLogoEnd) {
        DrawTexturePro(
            Game_Title_sprite,
            { WINDOW_START_WIDTH * float(game_title_sprite_vertical_index), WINDOW_START_HEIGHT * float(game_title_sprite_horizon_index), WINDOW_START_WIDTH, WINDOW_START_HEIGHT },
            { 0, 0, WINDOW_START_WIDTH , WINDOW_START_HEIGHT },
            { 0 , 0 },
            0,
            WHITE
        );
        for (int i = 0; i < buttons.size(); i++) {
            if (CheckCollisionPointRec(GetMousePosition(), buttons[i])) {
                DrawRectangleLinesEx(buttons[i], 2, {189, 32, 49, 255});
            }
        }
    }
    else if (!isDigiPenLogoEnd) {
        DrawTexturePro(
            DigiPen_logo_sprite,
            { 0, 0, WINDOW_START_WIDTH, WINDOW_START_HEIGHT },
            { 0, 0, WINDOW_START_WIDTH , WINDOW_START_HEIGHT },
            { 0 , 0 },
            0,
            WHITE
        );
    }
   

}
