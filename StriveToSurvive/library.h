#ifndef LIBRARY_H

#define LIBRARY_H

//Standard Header
#include <iostream>
#include <raylib.h>
#include <vector>
#include <string>
#include <cmath>
#include <raymath.h>


//Global Constants
constexpr int WINDOW_START_WIDTH = 1280;
constexpr int WINDOW_START_HEIGHT = 720;
constexpr int WINDOW_FRAMES_PER_SECOND = 60;
constexpr float SPAWNPOINT_CIRCLE_RADIUS = 750;	//{sqrt(WINDOW_START_WIDTH ^ 2 + WINDOW_START_HEIGHT ^ 2) / 2}'s approximation
constexpr char WINDOW_NAME[]{ "Strive To Survive" };

enum WeaponMeleeType {

};

enum WeaponRangedType {

};

//Item.cpp
class Item {
private:
	bool isWeaponTypeMelee = true;
	std::vector<Texture> MeleeWeaponSprite;
	std::vector<Texture> RangedWeaponSprite;

public:
	bool GetisWeaponTypeMelee();

};


//player.cpp
class Player : public Item{
private:
	int hp = 100;
	float damage = 10;
	float speed = 10;

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

public:
	void Move();
	void Attack();
	void Dodge();
	void Skill();
	void Draw();

	Vector2 GetPosition();

};



//enemy.cpp
class Enemy {
private:
	Player *player;
	Vector2 position;
	Vector2 spawnpoint[8] = {
		{0, SPAWNPOINT_CIRCLE_RADIUS},
		{SPAWNPOINT_CIRCLE_RADIUS / sqrt(2), SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)},
		{SPAWNPOINT_CIRCLE_RADIUS, 0},
		{SPAWNPOINT_CIRCLE_RADIUS / sqrt(2), -SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)},
		{0, SPAWNPOINT_CIRCLE_RADIUS},
		{-SPAWNPOINT_CIRCLE_RADIUS / sqrt(2), -SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)},
		{-SPAWNPOINT_CIRCLE_RADIUS, 0},
		{-SPAWNPOINT_CIRCLE_RADIUS / sqrt(2), SPAWNPOINT_CIRCLE_RADIUS / sqrt(2)}
	};
protected:
	bool isPlayerFollowType = true;
public: 
	Enemy(Player* player);
	void UpdateSpawnPoint();

};


#endif
