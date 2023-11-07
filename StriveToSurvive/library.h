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

constexpr int PLAYER_STANDING_SPRITE_MAXNUM = 6;
constexpr int PLAYER_WALKING_SPRITE_MAXNUM = 5;
constexpr int MONSTER1_SPRITE_MAXNUM = 4;
constexpr int MONSTER2_SPRITE_MAXNUM = 8;

constexpr int SPRITE_SIZE = 32;
constexpr Rectangle IN_GAME_SPRITE_SIZE{ 0,0,SPRITE_SIZE * 4, SPRITE_SIZE * 4 };

constexpr char WINDOW_NAME[]{ "Strive To Survive" };


enum WeaponId {
	TEST_MELEE_WEAPON,
	TEST_RANGED_WEAPON
};


//debug
extern bool DEBUGING_MODE;

//timer.cpp
class Timer {
private:
	float lifetime = -1;
	bool istimerseting = false;
public:
	void SetTimer(float);
	void UpdateTimer();
	bool TimerDone();
};




//Item.cpp
class Item {
private:
	WeaponId weaponid = TEST_MELEE_WEAPON;
	bool isWeaponTypeMelee = true;
public:
	std::vector<Texture> MeleeWeaponSprite;
	std::vector<Texture> RangedWeaponSprite;
	bool GetisWeaponTypeMelee();
	void SetWeapon(WeaponId);
	WeaponId GetWeapon();


};


//player.cpp
class Player : public Item{
private:
	//player state
	int hp = 100;
	float damage = 10;
	float speed = 10;

	//By default in seconds
	float attack_cooltime = 1;
	float dodge_cooltime = 1;
	float skill_cooltime = 10;
	
	//By default looking right
	bool islookingright = true;
	bool isstanding = true;

	//Player Sprite
	Texture standing_sprite{ LoadTexture("resourse/player_standing.png") };
	Texture walking_sprite{ LoadTexture("resourse/player_walking.png") };

	//Player Position
	Vector2 position{ 0, 0 };
	Vector2 delta_position{ 0,0 };
	
	//Player Hitbox
	Rectangle hitbox{ float(- SPRITE_SIZE), float(- SPRITE_SIZE * 1.3), float(SPRITE_SIZE * 1.8), float(SPRITE_SIZE * 3)};

	//sprite timer
	Timer standing_sprite_timer;
	Timer walking_sprite_timer;

	unsigned int standing_sprite_index = 0;
	unsigned int walking_sprite_index = 0;


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
	void UpdateHitbox();
	void Update();


	//draw
	void Draw();

	//for debug
	void DrawSpawnPoint();
	void DrawHitbox();

	Vector2 GetPosition();
	Vector2 GetDeltaPosition();

};



//enemy.cpp
class Enemy {
protected:
	Player *player;
	Vector2 position;
	Texture sprite{ LoadTexture("resource/knight.png") };

	float speed = 0;
	int hp = 10;
	bool isPlayerFollowType = true;

public: 
	Enemy(Player* player);

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

	
public:
	EnemyManager(Player* _player): player(_player){
	}
	std::vector<TEnemyParentClass* > enemies;

	//update
	void SpawnEnemies() {
		for (int i = 0; i < 10; i++) {
			enemies.push_back(new TEnemyParentClass(player));
		}
	}

	void MoveEnemies() {
		for (TEnemyParentClass* enemy : enemies) {
			enemy->ChasePlayer();
		}
	}

	//draw
	void DrawEnemies() {
		for (TEnemyParentClass* enemy : enemies) {
			enemy->Draw();
		}
	}

};


//for debug
class TestEnemy : public Enemy {
public:
	TestEnemy(Player* player) : Enemy(player) {
		sprite = LoadTexture("resource/monster1.png");
		speed = 3;
		hp = 10;
	}

};


#endif
