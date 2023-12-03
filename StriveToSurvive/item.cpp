#include "library.h"

Item::Item() {
	//weapon_sprite
	weapon_icon[COMMON_KATANA_KATANA] = LoadTexture("resourse/test_melee_weapon.png");
	weapon_icon[COMMON_MACHINGUN_MACHINGUN] = LoadTexture("resourse/test_melee_weapon.png");

}

Texture Item::GetWeaponIcon(WeaponId _weaponId) {
	return weapon_icon[_weaponId];
}

Texture Item::GetWeaponSprite(WeaponId _weaponId) {
	return weapon_sprite[_weaponId];
}

Texture Item::GetOrbIcon(OrbId _orbid) {
	return orb_icon[_orbid];
}

std::tuple<WeaponId, OrbId> Item::GetCombinationtype(WeaponId _weaponid) {
	switch (_weaponid)
	{
	case COMMON_KATANA_KATANA:
		return std::tuple<WeaponId, OrbId>{ WeaponId::NONE, OrbId::NONE };
		break;
	case UNCOMMON_KATANA_TAILWIND:
		return std::tuple<WeaponId, OrbId>{ WeaponId::COMMON_KATANA_KATANA, OrbId::COMMON_WATERORB };
		break;
	case UNCOMMON_KATANA_ZERO:
		return std::tuple<WeaponId, OrbId>{ WeaponId::COMMON_KATANA_KATANA, OrbId::COMMON_ANGERORB };
		break;
	case RARE_KATANA_STORMWIND:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_KATANA_TAILWIND, OrbId::UNCOMMON_SEAORB };
		break;
	case RARE_KATANA_THUNDER:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_KATANA_TAILWIND, OrbId::UNCOMMON_SWIFTNESSORB };
		break;
	case RARE_KATANA_MASAMUNE:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_KATANA_ZERO, OrbId::UNCOMMON_CHARGEORB };
		break;
	case RARE_KATANA_MURAMASA:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_KATANA_ZERO, OrbId::UNCOMMON_TRANSFUSIONORB };
		break;
	case COMMON_GREATSWORD_GREATSWORD:
		return std::tuple<WeaponId, OrbId>{ WeaponId::NONE, OrbId::NONE };
		break;
	case UNCOMMON_GREATSWORD_KNIGHTLYSWORD:
		return std::tuple<WeaponId, OrbId>{ WeaponId::COMMON_GREATSWORD_GREATSWORD, OrbId::COMMON_ANGERORB };
		break;
	case UNCOMMON_GREATSWORD_BLOODSWORD:
		return std::tuple<WeaponId, OrbId>{ WeaponId::COMMON_GREATSWORD_GREATSWORD, OrbId::COMMON_BLOODORB };
		break;
	case RARE_GREATSWORD_BLACKKNIGHT:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_GREATSWORD_KNIGHTLYSWORD, OrbId::UNCOMMON_RAGEORB };
		break;
	case RARE_GREATSWORD_WHITEKNIGHT:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_GREATSWORD_KNIGHTLYSWORD, OrbId::UNCOMMON_ARMORORB };
		break;
	case RARE_GREATSWORD_VAMPIRE:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_GREATSWORD_BLOODSWORD, OrbId::UNCOMMON_HUNGERORB };
		break;
	case RARE_GREATSWORD_BERSERKER:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_GREATSWORD_BLOODSWORD, OrbId::UNCOMMON_RAGEORB };
		break;
	case COMMON_MACHINGUN_MACHINGUN:
		return std::tuple<WeaponId, OrbId>{ WeaponId::NONE, OrbId::NONE };
		break;
	case UNCOMMON_MACHINGUN_LIGHTMACHINGUN:
		return std::tuple<WeaponId, OrbId>{ WeaponId::COMMON_MACHINGUN_MACHINGUN, OrbId::COMMON_WATERORB };
		break;
	case UNCOMMON_MACHINGUN_HEAVYMACHINGUN:
		return std::tuple<WeaponId, OrbId>{ WeaponId::COMMON_MACHINGUN_MACHINGUN, OrbId::COMMON_ANGERORB };
		break;
	case RARE_MACHINGUN_KRAKEN:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_MACHINGUN_LIGHTMACHINGUN, OrbId::UNCOMMON_SEAORB };
		break;
	case RARE_MACHINGUN_VOID:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_MACHINGUN_LIGHTMACHINGUN, OrbId::UNCOMMON_ARMORORB };
		break;
	case RARE_MACHINGUN_REPENTENCE:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_MACHINGUN_HEAVYMACHINGUN, OrbId::UNCOMMON_HUNGERORB };
		break;
	case RARE_MACHINGUN_WILD:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_MACHINGUN_HEAVYMACHINGUN, OrbId::UNCOMMON_ROARORB };
		break;
	case COMMON_SNIPERRIFLE_SNIPERRIFLE:
		return std::tuple<WeaponId, OrbId>{ WeaponId::NONE, OrbId::NONE };
		break;
	case UNCOMMON_SNIPERRIFLE_BOLTACTION:
		return std::tuple<WeaponId, OrbId>{ WeaponId::COMMON_SNIPERRIFLE_SNIPERRIFLE, OrbId::COMMON_ANGERORB };
		break;
	case UNCOMMON_SNIPERRIFLE_SEMIAUTO:
		return std::tuple<WeaponId, OrbId>{ WeaponId::COMMON_SNIPERRIFLE_SNIPERRIFLE, OrbId::COMMON_WATERORB };
		break;
	case RARE_SNIPERRIFLE_RAILGUN:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_SNIPERRIFLE_BOLTACTION, OrbId::UNCOMMON_CHARGEORB };
		break;
	case RARE_SNIPERRIFLE_PIRACY:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_SNIPERRIFLE_BOLTACTION, OrbId::UNCOMMON_SEAORB };
		break;
	case RARE_SNIPERRIFLE_CATERPILLAR:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_SNIPERRIFLE_SEMIAUTO, OrbId::UNCOMMON_SWIFTNESSORB };
		break;
	case RARE_SNIPERRIFLE_MAGICENGINEERING:
		return std::tuple<WeaponId, OrbId>{ WeaponId::UNCOMMON_SNIPERRIFLE_SEMIAUTO, OrbId::UNCOMMON_CHARGEORB };
		break;
	case WeaponId::NONE:
		return std::tuple<WeaponId, OrbId>{ WeaponId::NONE, OrbId::NONE };
		break;

	}
}

std::tuple<OrbId, OrbId> Item::GetCombinationtype(OrbId){
}