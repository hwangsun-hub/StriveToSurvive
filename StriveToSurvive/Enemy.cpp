#include "library.h"

Enemy::Enemy(Player* player) : player(player) {
	position = player->GetPosition();
}


void Enemy::UpdateSpawnPoint() {


}

void Enemy::drawSpawnPoint() {
	for (Vector2 position : spawnpoint) {
		DrawCircleV(position, 10, BLUE);
	}

}
