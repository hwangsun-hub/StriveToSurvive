#include "library.h"

Player::Player(Camera2D _camera) : camera(_camera){
    SetWeapon(TEST_MELEE_WEAPON);
}

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
        position.x += delta_position.x;
        position.y += delta_position.y;
    }
}
void Player::Attack() {
    if (GetWeapon() == TEST_MELEE_WEAPON) {

    }
}
void Player::Dodge() {}
void Player::Skill() {}
void Player::Draw(){
    //player sprite
    if (isstanding) {
        //sprite timer
        standing_sprite_timer.SetTimer(0.1f);
        standing_sprite_timer.UpdateTimer();
        if (standing_sprite_timer.TimerDone()) {
            standing_sprite_index++;
            if (standing_sprite_index == PLAYER_STANDING_SPRITE_MAXNUM) {
                standing_sprite_index = 0;
            }
        }
        //draw
        //flip : float(islookingright ? 1 : -1)
        DrawTexturePro(
            standing_sprite,
            { SPRITE_SIZE * float(standing_sprite_index), 0, SPRITE_SIZE * float(islookingright ? 1 : -1), SPRITE_SIZE},
            { 0, 0, IN_GAME_SPRITE_SIZE , IN_GAME_SPRITE_SIZE},
            { IN_GAME_SPRITE_SIZE / 2 - position.x , IN_GAME_SPRITE_SIZE / 2 - position.y },
            0,
            WHITE
        );
    }
    else {
        //sprite timer
        walking_sprite_timer.SetTimer(0.1f);
        walking_sprite_timer.UpdateTimer();
        if (walking_sprite_timer.TimerDone()) {
            walking_sprite_index++;
            if (walking_sprite_index == PLAYER_WALKING_SPRITE_MAXNUM) {
                walking_sprite_index = 0;
            }
        }
        //draw
        //flip : float(islookingright ? 1 : -1)
        DrawTexturePro(
            walking_sprite,
            { SPRITE_SIZE * float(walking_sprite_index), 0, SPRITE_SIZE * float(islookingright ? 1 : -1), SPRITE_SIZE },
            { 0, 0, IN_GAME_SPRITE_SIZE , IN_GAME_SPRITE_SIZE },
            { IN_GAME_SPRITE_SIZE / 2 - position.x , IN_GAME_SPRITE_SIZE / 2 - position.y },
            0,
            WHITE
        );
    }
    DrawWeapon();
    if (DEBUGING_MODE) {
        DrawSpawnPoint();
        DrawHitbox();
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
void Player::UpdateHitbox() {
    float degree = atan2f(GetMouseY() - WINDOW_START_HEIGHT / 2, GetMouseX() - WINDOW_START_WIDTH / 2);
    hitbox.x += GetDeltaPosition().x;
    hitbox.y += GetDeltaPosition().y;
    melee_attack_hitbox.x = hitbox.x + 100 * cosf(degree);
    melee_attack_hitbox.y = hitbox.y + 100 * sinf(degree);
    

}

void Player::Update() {
    Move();
    UpdateSpawnpoint();
    UpdateHitbox();

}

void Player::DrawSpawnPoint() {
    for (Vector2 position : spawnpoint) {
        DrawCircleV(position, 10, BLUE);
    }
}

void Player::DrawHitbox() {
    float degree = atan2f(GetMouseY() - WINDOW_START_HEIGHT / 2, GetMouseX() - WINDOW_START_WIDTH / 2);
    DrawRectangleLinesEx(hitbox, 2, RED);

    rlPushMatrix();
    rlTranslatef(melee_attack_hitbox.x + melee_attack_hitbox.width /2, melee_attack_hitbox.y + melee_attack_hitbox.height / 2, 0.0f);
    rlRotatef(degree * 180 / PI, 0, 0, 1.0f);
    rlTranslatef(-(melee_attack_hitbox.x + melee_attack_hitbox.width / 2), -(melee_attack_hitbox.y + melee_attack_hitbox.height / 2), 0.0f);
    DrawRectangleLinesEx(melee_attack_hitbox, 2, PURPLE);
    rlPopMatrix();
}

void Player::DrawWeapon() {
    DrawTexturePro(
        weapon_sprite,
        {
            weapon_sprite_source.x,
            weapon_sprite_source.y,
            weapon_sprite_source.width * float(GetMouseX() > WINDOW_START_WIDTH / 2 ? 1 : -1),
            weapon_sprite_source.height
        },
        weapon_sprite_dest,
        { weapon_sprite_orgin.x - position.x, weapon_sprite_orgin.y - position.y },
        0,
        WHITE
    );
}


