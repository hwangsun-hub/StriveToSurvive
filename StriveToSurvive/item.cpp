#include "library.h"

Item::Item() {
	//weapon_sprite
	weapon_icon[WeaponId::COMMON_KATANA_KATANA] = LoadTexture("resources/katana/common_katana_katana.png");
	weapon_icon[WeaponId::COMMON_GREATSWORD_GREATSWORD] = LoadTexture("resources/greatsword/common_greatsword_greatsword.png");
	weapon_icon[WeaponId::COMMON_MACHINGUN_MACHINGUN] = LoadTexture("resources/machinegun/common_machinegun_machinegun.png");
	weapon_icon[WeaponId::COMMON_SNIPERRIFLE_SNIPERRIFLE] = LoadTexture("resources/sniperrifle/common_sniperrifle_sniperrifle.png");
	//orb_icon
	orb_icon[OrbId::COMMON_LIFEORB] = LoadTexture("resources/common_orb/lifeorb.png");
	orb_icon[OrbId::COMMON_IRONORB] = LoadTexture("resources/common_orb/ironorb.png");
	orb_icon[OrbId::COMMON_SPRINGORB] = LoadTexture("resources/common_orb/springorb.png");
	orb_icon[OrbId::COMMON_ANGERORB] = LoadTexture("resources/common_orb/angerorb.png");
	orb_icon[OrbId::COMMON_WATERORB] = LoadTexture("resources/common_orb/waterorb.png");
	orb_icon[OrbId::COMMON_BLOODORB] = LoadTexture("resources/common_orb/bloodorb.png");
	orb_icon[OrbId::COMMON_WINDORB] = LoadTexture("resources/common_orb/windorb.png");
	orb_icon[OrbId::COMMON_RANGEORB] = LoadTexture("resources/common_orb/rangeorb.png");
	orb_icon[OrbId::UNCOMMON_ARMORORB] = LoadTexture("resources/uncommon_orb/armororb.png");
	orb_icon[OrbId::UNCOMMON_TRANSFUSIONORB] = LoadTexture("resources/uncommon_orb/transfusionorb.png");
	orb_icon[OrbId::UNCOMMON_ROARORB] = LoadTexture("resources/uncommon_orb/roarorb.png");
	orb_icon[OrbId::UNCOMMON_RAGEORB] = LoadTexture("resources/uncommon_orb/rageorb.png");
	orb_icon[OrbId::UNCOMMON_SEAORB] = LoadTexture("resources/uncommon_orb/seaorb.png");
	orb_icon[OrbId::UNCOMMON_HUNGERORB] = LoadTexture("resources/uncommon_orb/hungerorb.png");
	orb_icon[OrbId::UNCOMMON_SWIFTNESSORB] = LoadTexture("resources/uncommon_orb/swiftnessorb.png");
	orb_icon[OrbId::UNCOMMON_CHARGEORB] = LoadTexture("resources/uncommon_orb/chargeorb.png");
	orb_icon[OrbId::NONE_ORB] = LoadTexture("resources/common_orb/noneorb.png");

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

WeaponType Item::GetWeaponType(WeaponId _weaponId) {
	switch (_weaponId)
	{
	case COMMON_KATANA_KATANA:
	case UNCOMMON_KATANA_TAILWIND:
	case UNCOMMON_KATANA_ZERO:
	case RARE_KATANA_STORMWIND:
	case RARE_KATANA_THUNDER:
	case RARE_KATANA_MASAMUNE:
	case RARE_KATANA_MURAMASA:
		return WeaponType::KATANA;
	case COMMON_GREATSWORD_GREATSWORD:
	case UNCOMMON_GREATSWORD_KNIGHTLYSWORD:
	case UNCOMMON_GREATSWORD_BLOODSWORD:
	case RARE_GREATSWORD_BLACKKNIGHT:
	case RARE_GREATSWORD_WHITEKNIGHT:
	case RARE_GREATSWORD_VAMPIRE:
	case RARE_GREATSWORD_BERSERKER:
		return WeaponType::GRAEATSWORD;
		break;
	case COMMON_MACHINGUN_MACHINGUN:
	case UNCOMMON_MACHINGUN_LIGHTMACHINGUN:
	case UNCOMMON_MACHINGUN_HEAVYMACHINGUN:
	case RARE_MACHINGUN_KRAKEN:
	case RARE_MACHINGUN_VOID:
	case RARE_MACHINGUN_REPENTENCE:
	case RARE_MACHINGUN_WILD:
		return WeaponType::MACHINGUN;
		break;
	case COMMON_SNIPERRIFLE_SNIPERRIFLE:
	case UNCOMMON_SNIPERRIFLE_BOLTACTION:
	case UNCOMMON_SNIPERRIFLE_SEMIAUTO:
	case RARE_SNIPERRIFLE_RAILGUN:
	case RARE_SNIPERRIFLE_PIRACY:
	case RARE_SNIPERRIFLE_CATERPILLAR:
	case RARE_SNIPERRIFLE_MAGICENGINEERING:
		return WeaponType::SNIPERRIFLE;
		break;
	default:
		return WeaponType::NONE_TYPE;
		break;
	}
}

std::tuple<WeaponId, OrbId> Item::GetCombinationtype(WeaponId _weaponid) {
	switch (_weaponid)
	{
	case COMMON_KATANA_KATANA:
		return std::tuple<WeaponId, OrbId>{ WeaponId::NONE_WEAPON, OrbId::NONE_ORB };
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
		return std::tuple<WeaponId, OrbId>{ WeaponId::NONE_WEAPON, OrbId::NONE_ORB };
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
		return std::tuple<WeaponId, OrbId>{ WeaponId::NONE_WEAPON, OrbId::NONE_ORB };
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
		return std::tuple<WeaponId, OrbId>{ WeaponId::NONE_WEAPON, OrbId::NONE_ORB };
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
	case WeaponId::NONE_WEAPON:
		return std::tuple<WeaponId, OrbId>{ WeaponId::NONE_WEAPON, OrbId::NONE_ORB };
		break;

	}
}

std::tuple<OrbId, OrbId> Item::GetCombinationtype(OrbId _orbid){
	switch (_orbid)
	{
	case UNCOMMON_ARMORORB:
		return std::tuple<OrbId, OrbId>{ OrbId::COMMON_LIFEORB, OrbId::COMMON_IRONORB };
		break;
	case UNCOMMON_TRANSFUSIONORB:
		return std::tuple<OrbId, OrbId>{ OrbId::COMMON_LIFEORB, OrbId::COMMON_BLOODORB };
		break;
	case UNCOMMON_ROARORB:
		return std::tuple<OrbId, OrbId>{ OrbId::COMMON_SPRINGORB, OrbId::COMMON_RANGEORB };
		break;
	case UNCOMMON_RAGEORB:
		return std::tuple<OrbId, OrbId>{ OrbId::COMMON_ANGERORB, OrbId::COMMON_IRONORB };
		break;
	case UNCOMMON_SEAORB:
		return std::tuple<OrbId, OrbId>{ OrbId::COMMON_WATERORB, OrbId::COMMON_WINDORB };
		break;
	case UNCOMMON_HUNGERORB:
		return std::tuple<OrbId, OrbId>{ OrbId::COMMON_BLOODORB, OrbId::COMMON_BLOODORB };
		break;
	case UNCOMMON_SWIFTNESSORB:
		return std::tuple<OrbId, OrbId>{ OrbId::COMMON_WINDORB, OrbId::COMMON_WINDORB };
		break;
	case UNCOMMON_CHARGEORB:
		return std::tuple<OrbId, OrbId>{ OrbId::COMMON_ANGERORB, OrbId::COMMON_RANGEORB };
		break;
	default:
		return std::tuple<OrbId, OrbId>{ OrbId::NONE_ORB, OrbId::NONE_ORB };
		break;
	}
}