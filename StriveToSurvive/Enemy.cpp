#include "library.h"

Enemy::Enemy(Player* _player) : player(_player) {
	position = player->spawnpoint[rand() % 8];
}
Enemy::~Enemy() {
}

void Enemy::ChasePlayer() {
	if (isPlayerFollowType) {
		delta_position = {
			speed * cos(atan2f((player->GetPosition().y - position.y), (player->GetPosition().x - position.x))) * GetFrameTime(),
			speed * sin(atan2f((player->GetPosition().y - position.y), (player->GetPosition().x - position.x))) * GetFrameTime()
		};
		

	}
}

void Enemy::UpdateHitbox() {
	hitbox.x = GetPosition().x - hitbox.width / 2;
	hitbox.y = GetPosition().y - hitbox.height / 2;
}

void Enemy::Damaged() {
	hp -= player->GetDamage() * 100 / (100 + defence) + player->GetTrueDamage();
	Knockbacked();
}

void Enemy::RangedDamaged() {
	hp -= player->GetDamage() * 100 / (100 + defence) + player->GetTrueDamage();
}

void Enemy::Knockbacked() {
	delta_position.x = -ENEMY_KNOCKBACK * delta_position.x;
	delta_position.y = -ENEMY_KNOCKBACK * delta_position.y;
	isKnockback = true;
}


void Enemy::UpdateState() {
	if (player->GetWeaponType(player->GetWeapon()) == WeaponType::KATANA || player->GetWeaponType(player->GetWeapon()) == WeaponType::GRAEATSWORD) {
		if (player_attack != player->GetisAttacking() && player_attack == false) {
			if (
				CheckCollisionCircleRec({ player->melee_attack_hitbox.x + player->GetHitbox().width / 2,  player->melee_attack_hitbox.y + player->GetHitbox().height / 2 }, MELEE_ATTACK_HITBOX_SIZE * player->range_coefficient, hitbox)
				) {
				Damaged();
			}

		}
		else {
			isKnockback = false;
		}
	}
	for (int i = 0; i < player->ranged_attack_hitboxs.size(); i++) {
		if (CheckCollisionCircleRec(std::get<0>(player->ranged_attack_hitboxs[i]), RANGED_ATTACK_SPRITE_RADIUS * player->range_coefficient * 2, hitbox)) {
			RangedDamaged();
			player->ranged_attack_hitboxs.erase(player->ranged_attack_hitboxs.begin() + i);
		}
	}
	
	player_attack = player->GetisAttacking();
}

void Enemy::Attack() {

}


void Enemy::Update() {
	sprite_timer.SetTimer(0.1f);
	sprite_timer.UpdateTimer();
	UpdateHitbox();
	UpdateState();
	
}

void Enemy::DrawHitbox() {
	DrawRectangleLinesEx(hitbox, 2, RED);
}

void Enemy::DrawhpBar() {
	DrawRectangleV({ position.x - 50, position.y + hpbar_y }, { 100,10 }, WHITE);
	DrawRectangleV({ position.x-50, position.y + hpbar_y }, { float(hp)/float(max_hp) * 100,10 }, GREEN);
}


void Enemy::Draw() {
	//sprite timer
	
	if (sprite_timer.TimerDone()) {
		sprite_index++;
		if (sprite_index == sprite_index_maxnum) {
			sprite_index = 0;
		}
	}
	//draw
	DrawTexturePro(
		sprite,
		{ WEAPON_SPRITE_SIZE * float(sprite_index), 0, WEAPON_SPRITE_SIZE * float(position.x < player->GetPosition().x ? 1 : -1), WEAPON_SPRITE_SIZE},
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

Rectangle Enemy::GetHitbox() {
	return hitbox;
}

void Enemy::SetPosition(Vector2 _position) {
	position = _position;
}

void Enemy::SetDeltaPosition(Vector2 _deltaposition) {
	delta_position = _deltaposition;
}

bool Enemy::GetisKnockback() {
	return isKnockback;
}

float Enemy::GetDamage() {
	return damage;
}


