#include "library.h"
void Player::Move() {
    int moveX = 0;
    int moveY = 0;

    // Check for cross movement
    if (IsKeyDown(KEY_W)) {
        moveY += 1;
    }
    if (IsKeyDown(KEY_S)) {
        moveY -= 1;
    }
    if (IsKeyDown(KEY_A)) {
        moveX -= 1;
    }
    if (IsKeyDown(KEY_D)) {
        moveX += 1;
    }

    // Check for diagonal movement
    if (moveX != 0 && moveY != 0) {
        // Diagonal movement: adjust moveX and moveY
        moveX *= speed / sqrt(2);
        moveY *= speed / sqrt(2);
    }

    // Update the player's position
    position.x += moveX * speed;
    position.y += moveY * speed;
}


void Player::Update() {}
Vector2 Player::GetPosition() {
    return position;
}

