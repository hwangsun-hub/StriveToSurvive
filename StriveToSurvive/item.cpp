#include "library.h"

Item::Item() {
	//weapon_sprite
	weapon_icon[TEST_MELEE_WEAPON] = LoadTexture("resourse/test_melee_weapon.png");
	weapon_icon[TEST_RANGED_WEAPON] = LoadTexture("resourse/test_melee_weapon.png");

}