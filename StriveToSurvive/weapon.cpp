#include "library.h"

bool Weapon::GetisWeaponTypeMelee() {
	return isWeaponTypeMelee;
}

void Weapon::SetWeapon(WeaponId _weaponid) {
	weaponid = _weaponid;
	switch (GetWeaponType(_weaponid))
	{
	case KATANA:
		weapon_sprite = GetWeaponSprite(_weaponid);
		weapon_sprite_source = {
			WEAPON_SPRITE_SIZE,
			0,
			WEAPON_SPRITE_SIZE,
			WEAPON_SPRITE_SIZE
		};
		weapon_sprite_dest = { 0, 0, WEAPON_SPRITE_SIZE * 3 , WEAPON_SPRITE_SIZE * 3 };
		weapon_sprite_orgin = { float(WEAPON_SPRITE_SIZE * 1.5) , WEAPON_SPRITE_SIZE };
		break;
	case GRAEATSWORD:
		weapon_sprite = GetWeaponSprite(_weaponid);
		weapon_sprite_source = {
			WEAPON_SPRITE_SIZE,
			0,
			WEAPON_SPRITE_SIZE,
			WEAPON_SPRITE_SIZE
		};
		weapon_sprite_dest = { -20,-90, WEAPON_SPRITE_SIZE * 3 , WEAPON_SPRITE_SIZE * 3 };
		weapon_sprite_orgin = { float(WEAPON_SPRITE_SIZE * 1.5) , WEAPON_SPRITE_SIZE };
		break;
	case MACHINGUN:
		weapon_sprite = GetWeaponSprite(_weaponid);
		weapon_sprite_source = {
			WEAPON_SPRITE_SIZE,
			0,
			WEAPON_SPRITE_SIZE,
			WEAPON_SPRITE_SIZE
		};
		weapon_sprite_dest = { 0,-WEAPON_SPRITE_SIZE * 1.5, WEAPON_SPRITE_SIZE * 3 , WEAPON_SPRITE_SIZE * 3 };
		weapon_sprite_orgin = { float(WEAPON_SPRITE_SIZE * 1.5) , WEAPON_SPRITE_SIZE };
		break;
	case SNIPERRIFLE:
		weapon_sprite = GetWeaponSprite(_weaponid);
		weapon_sprite_source = {
			WEAPON_SPRITE_SIZE,
			0,
			WEAPON_SPRITE_SIZE,
			WEAPON_SPRITE_SIZE
		};
		weapon_sprite_dest = { 0,-WEAPON_SPRITE_SIZE * 1.5, WEAPON_SPRITE_SIZE * 3 , WEAPON_SPRITE_SIZE * 3 };
		weapon_sprite_orgin = { float(WEAPON_SPRITE_SIZE * 1.5) , WEAPON_SPRITE_SIZE };
		break;
	default:
		break;
	}

}

WeaponId Weapon::GetWeapon() {
	return weaponid;
}