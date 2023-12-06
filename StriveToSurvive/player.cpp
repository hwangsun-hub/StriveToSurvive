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
    switch (GetWeaponType(GetWeapon()))
    {
    case WeaponType::KATANA:
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
        break;
    case WeaponType::GRAEATSWORD:
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isAttackReady) {
            greatsword_motion = !greatsword_motion;
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
        break;
    case WeaponType::MACHINGUN:
        break;
    case WeaponType::SNIPERRIFLE:
        break;

    }
}
void Player::Dodge() {}
void Player::Skill() {}
void Player::Kill() {
    killcount++;
    money += 10;
}
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
    if (IsKeyDown(KEY_V)) {
        sex_x++;
        std::cout << "sex_x :" << sex_x << std::endl;
    }
    if (IsKeyDown(KEY_B)) {
        sex_y++;
        std::cout << "sex_y :" << sex_y << std::endl;
    }
    if (IsKeyDown(KEY_F)) {
        sex_x--;
        std::cout << "sex_x :" << sex_x << std::endl;
    }
    if (IsKeyDown(KEY_G)) {
        sex_y--;
        std::cout << "sex_y :" << sex_y << std::endl;
    }
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
    float degree = atan2f(GetMouseY() - WINDOW_START_HEIGHT / 2, GetMouseX() - WINDOW_START_WIDTH / 2) ;
    switch (GetWeaponType(GetWeapon()))
    {
    case KATANA:
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
    
        break;
    case GRAEATSWORD:

        rlPushMatrix();

        rlTranslatef(position.x, position.y,0);

        rlRotatef(degree * RAD2DEG + 40, 0, 0, 1);
        if (greatsword_motion) {
            rlTranslatef(weapon_sprite_dest.x + WEAPON_SPRITE_SIZE, weapon_sprite_dest.y+ float(WEAPON_SPRITE_SIZE * 1.5), 0);

            rlRotatef(80, 0, 0, 1);
        }
        DrawTexturePro(
            weapon_sprite,
            {
                weapon_sprite_source.x,
                weapon_sprite_source.y,
                weapon_sprite_source.width * float(islookingright ? 1 : -1),
                weapon_sprite_source.height
            },
            weapon_sprite_dest,
            { 0, 0 },

            0,
            WHITE
        );
        rlPopMatrix();
        break;
    case MACHINGUN:
        break;
    case SNIPERRIFLE:
        break;
    case NONE_TYPE:
        break;
    default:
        break;
    }

}
void Player::DrawWeaponAttack() {
    switch (GetWeaponType(GetWeapon()))
    {
    case KATANA:
        if (isAttacking) {
            DrawTexturePro(
                katana_weapon_attack_sprite,
                { WEAPON_SPRITE_SIZE * float(melee_weapon_attack_sprite_index), 0, WEAPON_SPRITE_SIZE, WEAPON_SPRITE_SIZE },
                { melee_attack_spritebox.x + melee_attack_spritebox.width / 2, melee_attack_spritebox.y + melee_attack_spritebox.height / 2, melee_attack_spritebox.width, melee_attack_spritebox.height },
                { melee_attack_spritebox.width / 2, melee_attack_spritebox.height / 2 },
                atan2f(GetMouseY() - WINDOW_START_HEIGHT / 2, GetMouseX() - WINDOW_START_WIDTH / 2) * RAD2DEG,
                WHITE
            );
        }
        break;
    case GRAEATSWORD:
        if (isAttacking) {
            DrawTexturePro(
                greatsword_weapon_attack_sprite,
                { WEAPON_SPRITE_SIZE * float(melee_weapon_attack_sprite_index), 0, WEAPON_SPRITE_SIZE, WEAPON_SPRITE_SIZE },
                { melee_attack_spritebox.x + melee_attack_spritebox.width / 2, melee_attack_spritebox.y + melee_attack_spritebox.height / 2, melee_attack_spritebox.width, melee_attack_spritebox.height },
                { melee_attack_spritebox.width / 2, melee_attack_spritebox.height / 2 },
                atan2f(GetMouseY() - WINDOW_START_HEIGHT / 2, GetMouseX() - WINDOW_START_WIDTH / 2) * RAD2DEG,
                WHITE
            );
        }
        break;
    case MACHINGUN:
        break;
    case SNIPERRIFLE:
        break;
    case NONE_TYPE:
        break;
    default:
        break;
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

WeaponId Player::GetInventoryMeleeWeapon() {
    return inventory_weapon[0];
}

void Player::SetInventoryMeleeWeapon(WeaponId _weaponid) {
    inventory_weapon[0] = _weaponid;
}

WeaponId Player::GetInventoryRangedWeapon() {
    return inventory_weapon[1];
}

void Player::SetInventoryRangedWeapon(WeaponId _weaponid) {
    inventory_weapon[1] = _weaponid;
}

std::tuple<OrbId, OrbId, OrbId> Player::GetInventoryOrb() {
    return std::tuple<OrbId, OrbId, OrbId>(inventory_orb[0], inventory_orb[1], inventory_orb[2]);
}

void Player::SetInventoryOrb(OrbId _orbid) {
    for (int i = 0; i < sizeof(inventory_orb); i++) {
        if (inventory_orb[i] != NONE_ORB) {
            inventory_orb[i] = _orbid;
            break;
        }
    }
}


