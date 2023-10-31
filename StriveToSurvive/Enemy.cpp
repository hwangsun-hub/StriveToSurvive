#include "library.h"

Enemy::Enemy(Player* player) : player(player) {
	position = player->GetPosition();
}


void Enemy::UpdateSpawnPoint() {

}
