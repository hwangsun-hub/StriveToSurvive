#include "library.h"

bool Item::GetisWeaponTypeMelee() {
	return isWeaponTypeMelee;
}

void Item::SetWeapon(WeaponId _weaponid) {
	weaponid = _weaponid;
	switch (weaponid)
	{
	case TEST_MELEE_WEAPON:
		weapon_sprite = LoadTexture("resourse/test_melee_weapon.png");
		break;
	case TEST_RANGED_WEAPON:
		break;
	}
}

WeaponId Item::GetWeapon() {
	return weaponid;
}


