#include "library.h"

Enemy::Enemy(Player* _player) : player(_player) {
	position = player->spawnpoint[rand() % 8];
}

void Enemy::ChasePlayer() {
	if (isPlayerFollowType) {
		delta_position = {
			speed * cos(atan2f((player->GetPosition().y - position.y), (player->GetPosition().x - position.x))),
			speed * sin(atan2f((player->GetPosition().y - position.y), (player->GetPosition().x - position.x)))
		};
		position.x += delta_position.x;
		position.y += delta_position.y;
	}
}

void Enemy::UpdateHitbox() {
	hitbox.x += GetDeltaPosition().x;
	hitbox.y += GetDeltaPosition().y;
}

void Enemy::Update() {
	ChasePlayer();
	UpdateHitbox();
}

void Enemy::DrawHitbox() {
	DrawRectangleLinesEx(hitbox, 2, RED);
}


void Enemy::Draw() {
	//sprite timer
	sprite_timer.SetTimer(0.1f);
	sprite_timer.UpdateTimer();
	if (sprite_timer.TimerDone()) {
		sprite_index++;
		if (sprite_index == sprite_index_maxnum) {
			sprite_index = 0;
		}
	}
	//draw
	DrawTexturePro(
		sprite,
		{ SPRITE_SIZE * float(sprite_index), 0, SPRITE_SIZE, SPRITE_SIZE },
		{0, 0, IN_GAME_SPRITE_SIZE, IN_GAME_SPRITE_SIZE },
		{ IN_GAME_SPRITE_SIZE / 2 - position.x , IN_GAME_SPRITE_SIZE / 2 - position.y },
		0,
		WHITE
	);
	if (DEBUGING_MODE) {
		DrawHitbox();
	}
}


Vector2 Enemy::GetPosition() {
	return position;
}

Vector2 Enemy::GetDeltaPosition() {
	return delta_position;
}
