#include "library.h"

void GameTitle::Update() {
    //gametitle
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
}

void GameTitle::Draw() {
    DrawTexturePro(
        Game_Title_sprite,
        { WINDOW_START_WIDTH * float(game_title_sprite_vertical_index), WINDOW_START_HEIGHT * float(game_title_sprite_horizon_index), WINDOW_START_WIDTH, WINDOW_START_HEIGHT},
        { 0, 0, WINDOW_START_WIDTH , WINDOW_START_HEIGHT },
        { 0 , 0 },
        0,
        WHITE
    );
    for (int i = 0; i < buttons.size(); i++) {
        if (CheckCollisionPointRec(GetMousePosition(), buttons[i])) {
            DrawRectangleLinesEx(buttons[i], 2, BROWN);
        }
    }
   

}
