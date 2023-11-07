#include "library.h"
void Player::Move() {
    float moveX = 0;
    float moveY = 0;

    // Check for cross movement
    if (IsKeyDown(KEY_W)) {
        moveY -= 1;
    }
    if (IsKeyDown(KEY_S)) {
        moveY += 1;
    }
    if (IsKeyDown(KEY_A)) {
        moveX -= 1;
        islookingright = false;
    }
    if (IsKeyDown(KEY_D)) {
        moveX += 1;
        islookingright = true;
    }

    // Check for diagonal movement
    if (moveX != 0 && moveY != 0) {
        // Diagonal movement: adjust moveX and moveY
        moveX /= sqrtf(2);
        moveY /= sqrtf(2);
    }
    
    // Update the player's delta position
    delta_position = { moveX * speed , moveY * speed };

    // Check for movement
    if (moveX == 0 && moveY == 0) {
        isstanding = true;
    }
    else {
        isstanding = false;

        // Update the player's position
        position.x += moveX * speed;
        position.y += moveY * speed;
    }
}
void Player::Attack() {
  
}
void Player::Dodge() {}
void Player::Skill() {}
void Player::Draw(){
    if (isstanding) {
        DrawTexturePro(
            standing_sprite,
            { 0, 0, SPRITE_SIZE, SPRITE_SIZE },
            IN_GAME_SPRITE_SIZE,
            { IN_GAME_SPRITE_SIZE.width / 2 - position.x , IN_GAME_SPRITE_SIZE.height / 2 - position.y },
            0,
            WHITE
        );
    }
    else {
        DrawTexturePro(
            walking_sprite,
            { 0, 0, SPRITE_SIZE, SPRITE_SIZE },
            IN_GAME_SPRITE_SIZE,
            { IN_GAME_SPRITE_SIZE.width / 2 - position.x , IN_GAME_SPRITE_SIZE.height / 2 - position.y },
            0,
            WHITE
        );
    }
}


Vector2 Player::GetPosition() {
    return position;
}

Vector2 Player::GetDeltaPosition() {
    return delta_position;
}

void Player::UpdateSpawnpoint() {
    for (Vector2& position : spawnpoint) {
        position = Vector2Add(position, GetDeltaPosition());
    }
}

void Player::DrawSpawnPoint() {
    for (Vector2 position : spawnpoint) {
        DrawCircleV(position, 10, BLUE);
    }
}


