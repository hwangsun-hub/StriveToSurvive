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





//player.cpp
class Player{
private:

	Vector2 position{ WINDOW_START_WIDTH / 2,  WINDOW_START_HEIGHT / 2 };

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

	Texture standing_sprite{ LoadTexture("resourse/Player_test.png") };

public:
	void Move();
	void Shoot();
	void Dodge();
	void Skill();
	void Draw();
	void Update();

	Vector2 GetPosition();




};

//weapon.cpp
class Weapon {
protected:
	enum Type {
		MELEE,
		RENGED
	};
	Type type;
public:
	void SetType(Type);
	Type GetType();
};

#endif
