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
#include <raymath.h>


//Global Constants
constexpr int WINDOW_START_WIDTH = 1280;
constexpr int WINDOW_START_HEIGHT = 720;
constexpr int WINDOW_FRAMES_PER_SECOND = 60;

constexpr float SPAWNPOINT_CIRCLE_RADIUS = 1000;
constexpr float MELEE_ATTACK_HITBOX_SIZE = 50;
constexpr float ENEMY_KNOCKBACK = 25;

constexpr int PLAYER_STANDING_SPRITE_MAXNUM = 6;
constexpr int PLAYER_WALKING_SPRITE_MAXNUM = 5;
constexpr int RUNNER_SPRITE_MAXNUM = 4;
constexpr int TANKER_SPRITE_MAXNUM = 8;
constexpr int MELEE_ATTACK_SPRITE_MAXNUM = 4;
constexpr int GAME_TITLE_SPRITE_VERTICAL_MAXNUM = 4;
constexpr int GAME_TITLE_SPRITE_HORIZON_MAXNUM = 3;

constexpr int WEAPON_SPRITE_SIZE = 32;
constexpr int IN_GAME_SPRITE_SIZE{ WEAPON_SPRITE_SIZE * 4 };
constexpr int ITEM_ICON_SIZE{ 64 };
constexpr int TILE_MAP_SIZE{ 1920 };
constexpr float MELEE_ATTACK_RANGE_WIDTH{ float(WEAPON_SPRITE_SIZE * 1.8) };
constexpr float MELEE_ATTACK_RANGE_HEIGHT{ float(WEAPON_SPRITE_SIZE * 3) };
constexpr int RANGED_ATTACK_SPRITE_RADIUS{ 7 };
constexpr int RANGED_ATTACK_SPRITE_SPEED{ 1000 };

constexpr int PLAYER_MAX_HP = 500;
constexpr float PLAYER_DODGE_SPEED{ 30 };
constexpr float PLAYER_SPEED{ 300 };

constexpr int RUNNER_HP_COEFFICIENT = 40;
constexpr int RUNNER_DEFENSE_COEFFICIENT = 5;
constexpr int RUNNER_DAMAGE_COEFFICIENT = 25;
constexpr int RUNNER_SPEED_COEFFICIENT = 10;
constexpr int RUNNER_SPAWN_LEVEL = 1;

constexpr int TANKER_HP_COEFFICIENT = 100;
constexpr int TANKER_DEFENSE_COEFFICIENT = 15;
constexpr int TANKER_DAMAGE_COEFFICIENT = 10;
constexpr int TANKER_SPAWN_LEVEL = 4;


constexpr int SPIDER_HP_COEFFICIENT = 50;
constexpr int SPIDER_DEFENSE_COEFFICIENT = 5;
constexpr int SPIDER_DAMAGE_COEFFICIENT = 100;
constexpr int SPIDER_SPAWN_LEVEL = 7;









constexpr char WINDOW_NAME[]{ "Strive To Survive" };
enum GameState {
	GAMESTATE_TITLE,
	GAMESTATE_BEFORE_GAME,
	GAMESTATE_INGAME,
	GAMESTATE_GAMEOVER,
	GAMESTATE_SETTING,
	GAMESTATE_SHOPPING,
	GAMESTATE_CREDIT,
	GAMESTATE_CLEAR
};


enum WeaponId {
	COMMON_KATANA_KATANA,
	UNCOMMON_KATANA_TAILWIND,
	UNCOMMON_KATANA_ZERO,
	RARE_KATANA_STORMWIND,
	RARE_KATANA_THUNDER,
	RARE_KATANA_MASAMUNE,
	RARE_KATANA_MURAMASA,
	COMMON_GREATSWORD_GREATSWORD,
	UNCOMMON_GREATSWORD_KNIGHTLYSWORD,
	UNCOMMON_GREATSWORD_BLOODSWORD,
	RARE_GREATSWORD_BLACKKNIGHT,
	RARE_GREATSWORD_WHITEKNIGHT,
	RARE_GREATSWORD_VAMPIRE,
	RARE_GREATSWORD_BERSERKER,
	COMMON_MACHINEGUN_MACHINGUN,
	UNCOMMON_MACHINEGUN_LIGHTMACHINEGUN,
	UNCOMMON_MACHINEGUN_HEAVYMACHINEGUN,
	RARE_MACHINEGUN_KRAKEN,
	RARE_MACHINEGUN_VOID,
	RARE_MACHINEGUN_REPENTENCE,
	RARE_MACHINEGUN_WILD,
	COMMON_SNIPERRIFLE_SNIPERRIFLE,
	UNCOMMON_SNIPERRIFLE_BOLTACTION,
	UNCOMMON_SNIPERRIFLE_SEMIAUTO,
	RARE_SNIPERRIFLE_RAILGUN,
	RARE_SNIPERRIFLE_PIRACY,
	RARE_SNIPERRIFLE_CATERPILLAR,
	RARE_SNIPERRIFLE_MAGICENGINEERING,
	NONE_WEAPON
};

enum OrbId {
	COMMON_LIFEORB,
	COMMON_IRONORB,
	COMMON_SPRINGORB,
	COMMON_ANGERORB,
	COMMON_WATERORB,
	COMMON_BLOODORB,
	COMMON_WINDORB,
	COMMON_RANGEORB,
	UNCOMMON_ARMORORB,
	UNCOMMON_TRANSFUSIONORB,
	UNCOMMON_ROARORB,
	UNCOMMON_RAGEORB,
	UNCOMMON_SEAORB,
	UNCOMMON_HUNGERORB,
	UNCOMMON_SWIFTNESSORB,
	UNCOMMON_CHARGEORB,
	NONE_ORB
};

enum WeaponType {
	KATANA,
	GRAEATSWORD,
	MACHINGUN,
	SNIPERRIFLE,
	NONE_TYPE
};

enum PlayerStat {
	DAMAGE,
	ATTACK_SPEED,
	TRUE_DAMAGE,
	DRAIN,
	DEFENCE,
	HPS,
	RANGE,
	SPEED
};

extern GameState gamestate;
extern bool exitWindow;
extern int wave_level;
extern int talent_score;
extern Camera2D camera;

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
	std::map<WeaponId, Texture> weapon_icons;
	std::map<WeaponId, Texture> weapon_sprites;
	std::map<OrbId, Texture> orb_icons;
public:
	Item();
	Texture GetWeaponIcon(WeaponId);
	Texture GetWeaponSprite(WeaponId);
	Texture GetOrbIcon(OrbId);
	WeaponType GetWeaponType(WeaponId);
	std::tuple<WeaponId, OrbId> GetCombinationtype(WeaponId);
	std::tuple<OrbId, OrbId> GetCombinationtype(OrbId);
};



//Weapon.cpp
class Weapon : public Item{
private:
	WeaponId weaponid = COMMON_KATANA_KATANA;
	bool isWeaponTypeMelee = true;
public:
	Texture weapon_sprite;
	Texture katana_weapon_attack_sprite = LoadTexture("resources/katana_attack_sprite.png");
	Texture greatsword_weapon_attack_sprite = LoadTexture("resources/greatsword_attack_sprite.png");
	Texture ranged_weapon_attack_sprite = LoadTexture("resources/ranged_weapon_attack_sprite.png");

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
	friend class Ui;
	//inventory
	OrbId inventory_orb[3] = { NONE_ORB, NONE_ORB , NONE_ORB };

	//player state
	//life per second, defense, knockback, damage , attack speed, Drain life, speed, range
	//By default in seconds
	int hp = 500;
	float life_per_second = 0;
	float defense = 0;
	float true_defense = 0;
	float damage = 10;
	float true_damage = 0;
	float charge_damage_coefficient = 1.0f;
	float buff_damage = 0;
	float damage_coefficient = 1.0f;
	float attack_cooltime = 0.5f;
	float attack_cooltime_coefficient = 1.0f;
	float drain_life_coefficient = 0.0f;
	float buff_drain_life_coefficient = 0;
	float speed = PLAYER_SPEED;
	float speed_coefficient = 1.0f;
	float buffed_speed = 0;

	int money = 0;
	int killcount = 0;
	int buff_killcount = 0;
	float dodge_cooltime = 2;
	float dodge_cooltime_coefficient = 1.0f;

	//attack
	bool isAttackReady = true;
	bool isAttacking = false;

	//dash attack
	bool isDashAttacking = false;

	float attack_degree = 0;

	//dodge
	bool isDodgeReady = true;

	//Invincible
	bool isInvincible = false;

	bool isDamaged = false;
	bool isToggled = false;
	bool isBuffed = false;
	bool isRoared = false;

	
	//By default looking right
	bool islookingright = true;
	bool isstanding = true;

	//Player Sprite
	Texture standing_sprite{ LoadTexture("resources/player_standing.png") };
	Texture walking_sprite{ LoadTexture("resources/player_walking.png") };

	//Player Position
	Vector2 position{ 0, 0 };
	Vector2 delta_position{ 0,0 };
	
	//Player Hitbox
	Rectangle hitbox{ float(- WEAPON_SPRITE_SIZE), float(- WEAPON_SPRITE_SIZE * 1.3), float(WEAPON_SPRITE_SIZE * 1.8), float(WEAPON_SPRITE_SIZE * 3)};
	
	Rectangle melee_attack_spritebox{ float(WEAPON_SPRITE_SIZE), float(-WEAPON_SPRITE_SIZE * 1.3), MELEE_ATTACK_RANGE_WIDTH, MELEE_ATTACK_RANGE_HEIGHT };


	//sprite timer
	Timer standing_sprite_timer;
	Timer walking_sprite_timer;
	Timer melee_weapon_attack_sprite_timer;
	Timer dash_attack_sprite_timer;

	unsigned int standing_sprite_index = 0;
	unsigned int walking_sprite_index = 0;
	unsigned int melee_weapon_attack_sprite_index = MELEE_ATTACK_SPRITE_MAXNUM;
	unsigned int dash_attack_sprite_index = 0;

	//action timer
	Timer attack_cooltimer;
	Timer dodge_cooltimer;
	Timer invincible_cooltimer;
	Timer life_heal_cooltimer;

	
	bool greatsword_motion = false;

	//weaponid_changed_check
	WeaponId before_weaponid = NONE_WEAPON;

	Texture tunder_effect = LoadTexture("resources/Lightning Strike.png");




public:
	Player();
	float charge_attack_time = 0;
	float time = 0;

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
	Rectangle melee_attack_hitbox{ float(WEAPON_SPRITE_SIZE), float(-WEAPON_SPRITE_SIZE * 1.3), MELEE_ATTACK_RANGE_WIDTH, MELEE_ATTACK_RANGE_HEIGHT };
	float range_coefficient = 1.0f;
	float charge_range_coefficient = 1.0f;
	float knockback_coefficient = 1.0f;
	//orgin, degree
	std::vector<std::tuple<Vector2, float>> ranged_attack_hitboxs;
	//update
	void Move();
	void Attack();
	void RangedAttack();
	void Dodge();
	void Kill();
	void Buff();
	void UpdateSpawnpoint();
	void UpdateHitbox();
	void UpdateWeapon();
	void Update();


	//draw
	void DrawUi();
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
	bool GetisDodging();
	Rectangle GetHitbox();
	int GetMoney();
	int GetKillcount();
	void SetMoney(int);
	std::tuple<OrbId, OrbId, OrbId> GetInventoryOrb();
	void SetInventoryOrb(OrbId);
	void RemoveInventoryOrb(OrbId);
	void SetWeaponStat(WeaponId);
	void SetOrbStat(OrbId);
	void DesetOrbStat(OrbId);
	int GetHp();
	float GetTrueDamage();
	void Damaged(float);
	void Dodgereset();
	void Drain();
	bool GetisRoared();
	void SetisRoared();
	float GetStat(PlayerStat);

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
	Texture sprite{ LoadTexture("resources/knight.png") };
	Rectangle hitbox{ 0, };

	float speed = 0;
	float damage = 0;
	float defence = 0;
	int max_hp = 10;
	int hp = max_hp;
	int hpbar_y = 30;

	bool isPlayerFollowType = true;
	bool isKnockback = false;
	bool player_attack = false;
	bool player_dashattack = false;
	bool player_dodge = false;

public: 
	Enemy(Player* player);
	~Enemy();


	//update
	void ChasePlayer();
	void UpdateHitbox();
	void Damaged();
	void RangedDamaged();
	void DashDamaged();
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
	float GetDamage();

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
				player->Damaged(enemies[i]->GetDamage());
				enemies[i]->SetDeltaPosition({ player->GetDeltaPosition().x, enemies[i]->GetDeltaPosition().y });
			}
			if (CheckCollisionRecs(MovYHitbox, player->GetHitbox())) {
				player->Damaged(enemies[i]->GetDamage());
				enemies[i]->SetDeltaPosition({ enemies[i]->GetDeltaPosition().x, player->GetDeltaPosition().y });
			}
			enemies[i]->SetPosition({ enemies[i]->GetPosition().x + enemies[i]->GetDeltaPosition().x , enemies[i]->GetPosition().y + enemies[i]->GetDeltaPosition().y });
			enemies[i]->Update();
			if (enemies[i]->Gethp() <= 0) {
				player->Kill();
				delete enemies[i];
				enemies.erase(enemies.begin() + i);

			}
		}
		player->SetisRoared();
	}

	//draw
	void DrawEnemies() {
		for (TEnemyParentClass* enemy : enemies) {
			enemy->Draw();
		}
	}

	void Reset() {
		enemies.clear();
	}
};


//for debug
class Runner : public Enemy {
public:
	Runner(Player* player) : Enemy(player) {
		UnloadTexture(sprite);
		sprite = LoadTexture("resources/enemy/runner.png");
		sprite_index_maxnum = RUNNER_SPRITE_MAXNUM;
		hitbox = { position.x + float(-WEAPON_SPRITE_SIZE), position.y + float(-WEAPON_SPRITE_SIZE * 1.3), float(WEAPON_SPRITE_SIZE * 1.8), float(WEAPON_SPRITE_SIZE * 2) }; \
		damage = 25 + RUNNER_DAMAGE_COEFFICIENT * (wave_level - RUNNER_SPAWN_LEVEL);
		speed = 100 + RUNNER_SPEED_COEFFICIENT * (wave_level - RUNNER_SPAWN_LEVEL) + rand() % 50 + 1;
		max_hp = 50 + RUNNER_HP_COEFFICIENT * (wave_level - RUNNER_SPAWN_LEVEL);
		hp = max_hp;
		defence = RUNNER_DEFENSE_COEFFICIENT * (wave_level - RUNNER_SPAWN_LEVEL);
	}
	~Runner() {
		UnloadTexture(sprite);
	}

};

class Tanker : public Enemy {
public:
	Tanker(Player* player) : Enemy(player) {
		UnloadTexture(sprite);
		sprite = LoadTexture("resources/enemy/tanker.png");
		sprite_index_maxnum = TANKER_SPRITE_MAXNUM;
		hitbox = { position.x + float(-WEAPON_SPRITE_SIZE), position.y + float(-WEAPON_SPRITE_SIZE * 1.2), float(WEAPON_SPRITE_SIZE * 1.8), float(WEAPON_SPRITE_SIZE * 3.5) };
		damage = 10 + TANKER_DAMAGE_COEFFICIENT * ((wave_level - TANKER_SPAWN_LEVEL) > 0 ? (wave_level - TANKER_SPAWN_LEVEL) : 0);
		speed = 100 + rand() % 25 + 1;;
		max_hp = 100 + TANKER_HP_COEFFICIENT * ((wave_level - TANKER_SPAWN_LEVEL) > 0 ? (wave_level - TANKER_SPAWN_LEVEL) : 0);
		hp = max_hp;
		defence = 25 + TANKER_DEFENSE_COEFFICIENT * ((wave_level - TANKER_SPAWN_LEVEL) > 0 ? (wave_level - TANKER_SPAWN_LEVEL) : 0);
		hpbar_y = 60;
	}
	~Tanker() {
		UnloadTexture(sprite);
	}

};

class Spider : public Enemy {
public:
	Spider(Player* player) : Enemy(player) {
		UnloadTexture(sprite);
		sprite = LoadTexture("resources/enemy/spider.png");
		sprite_index_maxnum = TANKER_SPRITE_MAXNUM - 1;
		hitbox = { position.x + float(-WEAPON_SPRITE_SIZE), position.y + float(-WEAPON_SPRITE_SIZE * 1.3), float(WEAPON_SPRITE_SIZE * 1.8), float(WEAPON_SPRITE_SIZE * 2) };
		damage = 150 + SPIDER_DAMAGE_COEFFICIENT * ((wave_level - SPIDER_SPAWN_LEVEL) > 0 ? (wave_level - SPIDER_SPAWN_LEVEL) : 0);
		speed = 300 + rand() % 50 + 1;;
		max_hp = 300 + SPIDER_HP_COEFFICIENT * ((wave_level - SPIDER_SPAWN_LEVEL) > 0 ? (wave_level - SPIDER_SPAWN_LEVEL) : 0);
		hp = max_hp;
		defence = SPIDER_DEFENSE_COEFFICIENT * ((wave_level - SPIDER_SPAWN_LEVEL) > 0 ? (wave_level - SPIDER_SPAWN_LEVEL) : 0);
		hpbar_y = 50;
	}
	~Spider() {
		UnloadTexture(sprite);
	}

};
//WaveManager.cpp
class WaveManager {
private:
	Timer wave_timer;
	Timer runner_spawn_timer;
	Timer tanker_spawn_timer;
	Timer spider_spawn_timer;
	bool isRunnerSpawnReady = false;
	bool isTankerSpawnReady = false;
	bool isSpiderSpawnReady = false;
public:
	EnemyManager<Runner>* runner_enemymanager;
	EnemyManager<Tanker>* tanker_enemymanager;
	EnemyManager<Spider>* spider_enemymanager;
	WaveManager(Player* _player);
	void Update();
	void Draw();

};

//gametiltle.cpp 
class GameTitle {
private:
	//basic sprite
	Texture DigiPen_logo_sprite = LoadTexture("resources/DigiPen_logo.png");
	Texture Game_Title_sprite = LoadTexture("resources/game_logo_finished.png");
	
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
	//Texture, Hitbox, price
	std::map< WeaponId, std::tuple<Texture, Rectangle, int> > weapon_icons;
	std::map< OrbId, std::tuple<Texture, Rectangle, int> > orb_icons;

	Texture shop_sprite = LoadTexture("resources/shop.png");

	

	enum State {
		MELEE,
		RANGED,
		ORB
	};

	State state = MELEE;

	WeaponId selected_weapon = NONE_WEAPON;
	OrbId selected_orb = NONE_ORB;

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
	Texture map = LoadTexture("resources/TileMap1920.png");
public:
	TileMap(Player* _player);
	void Update();
	void Draw();

};
//IUi.cpp
class Ui {
private:
	enum Talent {
		NORMAL,
		RAGE,
		FORT,
		CELE,
		WEAPON_SELECT
	};
	Talent talent = NORMAL;
	Player* player;
	Texture ingame_ui = LoadTexture("resources/ui/ingame_ui.png");
	Texture shop_ui = LoadTexture("resources/ui/shop_ui.png");
	Texture stat_ui = LoadTexture("resources/ui/stat_ui.png");
	Texture lobby_ui = LoadTexture("resources/ui/lobby.png");
	Texture rage_ui = LoadTexture("resources/ui/rage.png");
	Texture celerity_ui = LoadTexture("resources/ui/celerity.png");
	Texture fortification_ui = LoadTexture("resources/ui/fortification.png");
	Texture select_weapon_ui = LoadTexture("resources/ui/select_weapon.png");
	Texture gameover_ui = LoadTexture("resources/ui/gmaeover_final.png");
	Texture gameclear_ui = LoadTexture("resources/ui/game_clear.png");
	Texture option_ui = LoadTexture("resources/ui/option.png");
	Texture option_check_ui = LoadTexture("resources/ui/option_check.png");
	Texture credit_ui = LoadTexture("resources/ui/credit.png");

	Texture ingame_ui_orb_icon1;
	Texture ingame_ui_orb_icon2;
	Texture ingame_ui_orb_icon3;

	Texture ingame_ui_weapon_icon;

	int rage_talent_score = 0;
	int fortification__talent_score = 0;
	int celerity__talent_score = 0;

	int credit_index = 0;
	bool isOptionClicked = false;

public:
	Ui(Player*);

	void UpdateIngameUi();
	void UpdateShopUi();
	void UpdateBeforeGameUi();
	void UpdateGameoverUi();
	void UpdateOptionUi();
	void UpdateCreditUi();
	void UpdateClearUi();

	void DrawIngameUi();
	void DrawShopUi();
	void DrawBeforeGameUi();
	void DrawGameoverUi();
	void DrawOptionUi();
	void DrawCreditUi();
	void DrawClearUi();

};


#endif
