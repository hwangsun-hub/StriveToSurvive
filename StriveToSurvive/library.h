#ifndef LIBRARY_H

#define LIBRARY_H

//Standard Header
#include <iostream>
#include <raylib.h>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <random>
#include <rlgl.h>
#include <map>
#include <tuple>


//Global Constants
constexpr int WINDOW_START_WIDTH = 1280;
constexpr int WINDOW_START_HEIGHT = 720;
constexpr int WINDOW_FRAMES_PER_SECOND = 60;

constexpr float SPAWNPOINT_CIRCLE_RADIUS = 750;	//{sqrt(WINDOW_START_WIDTH ^ 2 + WINDOW_START_HEIGHT ^ 2) / 2}'s approximation
constexpr float MELEE_ATTACK_HITBOX_SIZE = 50;
constexpr float ENEMY_KNOCKBACK = 25;

constexpr int PLAYER_STANDING_SPRITE_MAXNUM = 6;
constexpr int PLAYER_WALKING_SPRITE_MAXNUM = 5;
constexpr int MONSTER1_SPRITE_MAXNUM = 4;
constexpr int MONSTER2_SPRITE_MAXNUM = 8;
constexpr int MELEE_ATTACK_SPRITE_MAXNUM = 4;
constexpr int GAME_TITLE_SPRITE_VERTICAL_MAXNUM = 4;
constexpr int GAME_TITLE_SPRITE_HORIZON_MAXNUM = 3;

constexpr int SPRITE_SIZE = 32;
constexpr int IN_GAME_SPRITE_SIZE{ SPRITE_SIZE * 4 };
constexpr int ITEM_ICON_SIZE{ 64 };
constexpr int TILE_MAP_SIZE{ 1920 };


constexpr char WINDOW_NAME[]{ "Strive To Survive" };
enum GameState {
	GAMESTATE_TITLE,
	GAMESTATE_INGAME,
	GAMESTATE_SETTING,
	GAMESTATE_SHOPPING
};


enum WeaponId {
	TEST_MELEE_WEAPON,
	TEST_RANGED_WEAPON
};

extern GameState gamestate;
extern bool exitWindow;
//debug
extern bool DEBUGING_MODE;

//timer.cpp
class Timer {
private:
	float lifetime = -1;
public:
	bool istimerseting = false;
	void SetTimer(float);
	void UpdateTimer();
	bool TimerDone();
};



//Item.cpp
class Item {
private:
	std::map<WeaponId, Texture> weapon_icon;
	std::map<WeaponId, Texture> weapon_sprite;
public:
	Item();
	Texture GetWeaponIcon(WeaponId);
	void SetWeaponIcon();
	Texture GetWeaponSprite(WeaponId);
	void SetWeaponSprite();
};



//Weapon.cpp
class Weapon {
private:
	WeaponId weaponid = TEST_MELEE_WEAPON;
	bool isWeaponTypeMelee = true;
public:
	Texture weapon_sprite = LoadTexture("resourse/test_melee_weapon.png");
	Texture melee_weapon_attack_sprite = LoadTexture("resourse/melee_attack_sprite.png");
	Rectangle weapon_sprite_source{ 0, };
	Rectangle weapon_sprite_dest{ 0, };
	Vector2 weapon_sprite_orgin{ 0, };
	bool GetisWeaponTypeMelee();
	void SetWeapon(WeaponId);
	WeaponId GetWeapon();
};


//player.cpp
class Player : public Weapon{
private:
	//camera
	Camera2D camera;

	//player state
	int hp = 100;
	float damage = 10;
	float speed = 500;
	int money = 0;

	//By default in seconds
	float attack_cooltime = 0.25f;
	float dodge_cooltime = 1;
	float skill_cooltime = 10;

	bool isAttackReady = true;
	bool isAttacking = false;
	
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
	
	Rectangle melee_attack_spritebox{ float(SPRITE_SIZE), float(-SPRITE_SIZE * 1.3), float(SPRITE_SIZE * 1.8), float(SPRITE_SIZE * 3) };

	//sprite timer
	Timer standing_sprite_timer;
	Timer walking_sprite_timer;
	Timer melee_weapon_attack_sprite_timer;
	Timer attack_cooltimer;

	unsigned int standing_sprite_index = 0;
	unsigned int walking_sprite_index = 0;
	unsigned int melee_weapon_attack_sprite_index = MELEE_ATTACK_SPRITE_MAXNUM;


public:
	Player();
	Player(Camera2D);

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
	Rectangle melee_attack_hitbox{ float(SPRITE_SIZE), float(-SPRITE_SIZE * 1.3), float(SPRITE_SIZE * 1.8), float(SPRITE_SIZE * 3) };
	
	//update
	void Move();
	void Attack();
	void Dodge();
	void Skill();
	void UpdateSpawnpoint();
	void UpdateHitbox();
	void UpdateWeapon();
	void Update();


	//draw
	void DrawWeapon();
	void DrawWeaponAttack();
	void Draw();

	//for debug
	void DrawSpawnPoint();
	void DrawHitbox();
	

	Vector2 GetPosition();
	Vector2 GetDeltaPosition();
	float GetDamage();
	bool GetisAttacking();
	Rectangle GetHitbox();
	int GetMoney();
	void SetMoney(int);

};



//enemy.cpp
//basic enemy
class Enemy {
protected:
	Timer sprite_timer;

	unsigned int sprite_index = 0;
	int sprite_index_maxnum = 4;

	Player *player;
	Vector2 position;
	Vector2 delta_position{ 0,0 };
	Texture sprite{ LoadTexture("resourse/knight.png") };
	Rectangle hitbox{ 0, };

	float speed = 0;
	float damage = 0;
	int hp = 10;
	bool isPlayerFollowType = true;
	bool isKnockback = false;
	bool player_attack = false;

public: 
	Enemy(Player* player);
	~Enemy();


	//update
	void ChasePlayer();
	void UpdateHitbox();
	void Damaged();
	void Knockbacked();
	void UpdateState();
	void Attack();
	void Update();

	//draw
	void DrawHitbox();
	void DrawhpBar();
	void Draw();

	//Get
	Vector2 GetPosition();
	Vector2 GetDeltaPosition();
	int Gethp();
	Rectangle GetHitbox();

	//Set
	void SetPosition(Vector2);
	void SetDeltaPosition(Vector2);
	bool GetisKnockback();
};

//EnemyManager.cpp
//manage EnemyParentClass (spawn, update, etc..)
template <typename TEnemyParentClass>
class EnemyManager {
private:
	Player* player;

	
public:
	EnemyManager(Player* _player): player(_player){
	}
	std::vector<TEnemyParentClass* > enemies;

	//update
	void SpawnEnemies(unsigned int spawn_num) {
		for (int i = 0; i < spawn_num; i++) {
			enemies.push_back(new TEnemyParentClass(player));
		}
	}


	void UpdateEnemies() {
		for (int i = 0; i < enemies.size(); i++) {
			if (!(enemies[i]->GetisKnockback())) {
				enemies[i]->ChasePlayer();
			}
			Rectangle MovXHitbox = { enemies[i]->GetHitbox().x + enemies[i]->GetDeltaPosition().x, enemies[i]->GetHitbox().y, enemies[i]->GetHitbox().width, enemies[i]->GetHitbox().height };
			Rectangle MovYHitbox = { enemies[i]->GetHitbox().x, enemies[i]->GetHitbox().y + enemies[i]->GetDeltaPosition().y, enemies[i]->GetHitbox().width, enemies[i]->GetHitbox().height };
			if (CheckCollisionRecs(MovXHitbox, player->GetHitbox())) {
				enemies[i]->SetDeltaPosition({ player->GetDeltaPosition().x, enemies[i]->GetDeltaPosition().y });
			}
			if (CheckCollisionRecs(MovYHitbox, player->GetHitbox())) {
				enemies[i]->SetDeltaPosition({ enemies[i]->GetDeltaPosition().x, player->GetDeltaPosition().y });
			}
			enemies[i]->SetPosition({ enemies[i]->GetPosition().x + enemies[i]->GetDeltaPosition().x , enemies[i]->GetPosition().y + enemies[i]->GetDeltaPosition().y });
			enemies[i]->Update();
			if (enemies[i]->Gethp() <= 0) {
				delete enemies[i];
				enemies.erase(enemies.begin() + i);

			}
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
		UnloadTexture(sprite);
		sprite = LoadTexture("resourse/monster1.png");
		sprite_index_maxnum = MONSTER1_SPRITE_MAXNUM;
		hitbox = { position.x + float(-SPRITE_SIZE), position.y + float(-SPRITE_SIZE * 1.3), float(SPRITE_SIZE * 1.8), float(SPRITE_SIZE * 2) };
		speed = 100 + rand() % 100;
		hp = 100;
	}
	~TestEnemy() {
		UnloadTexture(sprite);
	}

};

//gametiltle.cpp 
class GameTitle {
private:
	//basic sprite
	Texture DigiPen_logo_sprite = LoadTexture("resourse/DigiPen_logo.png");
	Texture Game_Title_sprite = LoadTexture("resourse/game_logo_finished.png");
	
	//for making interaction (if you click the button, gametitle state is change)
	Rectangle game_start_button = { 62, 323, 110, 65 };
	Rectangle game_option_button = { 62, 393, 169, 65  };
	Rectangle game_credit_button = { 62, 468, 143, 65 };
	Rectangle game_quit_button = { 62, 542, 92, 65 };
	std::vector<Rectangle> buttons = { game_start_button , game_option_button , game_credit_button , game_quit_button };
	//timer
	Timer game_title_timer;
	int game_title_sprite_vertical_index = 0;
	int game_title_sprite_horizon_index = 0;
	Timer digipen_logo_timer;
	//bool
	bool isDigiPenLogoEnd = false;
public:
	void Update();
	void Draw();
};

class Shop : public Item{
private:
	Player* player;
	std::vector<Weapon> Items;
	//WeaponId, Texture, Hitbox, price
	std::vector < std::tuple<WeaponId, Texture, Rectangle, int> > Icons;
public:
	Shop(Player*);
	void UpdateUI();
	void UpdatePlayerBuy();
	void Update();
	void DrawUI();
	void Draw();
};

//TileMap.cpp
class TileMap {
private:
	Player* player;
	Texture map = LoadTexture("resourse/TileMap1920.png");
public:
	TileMap(Player* _player);
	void Update();
	void Draw();

};


#endif
