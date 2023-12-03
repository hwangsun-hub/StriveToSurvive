#include "library.h"

Shop::Shop(Player* _player) {
	player = _player;
	Icons[COMMON_KATANA_KATANA] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(COMMON_KATANA_KATANA), icon1_1, 100);
	Icons[UNCOMMON_KATANA_TAILWIND] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_KATANA_TAILWIND), icon1_2, 0);
	Icons[UNCOMMON_KATANA_ZERO] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_KATANA_ZERO), icon1_3, 0);
	Icons[RARE_KATANA_STORMWIND] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_KATANA_STORMWIND), icon1_4, 0);
	Icons[RARE_KATANA_THUNDER] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_KATANA_THUNDER), icon1_5, 0);
	Icons[RARE_KATANA_MASAMUNE] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_KATANA_MASAMUNE), icon1_6, 0);
	Icons[RARE_KATANA_MURAMASA] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_KATANA_MURAMASA), icon1_7, 0);
	Icons[COMMON_GREATSWORD_GREATSWORD] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(COMMON_GREATSWORD_GREATSWORD), icon2_1, 0);
	Icons[UNCOMMON_GREATSWORD_KNIGHTLYSWORD] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_GREATSWORD_KNIGHTLYSWORD), icon2_2, 0);
	Icons[UNCOMMON_GREATSWORD_BLOODSWORD] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_GREATSWORD_BLOODSWORD), icon2_3, 0);
	Icons[RARE_GREATSWORD_BLACKKNIGHT] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_GREATSWORD_BLACKKNIGHT), icon2_4, 0);
	Icons[RARE_GREATSWORD_WHITEKNIGHT] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_GREATSWORD_WHITEKNIGHT), icon2_5, 0);
	Icons[RARE_GREATSWORD_VAMPIRE] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_GREATSWORD_VAMPIRE), icon2_6, 0);
	Icons[RARE_GREATSWORD_BERSERKER] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_GREATSWORD_BERSERKER), icon2_7, 0);
	Icons[COMMON_MACHINGUN_MACHINGUN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(COMMON_MACHINGUN_MACHINGUN), icon1_1, 0);
	Icons[UNCOMMON_MACHINGUN_LIGHTMACHINGUN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_MACHINGUN_LIGHTMACHINGUN), icon1_2, 0);
	Icons[UNCOMMON_MACHINGUN_HEAVYMACHINGUN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_MACHINGUN_HEAVYMACHINGUN), icon1_3, 0);
	Icons[RARE_MACHINGUN_KRAKEN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_MACHINGUN_KRAKEN), icon1_4, 0);
	Icons[RARE_MACHINGUN_VOID] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_MACHINGUN_VOID), icon1_5, 0);
	Icons[RARE_MACHINGUN_REPENTENCE] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_MACHINGUN_REPENTENCE), icon1_6, 0);
	Icons[RARE_MACHINGUN_WILD] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_MACHINGUN_WILD), icon1_7, 0);
	Icons[COMMON_SNIPERRIFLE_SNIPERRIFLE] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(COMMON_SNIPERRIFLE_SNIPERRIFLE), icon2_1, 0);
	Icons[UNCOMMON_SNIPERRIFLE_BOLTACTION] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_SNIPERRIFLE_BOLTACTION), icon2_2, 0);
	Icons[UNCOMMON_SNIPERRIFLE_SEMIAUTO] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_SNIPERRIFLE_SEMIAUTO), icon2_3, 0);
	Icons[RARE_SNIPERRIFLE_RAILGUN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_SNIPERRIFLE_RAILGUN), icon2_4, 0);
	Icons[RARE_SNIPERRIFLE_PIRACY] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_SNIPERRIFLE_PIRACY), icon2_5, 0);
	Icons[RARE_SNIPERRIFLE_CATERPILLAR] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_SNIPERRIFLE_CATERPILLAR), icon2_6, 0);
	Icons[RARE_SNIPERRIFLE_MAGICENGINEERING] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_SNIPERRIFLE_MAGICENGINEERING), icon2_7, 0);
}

void Shop::UpdateUI() {
	//main UI

}

void  Shop::UpdatePlayerBuy() {
	switch (state)
	{
	case Shop::MELEE:
		for (int i = COMMON_KATANA_KATANA; i < COMMON_MACHINGUN_MACHINGUN; i++) {
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(Icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				selected_weapon = static_cast<WeaponId>(i);
			}
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(Icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
				if (player->GetMoney() > std::get<2>(Icons[static_cast<WeaponId>(i)]) && player->GetInventoryMeleeWeapon() != NONE_WEAPON) {
					if (static_cast<WeaponId>(i) == std::get<0>(GetCombinationtype(player->GetInventoryMeleeWeapon())) || static_cast<WeaponId>(i) == std::get<1>(GetCombinationtype(player->GetInventoryMeleeWeapon()))) {
						player->SetInventoryMeleeWeapon(static_cast<WeaponId>(i));
						player->SetMoney(player->GetMoney() - std::get<2>(Icons[static_cast<WeaponId>(i)]));
					}
				}
			}
		}
		break;
	case Shop::RANGED:
		for (int i = COMMON_MACHINGUN_MACHINGUN; i < NONE_WEAPON; i++) {
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(Icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				selected_weapon = static_cast<WeaponId>(i);
			}
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(Icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
				if (player->GetMoney() > std::get<2>(Icons[static_cast<WeaponId>(i)]) && player->GetInventoryRangedWeapon() != NONE_WEAPON) {
					if (static_cast<WeaponId>(i) == std::get<0>(GetCombinationtype(player->GetInventoryRangedWeapon())) || static_cast<WeaponId>(i) == std::get<1>(GetCombinationtype(player->GetInventoryRangedWeapon()))) {
						player->SetInventoryRangedWeapon(static_cast<WeaponId>(i));
						player->SetMoney(player->GetMoney() - std::get<2>(Icons[static_cast<WeaponId>(i)]));
					}
				}
			}
		}
		break;
	case Shop::ORB:
		break;
	default:
		break;
	}
}

void Shop::Update(){

}

void Shop::DrawUI() {
	//main UI
	DrawRectangle(0, 0, 1000, 650, RED);
}

void Shop::Draw() {
	DrawUI();
}