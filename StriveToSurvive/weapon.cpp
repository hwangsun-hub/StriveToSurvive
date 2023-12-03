#include "library.h"

bool Weapon::GetisWeaponTypeMelee() {
	return isWeaponTypeMelee;
}

void Weapon::SetWeapon(WeaponId _weaponid) {
	weaponid = _weaponid;
	switch (weaponid)
	{
	case COMMON_KATANA_KATANA:
		weapon_sprite = LoadTexture("resourse/test_melee_weapon.png");
		weapon_sprite_source = {
			WEAPON_SPRITE_SIZE,
			0,
			WEAPON_SPRITE_SIZE,
			WEAPON_SPRITE_SIZE
		};
		weapon_sprite_dest = { 0, 0, WEAPON_SPRITE_SIZE * 3 , WEAPON_SPRITE_SIZE * 3 };
		weapon_sprite_orgin = { float(WEAPON_SPRITE_SIZE * 1.5) , WEAPON_SPRITE_SIZE };
		break;
	case COMMON_MACHINGUN_MACHINGUN:
		break;
	}
}

WeaponId Weapon::GetWeapon() {
	return weaponid;
}