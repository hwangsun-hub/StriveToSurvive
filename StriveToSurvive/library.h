#ifndef LIBRARY_H

#define LIBRARY_H

//standard header
#include <iostream>
#include <raylib.h>
#include <vector>
#include <string>

//Global Constants
constexpr int window_start_width = 1280;
constexpr int window_start_height = 720;
constexpr int window_frames_per_second = 60;
constexpr char window_name[]{ "Strive To Survive" };

//player.cpp
class Player{
public:
	void Move() {};
	void Shoot() {};
	void Dodge() {};

private:
	enum BodyState{
		PLAYER_STANDING,
		PLAYER_WALKING,
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
	int hp;

};

#endif
