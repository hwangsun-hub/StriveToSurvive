#include "library.h"

Player::Player(Camera2D _camera) : camera(_camera){
    SetWeapon(COMMON_KATANA_KATANA);
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
    
     delta_position = { moveX * speed * GetFrameTime() , moveY * speed * GetFrameTime() };
    

    // Check for movement
    if (moveX == 0 && moveY == 0) {
        isstanding = true;
        walking_sprite_timer.SetTimer(0);
    }
    else {
        isstanding = false;
        standing_sprite_timer.SetTimer(0);

        // Update the player's position
        position.x += delta_position.x;
        position.y += delta_position.y;
    }
}
void Player::Attack() {
    if (GetisWeaponTypeMelee()) {
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isAttackReady) {
            melee_weapon_attack_sprite_index = 0;
            isAttackReady = false;
            isAttacking = true;
        }
        if (isAttacking) {
            melee_weapon_attack_sprite_timer.SetTimer(0.05f);
            melee_weapon_attack_sprite_timer.UpdateTimer();
            if (melee_weapon_attack_sprite_timer.TimerDone()) {
                melee_weapon_attack_sprite_index++;
                if (melee_weapon_attack_sprite_index == MELEE_ATTACK_SPRITE_MAXNUM) {
                    isAttacking = false;
                }
            }
        }

    }
    else if (!GetisWeaponTypeMelee()) {

    }
}
void Player::Dodge() {}
void Player::Skill() {}
void Player::Kill() {}
void Player::Draw(){
    //player sprite
    if (isstanding) {
        //sprite timer
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
            { WEAPON_SPRITE_SIZE * float(standing_sprite_index), 0, WEAPON_SPRITE_SIZE * float(islookingright ? 1 : -1), WEAPON_SPRITE_SIZE},
            { 0, 0, IN_GAME_SPRITE_SIZE , IN_GAME_SPRITE_SIZE},
            { IN_GAME_SPRITE_SIZE / 2 - position.x , IN_GAME_SPRITE_SIZE / 2 - position.y },
            0,
            WHITE
        );
    }
    else {
        //sprite timer
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
            { WEAPON_SPRITE_SIZE * float(walking_sprite_index), 0, WEAPON_SPRITE_SIZE * float(islookingright ? 1 : -1), WEAPON_SPRITE_SIZE },
            { 0, 0, IN_GAME_SPRITE_SIZE , IN_GAME_SPRITE_SIZE },
            { IN_GAME_SPRITE_SIZE / 2 - position.x , IN_GAME_SPRITE_SIZE / 2 - position.y },
            0,
            WHITE
        );
    }
    DrawWeapon();
    DrawWeaponAttack();

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
        position = { position.x + GetDeltaPosition().x, position.y + GetDeltaPosition().y };
    }
}
void Player::UpdateHitbox() {
    float degree = atan2f(GetMouseY() - WINDOW_START_HEIGHT / 2, GetMouseX() - WINDOW_START_WIDTH / 2);
    hitbox.x += GetDeltaPosition().x;
    hitbox.y += GetDeltaPosition().y;
    melee_attack_hitbox.x = hitbox.x + 80 * cosf(degree);
    melee_attack_hitbox.y = hitbox.y + 80 * sinf(degree);
    melee_attack_spritebox.x = hitbox.x + 100 * cosf(degree);
    melee_attack_spritebox.y = hitbox.y + 100 * sinf(degree);
    

}

void Player::Update() {
    if (isstanding) {
        //sprite timer
        standing_sprite_timer.SetTimer(0.1f);
        standing_sprite_timer.UpdateTimer();
    }
    else {
        //sprite timer
        walking_sprite_timer.SetTimer(0.1f);
        walking_sprite_timer.UpdateTimer();
    }
    if (!isAttackReady) {
        attack_cooltimer.SetTimer(attack_cooltime);
        attack_cooltimer.UpdateTimer();
    }
    if (attack_cooltimer.TimerDone()) {
        isAttackReady = true;
    }
    Attack();
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
    DrawCircleLines(melee_attack_hitbox.x+ hitbox.width/2, melee_attack_hitbox.y+ hitbox.height / 2, MELEE_ATTACK_HITBOX_SIZE, RED);
}

void Player::DrawWeapon() {
    DrawTexturePro(
        weapon_sprite,
        {
            weapon_sprite_source.x,
            weapon_sprite_source.y,
            weapon_sprite_source.width * float(islookingright ? 1 : -1),
            weapon_sprite_source.height
        },
        weapon_sprite_dest,
        { weapon_sprite_orgin.x - position.x, weapon_sprite_orgin.y - position.y },
        0,
        WHITE
    );
}
void Player::DrawWeaponAttack() {
    if (isAttacking) {
        DrawTexturePro(
            melee_weapon_attack_sprite,
            { WEAPON_SPRITE_SIZE * float(melee_weapon_attack_sprite_index), 0, WEAPON_SPRITE_SIZE, WEAPON_SPRITE_SIZE },
            { melee_attack_spritebox.x + melee_attack_spritebox.width / 2, melee_attack_spritebox.y + melee_attack_spritebox.height / 2, melee_attack_spritebox.width, melee_attack_spritebox.height },
            { melee_attack_spritebox.width / 2, melee_attack_spritebox.height / 2 },
            atan2f(GetMouseY() - WINDOW_START_HEIGHT / 2, GetMouseX() - WINDOW_START_WIDTH / 2) * RAD2DEG,
            WHITE
        );
    }
}

float Player::GetDamage() {
    return damage;
}

bool Player::GetisAttacking() {
    return isAttacking;
}

Rectangle Player::GetHitbox() {
    return hitbox;
}

int Player::GetMoney() {
    return money;
}

void Player::SetMoney(int _money) {
    money = _money;
}



