#include "library.h"

WaveManager::WaveManager(Player* _player) {
	runner_enemymanager = new EnemyManager<Runner>(_player);
	tanker_enemymanager = new EnemyManager<Tanker>(_player);
	spider_enemymanager = new EnemyManager<Spider>(_player);

}

void WaveManager::Update() {
	wave_timer.SetTimer(60);
	wave_timer.UpdateTimer();
	switch (wave_level)
	{
	case 1:
		runner_spawn_timer.SetTimer(2);
		runner_spawn_timer.UpdateTimer();
		if (runner_spawn_timer.TimerDone()) {
			runner_enemymanager->SpawnEnemies(4);
		}
		break;
	case 2:
		runner_spawn_timer.SetTimer(1.5);
		runner_spawn_timer.UpdateTimer();
		if (runner_spawn_timer.TimerDone()) {
			runner_enemymanager->SpawnEnemies(4);
		}
		break;
	case 3:
		runner_spawn_timer.SetTimer(0.5);
		runner_spawn_timer.UpdateTimer();
		if (runner_spawn_timer.TimerDone()) {
			runner_enemymanager->SpawnEnemies(2);
		}
		break;
	case 4:
		runner_spawn_timer.SetTimer(0.5);
		runner_spawn_timer.UpdateTimer();
		if (runner_spawn_timer.TimerDone()) {
			runner_enemymanager->SpawnEnemies(2);
		}
		tanker_spawn_timer.SetTimer(2);
		tanker_spawn_timer.UpdateTimer();
		if (tanker_spawn_timer.TimerDone()) {
			tanker_enemymanager->SpawnEnemies(1);
		}
		break;
	case 5:
		runner_spawn_timer.SetTimer(0.25);
		runner_spawn_timer.UpdateTimer();
		if (runner_spawn_timer.TimerDone()) {
			runner_enemymanager->SpawnEnemies(2);
		}
		tanker_spawn_timer.SetTimer(2);
		tanker_spawn_timer.UpdateTimer();
		if (tanker_spawn_timer.TimerDone()) {
			tanker_enemymanager->SpawnEnemies(1);
		}
		break;
	case 6:
		runner_spawn_timer.SetTimer(0.25);
		runner_spawn_timer.UpdateTimer();
		if (runner_spawn_timer.TimerDone()) {
			runner_enemymanager->SpawnEnemies(2);
		}
		tanker_spawn_timer.SetTimer(1);
		tanker_spawn_timer.UpdateTimer();
		if (tanker_spawn_timer.TimerDone()) {
			tanker_enemymanager->SpawnEnemies(1);
		}
		break;
	case 7:
		runner_spawn_timer.SetTimer(0.25);
		runner_spawn_timer.UpdateTimer();
		if (runner_spawn_timer.TimerDone()) {
			runner_enemymanager->SpawnEnemies(2);
		}
		tanker_spawn_timer.SetTimer(1);
		tanker_spawn_timer.UpdateTimer();
		if (tanker_spawn_timer.TimerDone()) {
			tanker_enemymanager->SpawnEnemies(1);
		}
		spider_spawn_timer.SetTimer(2);
		spider_spawn_timer.UpdateTimer();
		if (spider_spawn_timer.TimerDone()) {
			spider_enemymanager->SpawnEnemies(1);
		}
		break;
	case 8:
		runner_spawn_timer.SetTimer(0.5);
		runner_spawn_timer.UpdateTimer();
		if (runner_spawn_timer.TimerDone()) {
			runner_enemymanager->SpawnEnemies(6);
		}
		tanker_spawn_timer.SetTimer(1);
		tanker_spawn_timer.UpdateTimer();
		if (tanker_spawn_timer.TimerDone()) {
			tanker_enemymanager->SpawnEnemies(2);
		}
		spider_spawn_timer.SetTimer(2);
		spider_spawn_timer.UpdateTimer();
		if (spider_spawn_timer.TimerDone()) {
			spider_enemymanager->SpawnEnemies(1);
		}
		break;
	case 9:
		runner_spawn_timer.SetTimer(0.5);
		runner_spawn_timer.UpdateTimer();
		if (runner_spawn_timer.TimerDone()) {
			runner_enemymanager->SpawnEnemies(8);
		}
		tanker_spawn_timer.SetTimer(1);
		tanker_spawn_timer.UpdateTimer();
		if (tanker_spawn_timer.TimerDone()) {
			tanker_enemymanager->SpawnEnemies(2);
		}
		spider_spawn_timer.SetTimer(1);
		spider_spawn_timer.UpdateTimer();
		if (spider_spawn_timer.TimerDone()) {
			spider_enemymanager->SpawnEnemies(1);
		}
		break;
	case 10:
		runner_spawn_timer.SetTimer(0.5);
		runner_spawn_timer.UpdateTimer();
		if (runner_spawn_timer.TimerDone()) {
			runner_enemymanager->SpawnEnemies(8);
		}
		tanker_spawn_timer.SetTimer(1);
		tanker_spawn_timer.UpdateTimer();
		if (tanker_spawn_timer.TimerDone()) {
			tanker_enemymanager->SpawnEnemies(2);
		}
		spider_spawn_timer.SetTimer(1);
		spider_spawn_timer.UpdateTimer();
		if (spider_spawn_timer.TimerDone()) {
			spider_enemymanager->SpawnEnemies(1);
		}
		break;
	default:
		break;
	}

	runner_enemymanager->UpdateEnemies();
	tanker_enemymanager->UpdateEnemies();
	spider_enemymanager->UpdateEnemies();

	if (wave_timer.TimerDone()) {
		gamestate = GAMESTATE_SHOPPING;
		camera.zoom = 1;
		runner_enemymanager->Reset();
		tanker_enemymanager->Reset();
		spider_enemymanager->Reset();
	}
}

void WaveManager::Draw() {
	runner_enemymanager->DrawEnemies();
	tanker_enemymanager->DrawEnemies();
	spider_enemymanager->DrawEnemies();
}