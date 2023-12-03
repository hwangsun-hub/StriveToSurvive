#include "library.h"

Item::Item() {
	//weapon_sprite
	weapon_icon[COMMON_KATANA_KATANA] = LoadTexture("resourse/test_melee_weapon.png");
	weapon_icon[COMMON_MACHINGUN_MACHINGUN] = LoadTexture("resourse/test_melee_weapon.png");

}