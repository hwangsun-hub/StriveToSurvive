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
        moveX /= sqrt(2);
        moveY /= sqrt(2);
    }
    
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
void Player::Shoot() {

}
void Player::Dodge() {}
void Player::Skill() {}
void Player::Draw(){
    DrawTexture(standing_sprite, position.x, position.y, WHITE);
}


void Player::Update() {
    Move();
    Draw();

}
Vector2 Player::GetPosition() {
    return position;
}

