#include "library.h"

GameTitle::GameTitle() {
    game_start_button = { 100, 100, 200, 50 };
    game_setting_button = { 100, 200, 200, 50 };
    game_exit_button = { 100, 300, 200, 50 };
}
void GameTitle::ButtonUpdate() {
    if (CheckCollisionPointRec(GetMousePosition(), game_start_button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        currentState = GAME_START;
    }

    if (CheckCollisionPointRec(GetMousePosition(), game_setting_button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        State current;
        currentState = SETTING;
    }

    if (CheckCollisionPointRec(GetMousePosition(), game_exit_button) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        State current;
        currentState = EXIT;
    }
    
    
    }
