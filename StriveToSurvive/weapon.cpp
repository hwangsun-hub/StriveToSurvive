#include "library.h"

bool Weapon::GetisWeaponTypeMelee() {
	return isWeaponTypeMelee;
}

void Weapon::SetWeapon(WeaponId _weaponid) {
	weaponid = _weaponid;
	switch (weaponid)
	{
	case TEST_MELEE_WEAPON:
		weapon_sprite = LoadTexture("resourse/test_melee_weapon.png");
		weapon_sprite_source = {
			SPRITE_SIZE,
			0,
			SPRITE_SIZE,
			SPRITE_SIZE
		};
		weapon_sprite_dest = { 0, 0, SPRITE_SIZE * 3 , SPRITE_SIZE * 3 };
		weapon_sprite_orgin = { float(SPRITE_SIZE * 1.5) , SPRITE_SIZE };
		break;
	case TEST_RANGED_WEAPON:
		break;
	}
}

WeaponId Weapon::GetWeapon() {
	return weaponid;
}