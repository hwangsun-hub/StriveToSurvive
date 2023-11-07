#include "library.h"

Enemy::Enemy(Player* _player) : player(_player) {
	position = player->spawnpoint[rand() % 8];
}

void Enemy::ChasePlayer() {
	if (isPlayerFollowType) {
		position.x += speed * cos(atan2f((player->GetPosition().y - position.y), (player->GetPosition().x - position.x)));
		position.y += speed * sin(atan2f((player->GetPosition().y - position.y), (player->GetPosition().x - position.x)));
	}
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
}


Vector2 Enemy::GetPosition() {
	return position;
}