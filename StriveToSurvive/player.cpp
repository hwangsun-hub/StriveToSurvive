#include "library.h"

Player::Player(){
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
    std::cout << charge_attack_time << std::endl;
    if (charge_attack_time < 3) {
        charge_damage_coefficient = 1;
        charge_range_coefficient = 1;
        charge_attack_time += GetFrameTime();
    }
    else {
        for (int i = 0; i < sizeof(inventory_orb); i++) {
            if (inventory_orb[i] == UNCOMMON_CHARGEORB) {
                charge_range_coefficient = 2;
                charge_damage_coefficient = 2;
            }
        }
        if (GetWeapon() == RARE_KATANA_MASAMUNE) {
            charge_range_coefficient = 2;
            charge_damage_coefficient = 5;
        }
    }


    float degree = atan2f(GetMouseY() - GetWorldToScreen2D(position, camera).y, GetMouseX() - GetWorldToScreen2D(position, camera).x);
    switch (GetWeaponType(GetWeapon()))
    {
    case WeaponType::KATANA:
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isAttackReady) {
            charge_attack_time = 0;
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
            charge_attack_time = 0;
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
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isAttackReady) {
            charge_attack_time = 0;
            ranged_attack_hitboxs.push_back(
                { { position.x + cosf(degree) * 80, position.y + sinf(degree) * 80 },
                degree }
            );
            isAttackReady = false;
            isAttacking = true;
        }
       
        break;
    case WeaponType::SNIPERRIFLE:
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && isAttackReady) {
            charge_attack_time = 0;
            ranged_attack_hitboxs.push_back(
                { { position.x + cosf(degree) * 80, position.y + sinf(degree) * 80 },
                degree }
            );
            isAttackReady = false;
            isAttacking = true;
        }
        break;

    }

}

void Player::RangedAttack() {
    for (int i = 0; i < ranged_attack_hitboxs.size(); i++) {
        std::get<0>(ranged_attack_hitboxs[i]).x += RANGED_ATTACK_SPRITE_SPEED * cosf(std::get<1>(ranged_attack_hitboxs[i])) * GetFrameTime();
        std::get<0>(ranged_attack_hitboxs[i]).y += RANGED_ATTACK_SPRITE_SPEED * sinf(std::get<1>(ranged_attack_hitboxs[i])) * GetFrameTime();
        if (
            std::get<0>(ranged_attack_hitboxs[i]).x > position.x + WINDOW_START_WIDTH ||
            std::get<0>(ranged_attack_hitboxs[i]).x < position.x - WINDOW_START_WIDTH ||
            std::get<0>(ranged_attack_hitboxs[i]).y > position.y + WINDOW_START_HEIGHT ||
            std::get<0>(ranged_attack_hitboxs[i]).y < position.y - WINDOW_START_HEIGHT
            ) {
            ranged_attack_hitboxs.erase(ranged_attack_hitboxs.begin() + i);
        }
        
    }
}

void Player::Dodge() {
    if (GetWeapon() != WeaponId::RARE_KATANA_THUNDER) {
        if (IsKeyPressed(KEY_SPACE) && isDodgeReady) {
            isDodgeReady = false;
            position.x += delta_position.x * PLAYER_DODGE_SPEED;
            position.y += delta_position.y * PLAYER_DODGE_SPEED;
        }
    }
    else {
        if (IsKeyPressed(KEY_SPACE) && isDodgeReady) {
            dash_attack_sprite_index = 0;
            isDodgeReady = false;
            isDashAttacking = true;
            
        }
        if (isDashAttacking) {
            dash_attack_sprite_timer.SetTimer(0.05f);
            dash_attack_sprite_timer.UpdateTimer();
            if (dash_attack_sprite_timer.TimerDone()) {
                dash_attack_sprite_index++;
                if (dash_attack_sprite_index == MELEE_ATTACK_SPRITE_MAXNUM) {
                    isDashAttacking = false;
                }
            }
        }
        
    }
}

void Player::Kill() {
    killcount++;
    money += 10;
}

void Player::Buff() {
    switch (GetWeapon()) {
        case RARE_KATANA_STORMWIND:
            true_damage = (speed - PLAYER_SPEED > 0 ? int((speed - PLAYER_SPEED) / 10) : 0);
            break;
        case RARE_KATANA_MASAMUNE:
            //special
            damage = 85;
            attack_cooltime = 0.5f;
            break;
        case RARE_KATANA_MURAMASA:
            //special
            damage = 100;
            attack_cooltime = 0.5f;
            break;
        case UNCOMMON_GREATSWORD_BLOODSWORD:
            //special
            damage = 120;
            attack_cooltime = 1.0f;
            break;
        case RARE_GREATSWORD_BLACKKNIGHT:
            //special
            damage = 175;
            attack_cooltime = 0.75f;
            break;
        case RARE_GREATSWORD_WHITEKNIGHT:
            //special
            damage = 175;
            attack_cooltime = 0.75f;
            break;
        case RARE_GREATSWORD_VAMPIRE:
            //special
            damage = 150;
            attack_cooltime = 0.75f;
            drain_life_coefficient = 10;
            break;
        case RARE_GREATSWORD_BERSERKER:
            //special
            damage = 150;
            attack_cooltime = 0.75f;
            break;
        case RARE_MACHINEGUN_KRAKEN:
            //special
            damage = 40;
            attack_cooltime = 0.2f;
            break;
        case RARE_MACHINEGUN_VOID:
            //special
            damage = 35;
            attack_cooltime = 0.2f;
            break;
        case RARE_MACHINEGUN_REPENTENCE:
            //special
            damage = 50;
            attack_cooltime = 0.25f;
            break;
        case RARE_MACHINEGUN_WILD:
            //special
            damage = 80;
            attack_cooltime = 0.3f;
            break;
        case RARE_SNIPERRIFLE_RAILGUN:
            //special
            damage = 500;
            attack_cooltime = 2.0f;
            break;
        case RARE_SNIPERRIFLE_PIRACY:
            //special
            damage = 200;
            attack_cooltime = 1.0f;
            break;
        case RARE_SNIPERRIFLE_CATERPILLAR:
            //special
            damage = 80;
            attack_cooltime = 0.4f;
            break;
        case RARE_SNIPERRIFLE_MAGICENGINEERING:
            //special
            damage = 80;
            attack_cooltime = 0.4f;
            break;
        case NONE_WEAPON:
            break;
        default:
            break;
    }
}

void Player::Draw(){
    Color player_color;
    if (isInvincible) {
        player_color = { 255, 255, 255, 128 };
        if (isDamaged) {
            player_color = RED;
            isDamaged = false;
        }
    }
    else {
        player_color = WHITE;
    }
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
            player_color
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
            player_color
        );
    }
    DrawWeapon();
    DrawWeaponAttack();
    //hp bar
    DrawRectangleV({ position.x - 50, position.y + 60 }, { 100,10 }, WHITE);
    DrawRectangleV({ position.x - 50, position.y + 60 }, { float(hp) / float(500) * 100,10 }, GREEN);

    if (GetWeapon() == RARE_KATANA_THUNDER) {


    }

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
    spawnpoint[0] = { position.x, SPAWNPOINT_CIRCLE_RADIUS + position.y };
    spawnpoint[1] = { float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)) + position.x, float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)) + position.y };
    spawnpoint[2] = { SPAWNPOINT_CIRCLE_RADIUS + position.x, position.y };
    spawnpoint[3] = { float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)) + position.x, -float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)) + position.y };
    spawnpoint[4] = { position.x, -SPAWNPOINT_CIRCLE_RADIUS + position.y };
    spawnpoint[5] = { -float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)) + position.x, -float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)) + position.y };
    spawnpoint[6] = { -SPAWNPOINT_CIRCLE_RADIUS + position.x, position.y };
    spawnpoint[7] = { -float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)) + position.x, float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)) + position.y };

}
void Player::UpdateHitbox() {
    float degree = atan2f(GetMouseY() - GetWorldToScreen2D(position, camera).y, GetMouseX() - GetWorldToScreen2D(position, camera).x);
    hitbox.x = position.x - hitbox.width / 2;
    hitbox.y = position.y - hitbox.height / 2;

    melee_attack_hitbox.x = (hitbox.x + 80 * cosf(degree));
    melee_attack_hitbox.y = (hitbox.y + 80 * sinf(degree));

    melee_attack_spritebox.x = (hitbox.x + 100 * cosf(degree));
    melee_attack_spritebox.y = (hitbox.y + 100 * sinf(degree));

    

}

void Player::Update() {
    if (before_weaponid != GetWeapon()) {
        SetWeaponStat(GetWeapon());
    }

    speed = PLAYER_SPEED * speed_coefficient;

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

    //attack timer
    if (!isAttackReady) {
        attack_cooltimer.SetTimer(attack_cooltime * attack_cooltime_coefficient);
        attack_cooltimer.UpdateTimer();
    }
    if (attack_cooltimer.TimerDone()) {
        isAttackReady = true;
    }

    //dodge timer
    if (!isDodgeReady) {
        dodge_cooltimer.SetTimer(dodge_cooltime * dodge_cooltime_coefficient);
        dodge_cooltimer.UpdateTimer();
    }
    if (dodge_cooltimer.TimerDone()) {
        isDodgeReady = true;
    }

    //invincible timer
    if (isInvincible) {
        invincible_cooltimer.SetTimer(0.5);
        invincible_cooltimer.UpdateTimer();
    }
    if (invincible_cooltimer.TimerDone()) {
        isInvincible = false;
    }
    life_heal_cooltimer.SetTimer(1);
    life_heal_cooltimer.UpdateTimer();
    
    if (life_heal_cooltimer.TimerDone()) {
        hp += life_per_second;
    }

    Attack();
    RangedAttack();
    Move();
    Dodge();
    UpdateSpawnpoint();
    UpdateHitbox();
    before_weaponid = GetWeapon();

}

void Player::DrawSpawnPoint() {
    for (Vector2 position : spawnpoint) {
        DrawCircleV(position, 10, BLUE);
    }
}

void Player::DrawHitbox() {
    float degree = atan2f(GetMouseY() - GetWorldToScreen2D(position, camera).y, GetMouseX() - GetWorldToScreen2D(position, camera).x);
    DrawRectangleLinesEx(hitbox, 2, RED);
    DrawCircleLines(melee_attack_hitbox.x + hitbox.width/2, melee_attack_hitbox.y + hitbox.height/2, MELEE_ATTACK_HITBOX_SIZE * range_coefficient * charge_range_coefficient, RED);
    
    for (int i = 0; i < ranged_attack_hitboxs.size(); i++) {
        DrawCircleLines(std::get<0>(ranged_attack_hitboxs[i]).x, std::get<0>(ranged_attack_hitboxs[i]).y, RANGED_ATTACK_SPRITE_RADIUS * range_coefficient * charge_range_coefficient * 2, WHITE);
    }
}

void Player::DrawWeapon() {
    float degree = atan2f(GetMouseY() - GetWorldToScreen2D(position, camera).y, GetMouseX() - GetWorldToScreen2D(position, camera).x);
    bool x_flip = GetMouseX() > WINDOW_START_WIDTH / 2;
    bool y_flip = GetMouseY() > WINDOW_START_HEIGHT / 2;
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

        rlPushMatrix();

        rlTranslatef(position.x, position.y, 0);

        rlRotatef(degree * RAD2DEG , 0, 0, 1);
        DrawTexturePro(
            weapon_sprite,
            {
                weapon_sprite_source.x,
                weapon_sprite_source.y,
                weapon_sprite_source.width,
                weapon_sprite_source.height* float(x_flip ? 1 : -1)
            },
            weapon_sprite_dest,
            { 0, 0 },

            0,
            WHITE
        );
        rlPopMatrix();
        break;
    case SNIPERRIFLE:

        rlPushMatrix();

        rlTranslatef(position.x, position.y, 0);

        rlRotatef(degree * RAD2DEG, 0, 0, 1);
        DrawTexturePro(
            weapon_sprite,
            {
                weapon_sprite_source.x,
                weapon_sprite_source.y,
                weapon_sprite_source.width,
                weapon_sprite_source.height * float(x_flip ? 1 : -1)
            },
            weapon_sprite_dest,
            { 0, 0 },

            0,
            WHITE
        );
        rlPopMatrix();
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
                { melee_attack_spritebox.x + melee_attack_spritebox.width / 2, melee_attack_spritebox.y + melee_attack_spritebox.height / 2, melee_attack_spritebox.width * range_coefficient * charge_range_coefficient, melee_attack_spritebox.height * range_coefficient * charge_range_coefficient },
                { melee_attack_spritebox.width * range_coefficient * charge_range_coefficient / 2, melee_attack_spritebox.height * range_coefficient * charge_range_coefficient / 2 },
                atan2f(GetMouseY() - GetWorldToScreen2D(position, camera).y, GetMouseX() - GetWorldToScreen2D(position, camera).x)* RAD2DEG,
                WHITE
            );
        }
        if (isDashAttacking) {
            DrawTexturePro(
                katana_weapon_attack_sprite,
                { WEAPON_SPRITE_SIZE * float(dash_attack_sprite_index), 0, WEAPON_SPRITE_SIZE, WEAPON_SPRITE_SIZE },
                { melee_attack_spritebox.x + melee_attack_spritebox.width / 2, melee_attack_spritebox.y + melee_attack_spritebox.height / 2, melee_attack_spritebox.width * range_coefficient * charge_range_coefficient, melee_attack_spritebox.height * range_coefficient * charge_range_coefficient },
                { melee_attack_spritebox.width * range_coefficient * charge_range_coefficient / 2, melee_attack_spritebox.height * range_coefficient * charge_range_coefficient / 2 },
                atan2f(GetMouseY() - GetWorldToScreen2D(position, camera).y, GetMouseX() - GetWorldToScreen2D(position, camera).x) * RAD2DEG,
                YELLOW
            );
        }
        break;
    case GRAEATSWORD:
        if (isAttacking) {
            DrawTexturePro(
                katana_weapon_attack_sprite,
                { WEAPON_SPRITE_SIZE * float(melee_weapon_attack_sprite_index), 0, WEAPON_SPRITE_SIZE, WEAPON_SPRITE_SIZE },
                { melee_attack_spritebox.x + melee_attack_spritebox.width / 2, melee_attack_spritebox.y + melee_attack_spritebox.height / 2, melee_attack_spritebox.width * range_coefficient * charge_range_coefficient, melee_attack_spritebox.height * range_coefficient * charge_range_coefficient },
                { melee_attack_spritebox.width * range_coefficient * charge_range_coefficient / 2, melee_attack_spritebox.height * range_coefficient * charge_range_coefficient / 2 },
                atan2f(GetMouseY() - GetWorldToScreen2D(position, camera).y, GetMouseX() - GetWorldToScreen2D(position, camera).x) * RAD2DEG,
                WHITE
            );
        }
        break;
    default:
        break;
    }

    for (int i = 0; i < ranged_attack_hitboxs.size(); i++) {
        DrawTexturePro(
            ranged_weapon_attack_sprite,
            { 0,0,WEAPON_SPRITE_SIZE / 2, WEAPON_SPRITE_SIZE / 2 },
            { std::get<0>(ranged_attack_hitboxs[i]).x - (WEAPON_SPRITE_SIZE / 2 * range_coefficient * charge_range_coefficient * 2)/2, std::get<0>(ranged_attack_hitboxs[i]).y - (WEAPON_SPRITE_SIZE / 2 * range_coefficient * charge_range_coefficient * 2) / 2, WEAPON_SPRITE_SIZE / 2 * range_coefficient * charge_range_coefficient * 2, WEAPON_SPRITE_SIZE / 2 * range_coefficient * charge_range_coefficient * 2 },
            { 0,0 },
            0,
            WHITE
        );

    }
}

float Player::GetDamage() {
    return damage * damage_coefficient * charge_damage_coefficient;
}


bool Player::GetisAttacking() {
    return isAttacking;
}

bool Player::GetisDodging() {
    return !isDodgeReady;
}

Rectangle Player::GetHitbox() {
    return hitbox;
}

int Player::GetMoney() {
    return money;
}

int Player::GetKillcount() {
    return killcount;
}

void Player::SetMoney(int _money) {
    money = _money;
}


std::tuple<OrbId, OrbId, OrbId> Player::GetInventoryOrb() {
    return std::tuple<OrbId, OrbId, OrbId>(inventory_orb[0], inventory_orb[1], inventory_orb[2]);
}

void Player::SetInventoryOrb(OrbId _orbid) {
    for (int i = 0; i < sizeof(inventory_orb); i++) {
        if (inventory_orb[i] == NONE_ORB) {
            inventory_orb[i] = _orbid;
            SetOrbStat(_orbid);
            break;
        }
    }
}

void Player::RemoveInventoryOrb(OrbId _orbid) {
    for (int i = 0; i < sizeof(inventory_orb); i++) {
        if (inventory_orb[i] == _orbid) {
            inventory_orb[i] = NONE_ORB;
            DesetOrbStat(_orbid);
            break;
        }
    }
}

void Player::SetWeaponStat(WeaponId _weaponid) {
    switch (_weaponid)
    {
    case COMMON_KATANA_KATANA:
        damage = 20;
        attack_cooltime = 0.5f;
        break;
    case UNCOMMON_KATANA_TAILWIND:
        damage = 30;
        true_damage = 10;
        attack_cooltime = 0.3f;
        break;
    case UNCOMMON_KATANA_ZERO:
        damage = 60;
        attack_cooltime = 0.5f;
        break;
    case RARE_KATANA_STORMWIND:
        //special
        damage = 40;
        attack_cooltime = 0.3f;
        break;
    case RARE_KATANA_THUNDER:
        //special
        damage = 60;
        attack_cooltime = 0.3f;
        break;
    case RARE_KATANA_MASAMUNE:
        //special
        damage = 85;
        attack_cooltime = 0.5f;
        break;
    case RARE_KATANA_MURAMASA:
        //special
        damage = 100;
        attack_cooltime = 0.5f;
        break;
    case COMMON_GREATSWORD_GREATSWORD:
        damage = 50;
        attack_cooltime = 1.0f;
        break;
    case UNCOMMON_GREATSWORD_KNIGHTLYSWORD:
        damage = 150;
        attack_cooltime = 1.0f;
        break;
    case UNCOMMON_GREATSWORD_BLOODSWORD:
        //special
        damage = 120;
        attack_cooltime = 1.0f;
        break;
    case RARE_GREATSWORD_BLACKKNIGHT:
        //special
        damage = 175;
        attack_cooltime = 0.75f;
        break;
    case RARE_GREATSWORD_WHITEKNIGHT:
        //special
        damage = 175;
        attack_cooltime = 0.75f;
        break;
    case RARE_GREATSWORD_VAMPIRE:
        //special
        damage = 150;
        attack_cooltime = 0.75f;
        drain_life_coefficient = 10;
        break;
    case RARE_GREATSWORD_BERSERKER:
        //special
        damage = 150;
        attack_cooltime = 0.75f;
        break;
    case COMMON_MACHINEGUN_MACHINGUN:
        damage = 20;
        attack_cooltime = 0.3f;
        break;
    case UNCOMMON_MACHINEGUN_LIGHTMACHINEGUN:
        damage = 35;
        attack_cooltime = 0.2f;
        break;
    case UNCOMMON_MACHINEGUN_HEAVYMACHINEGUN:
        damage = 50;
        attack_cooltime = 0.3f;
        break;
    case RARE_MACHINEGUN_KRAKEN:
        //special
        damage = 40;
        attack_cooltime = 0.2f;
        break;
    case RARE_MACHINEGUN_VOID:
        //special
        damage = 35;
        attack_cooltime = 0.2f;
        break;
    case RARE_MACHINEGUN_REPENTENCE:
        //special
        damage = 50;
        attack_cooltime = 0.25f;
        break;
    case RARE_MACHINEGUN_WILD:
        //special
        damage = 80;
        attack_cooltime = 0.3f;
        break;
    case COMMON_SNIPERRIFLE_SNIPERRIFLE:
        damage = 40;
        attack_cooltime = 0.6f;
        break;
    case UNCOMMON_SNIPERRIFLE_BOLTACTION:
        damage = 100;
        attack_cooltime = 0.6f;
        break;
    case UNCOMMON_SNIPERRIFLE_SEMIAUTO:
        damage = 75;
        attack_cooltime = 0.45f;
        break;
    case RARE_SNIPERRIFLE_RAILGUN:
        //special
        damage = 500;
        attack_cooltime = 2.0f;
        break;
    case RARE_SNIPERRIFLE_PIRACY:
        //special
        damage = 200;
        attack_cooltime = 1.0f;
        break;
    case RARE_SNIPERRIFLE_CATERPILLAR:
        //special
        damage = 80;
        attack_cooltime = 0.4f;
        break;
    case RARE_SNIPERRIFLE_MAGICENGINEERING:
        //special
        damage = 80;
        attack_cooltime = 0.4f;
        break;
    case NONE_WEAPON:
        break;
    default:
        break;
    }
}

void Player::SetOrbStat(OrbId _orbid) {
    switch (_orbid)
    {
    case COMMON_LIFEORB:
        life_per_second++;
        break;
    case COMMON_IRONORB:
        defense += 10;
        break;
    case COMMON_SPRINGORB:
        knockback_coefficient += 0.5f;
        break;
    case COMMON_ANGERORB:
        damage_coefficient += 0.25f;
        break;
    case COMMON_WATERORB:
        attack_cooltime_coefficient += 0.25f;
        break;
    case COMMON_BLOODORB:
        drain_life_coefficient += 0.02f;
        break;
    case COMMON_WINDORB:
        speed_coefficient += 0.25f;
        break;
    case COMMON_RANGEORB:
        range_coefficient += 0.25f;
        break;
    case UNCOMMON_ARMORORB:
        true_defense += 5;
        life_per_second += 2;
        defense += 20;
        break;
    case UNCOMMON_TRANSFUSIONORB:
        life_per_second += 3;
        drain_life_coefficient += 3;
        break;
    case UNCOMMON_ROARORB:
        //special
        knockback_coefficient += 0.5;
        range_coefficient += 0.25;
        break;
    case UNCOMMON_RAGEORB:
        //special
        damage_coefficient += 0.3;
        attack_cooltime_coefficient += 0.3;
        break;
    case UNCOMMON_SEAORB:
        //special
        speed_coefficient += 0.3;
        attack_cooltime_coefficient += 0.3;
        break;
    case UNCOMMON_HUNGERORB:
        //special
        drain_life_coefficient += 4;
        break;
    case UNCOMMON_SWIFTNESSORB:
        dodge_cooltime_coefficient -= 0.5;
        speed_coefficient += 1.65;
        break;
    case UNCOMMON_CHARGEORB:
        //special
        damage_coefficient += 0.3;
        range_coefficient += 0.3;
        break;
    case NONE_ORB:
        break;
    default:
        break;
    }
}

void Player::DesetOrbStat(OrbId _orbid) {
    switch (_orbid)
    {
    case COMMON_LIFEORB:
        life_per_second--;
        break;
    case COMMON_IRONORB:
        defense -= 10;
        break;
    case COMMON_SPRINGORB:
        knockback_coefficient -= 0.5f;
        break;
    case COMMON_ANGERORB:
        damage_coefficient -= 0.25f;
        break;
    case COMMON_WATERORB:
        attack_cooltime_coefficient -= 0.25f;
        break;
    case COMMON_BLOODORB:
        drain_life_coefficient -= 0.02f;
        break;
    case COMMON_WINDORB:
        speed_coefficient -= 0.25f;
        break;
    case COMMON_RANGEORB:
        range_coefficient -= 0.25f;
        break;
    case UNCOMMON_ARMORORB:
        true_defense -= 5;
        life_per_second -= 2;
        defense -= 20;
        break;
    case UNCOMMON_TRANSFUSIONORB:
        life_per_second -= 3;
        drain_life_coefficient -= 3;
        break;
    case UNCOMMON_ROARORB:
        //special
        knockback_coefficient -= 0.5;
        range_coefficient -= 0.25;
        break;
    case UNCOMMON_RAGEORB:
        //special
        damage_coefficient -= 0.3;
        attack_cooltime_coefficient -= 0.3;
        break;
    case UNCOMMON_SEAORB:
        //special
        speed_coefficient -= 0.3;
        attack_cooltime_coefficient -= 0.3;
        break;
    case UNCOMMON_HUNGERORB:
        //special
        drain_life_coefficient -= 4;
        break;
    case UNCOMMON_SWIFTNESSORB:
        dodge_cooltime_coefficient += 0.5;
        speed_coefficient -= 1.65;
        break;
    case UNCOMMON_CHARGEORB:
        //special
        damage_coefficient -= 0.3;
        range_coefficient -= 0.3;
        break;
    case NONE_ORB:
        break;
    default:
        break;
    }
}

int Player::GetHp() {
    return hp;
}

float Player::GetTrueDamage() {
    return true_damage;
}

void Player::Damaged(float enemy_damage) {
    if (!isInvincible) {
        hp -= enemy_damage * 100 / (100 + defense);
        isInvincible = true;
        isDamaged = true;
    }
}



