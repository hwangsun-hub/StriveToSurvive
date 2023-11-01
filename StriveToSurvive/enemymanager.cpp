#include "library.h"
EnemyManager::EnemyManager(EnemyType enemytype, Enemy _enemy) :enemy(_enemy){
	enemy.SetEnemyType(enemytype);
}