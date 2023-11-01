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
	DrawRectangleV(Vector2AddValue(position, -50), { 100,100 }, GREEN);
}

void Enemy::SetEnemyType(EnemyType enemytype) {
	id = enemytype;
}


Vector2 Enemy::GetPosition() {
	return position;
}