#ifndef LIBRARY_H

#define LIBRARY_H

//standard header
#include <iostream>
#include <raylib.h>
#include <vector>
#include <string>
#include <math.h>
#include <raymath.h>

//Global Constants
constexpr int window_start_width = 1280;
constexpr int window_start_height = 720;
constexpr int window_frames_per_second = 60;
constexpr char window_name[]{ "Strive To Survive" };

//player.cpp
class Player{
public:
	//
	void Move(bool, bool, bool, bool) {};
	void Shoot(bool) {};
	void Dodge(bool) {};
	void Skill(bool) {};

	Vector2 GetPosition() {};

private:
	enum BodyState{
		PLAYER_STANDING,
		PLAYER_WALKING
	};

	enum ArmState {
		PLAYER_STANDING,
		PLAYER_SHOOTING
	};

	enum State {
		PLAYER_LIVING,
		PLAYER_DYING
	};

	Vector2 position{};

	int hp = 100;
	float damage = 10;
	float speed = 10;

	//By default in seconds
	float shooting_cooltime = 1;
	float skill_cooltime = 10;
	
	//By default looking right
	bool islookingleft = false;
	bool islookingright = true;

};

#endif
