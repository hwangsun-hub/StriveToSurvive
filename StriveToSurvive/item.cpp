#include "library.h"

bool Item::GetisWeaponTypeMelee() {
	return isWeaponTypeMelee;
}

void Item::SetWeapon(WeaponId weaponid) {
	this->weaponid = weaponid;
}

WeaponId Item::GetWeapon() {
	return weaponid;
}


