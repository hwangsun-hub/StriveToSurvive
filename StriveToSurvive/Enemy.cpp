#include "library.h"

Enemy::Enemy(Player* player) : player(player) {
	srand(time(NULL));
	position = spawnpoint[rand()%8];
}


void Enemy::UpdateSpawnPoint() {
	for (Vector2 &position : spawnpoint) {
		position = Vector2Add(position, player->GetDeltaPosition());
	}
}

void Enemy::drawSpawnPoint() {
	for (Vector2 position : spawnpoint) {
		DrawCircleV(position, 10, BLUE);
	}
}

void Enemy::ChasePlayer() {
	position.x += speed * cos(atan2f((player->GetPosition().y - position.y), (player->GetPosition().x - position.x)));
	position.y += speed * sin(atan2f((player->GetPosition().y - position.y), (player->GetPosition().x - position.x)));
}

void Enemy::Draw() {
	DrawRectangleV(Vector2AddValue(position, -50), { 100,100 }, GREEN);
}