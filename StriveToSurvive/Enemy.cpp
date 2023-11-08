#include "library.h"

Enemy::Enemy(Player* _player) : player(_player) {
	position = player->spawnpoint[rand() % 8];
}
Enemy::~Enemy() {
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

void Enemy::Damaged() {
	hp -= player->GetDamage();
	//knockback
	position.x -= ENEMY_KNONKBACK * delta_position.x;
	position.y -= ENEMY_KNONKBACK * delta_position.y;
	hitbox.x -= ENEMY_KNONKBACK * delta_position.x;
	hitbox.y -= ENEMY_KNONKBACK * delta_position.y;
}
void Enemy::UpdateState() {
	if (
		player->GetisAttacking() &&
		IsMouseButtonPressed(MOUSE_BUTTON_LEFT) &&
		CheckCollisionCircleRec({ player->melee_attack_hitbox.x + hitbox.width / 2,  player->melee_attack_hitbox.y + hitbox.height / 2}, MELEE_ATTACK_HITBOX_SIZE, hitbox)) {
		Damaged();
	}
}


void Enemy::Update() {
	ChasePlayer();
	UpdateHitbox();
	UpdateState();
}

void Enemy::DrawHitbox() {
	DrawRectangleLinesEx(hitbox, 2, RED);
}

void Enemy::DrawhpBar() {
	DrawRectangleV({ position.x - 50, position.y + 30 }, { 100,10 }, WHITE);
	DrawRectangleV({ position.x-50, position.y+30 }, { float(hp),10 }, GREEN);
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
	DrawhpBar();
}


Vector2 Enemy::GetPosition() {
	return position;
}

Vector2 Enemy::GetDeltaPosition() {
	return delta_position;
}

int Enemy::Gethp() {
	return hp;
}

