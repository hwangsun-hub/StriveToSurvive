#ifndef LIBRARY_H

#define LIBRARY_H

//Standard Header
#include <iostream>
#include <raylib.h>
#include <vector>
#include <string>
#include <cmath>
#include <raymath.h>
#include <ctime>
#include <random>


//Global Constants
constexpr int WINDOW_START_WIDTH = 1280;
constexpr int WINDOW_START_HEIGHT = 720;
constexpr int WINDOW_FRAMES_PER_SECOND = 60;
constexpr float SPAWNPOINT_CIRCLE_RADIUS = 750;	//{sqrt(WINDOW_START_WIDTH ^ 2 + WINDOW_START_HEIGHT ^ 2) / 2}'s approximation
constexpr char WINDOW_NAME[]{ "Strive To Survive" };


enum WeaponId {
	TEST_MELEE_WEAPON
};

enum EnemyType {
	ZOMBIE
};
//debug
constexpr bool DEBUGING_MODE = true;




//Item.cpp
class Item {
private:
	WeaponId weaponid = TEST_MELEE_WEAPON;
	bool isWeaponTypeMelee = true;
	std::vector<Texture> MeleeWeaponSprite;
	std::vector<Texture> RangedWeaponSprite;
public:
	bool GetisWeaponTypeMelee();
	void SetWeapon(WeaponId);

};


//player.cpp
class Player {
private:
	int hp = 100;
	float damage = 10;
	float speed = 10;
	Item weapon;

	//By default in seconds
	float shooting_cooltime = 1;
	float dodge_cooltime = 1;
	float skill_cooltime = 10;
	
	//By default looking right
	bool islookingright = true;
	bool isstanding = true;

	//Player Sprite
	Texture standing_sprite{ LoadTexture("resourse/Player_test.png") };

	Vector2 position{ 0, 0 };
	Vector2 delta_position{ 0,0 };


public:
	Vector2 spawnpoint[8] = {
		{0, SPAWNPOINT_CIRCLE_RADIUS},
		{float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)), float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2))},
		{SPAWNPOINT_CIRCLE_RADIUS, 0},
		{float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)), -float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2))},
		{0, -SPAWNPOINT_CIRCLE_RADIUS},
		{-float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)), -float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2))},
		{-SPAWNPOINT_CIRCLE_RADIUS, 0},
		{-float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)), float(SPAWNPOINT_CIRCLE_RADIUS / sqrt(2))}
	};
	//update
	void Move();
	void Attack();
	void Dodge();
	void Skill();
	void UpdateSpawnpoint();


	//draw
	void Draw();
	void DrawSpawnPoint();

	Vector2 GetPosition();
	Vector2 GetDeltaPosition();

};



//enemy.cpp
class Enemy {
private:
	Player *player;
	Vector2 position;
	float speed = 5;
	EnemyType id = ZOMBIE;

protected:
	bool isPlayerFollowType = true;
public: 
	Enemy(Player* player);
	void SetEnemyType(EnemyType);
	Vector2 GetPosition();


	//update
	void ChasePlayer();

	//draw
	void Draw();
};

//EnemyManager.cpp
template <typename TEnemyParentClass>
class EnemyManager {
private:
	Player* player;
	EnemyType enemytype;
	
public:
	EnemyManager(EnemyType _enemytype, Player* _player): enemytype(_enemytype), player(_player){
	}
	std::vector<TEnemyParentClass* > enemies;

	//update
	void SpawnEnemies() {
		for (int i = 0; i < 10; i++) {
			enemies.push_back(new TEnemyParentClass(player));
		}
	}
	//draw
	void DrawEnemies() {
		for (TEnemyParentClass* enemy : enemies) {
			enemy->Draw();
		}
	}

	void MoveEnemies() {
		for (TEnemyParentClass* enemy : enemies) {
			enemy->ChasePlayer();
		}
	}

	void Debug() {
		for (TEnemyParentClass* enemy : enemies) {
			std::cout << enemy->GetPosition().x << " " << enemy->GetPosition().y << std::endl;
		}
	}
};


//for debug
class TestEnemy : public Enemy {
public:
	TestEnemy(Player* player) : Enemy(player) {
	}
};


#endif
