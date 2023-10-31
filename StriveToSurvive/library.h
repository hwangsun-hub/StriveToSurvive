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
public: 
	Enemy(Player player);

};


#endif
