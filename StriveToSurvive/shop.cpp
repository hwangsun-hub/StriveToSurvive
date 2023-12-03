#include "library.h"

Shop::Shop(Player* _player) {
	Rectangle icon1_1 = { 538, 124, ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle icon1_2 = { 368, 205 , ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle icon1_3 = { 453, 205, ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle icon1_4 = { 538, 205, ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle icon1_5 = { 368, 288, ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle icon1_6 = { 453, 288, ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle icon1_7 = { 538, 288, ITEM_ICON_SIZE, ITEM_ICON_SIZE };

	Rectangle icon2_1 = { 538, 364, ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle icon2_2 = { 368, 445 , ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle icon2_3 = { 453, 445, ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle icon2_4 = { 538, 445, ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle icon2_5 = { 368, 528, ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle icon2_6 = { 453, 528, ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle icon2_7 = { 538, 528, ITEM_ICON_SIZE, ITEM_ICON_SIZE };

	Rectangle icon3_1 = { 453, 124, ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle icon4_1 = { 453, 364, ITEM_ICON_SIZE, ITEM_ICON_SIZE };

	Rectangle selected_icon = { 764, 128, ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle combination_icon1 = { 686, 250, ITEM_ICON_SIZE, ITEM_ICON_SIZE };
	Rectangle combination_icon2 = { 842, 128, ITEM_ICON_SIZE, ITEM_ICON_SIZE };

	Rectangle exit_hitbox = { 1156, 643, 117, 70 };

	player = _player;
	weapon_icons[COMMON_KATANA_KATANA] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(COMMON_KATANA_KATANA), icon1_1, 100);
	weapon_icons[UNCOMMON_KATANA_TAILWIND] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_KATANA_TAILWIND), icon1_2, 0);
	weapon_icons[UNCOMMON_KATANA_ZERO] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_KATANA_ZERO), icon1_3, 0);
	weapon_icons[RARE_KATANA_STORMWIND] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_KATANA_STORMWIND), icon1_4, 0);
	weapon_icons[RARE_KATANA_THUNDER] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_KATANA_THUNDER), icon1_5, 0);
	weapon_icons[RARE_KATANA_MASAMUNE] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_KATANA_MASAMUNE), icon1_6, 0);
	weapon_icons[RARE_KATANA_MURAMASA] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_KATANA_MURAMASA), icon1_7, 0);
	weapon_icons[COMMON_GREATSWORD_GREATSWORD] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(COMMON_GREATSWORD_GREATSWORD), icon2_1, 0);
	weapon_icons[UNCOMMON_GREATSWORD_KNIGHTLYSWORD] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_GREATSWORD_KNIGHTLYSWORD), icon2_2, 0);
	weapon_icons[UNCOMMON_GREATSWORD_BLOODSWORD] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_GREATSWORD_BLOODSWORD), icon2_3, 0);
	weapon_icons[RARE_GREATSWORD_BLACKKNIGHT] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_GREATSWORD_BLACKKNIGHT), icon2_4, 0);
	weapon_icons[RARE_GREATSWORD_WHITEKNIGHT] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_GREATSWORD_WHITEKNIGHT), icon2_5, 0);
	weapon_icons[RARE_GREATSWORD_VAMPIRE] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_GREATSWORD_VAMPIRE), icon2_6, 0);
	weapon_icons[RARE_GREATSWORD_BERSERKER] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_GREATSWORD_BERSERKER), icon2_7, 0);
	weapon_icons[COMMON_MACHINGUN_MACHINGUN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(COMMON_MACHINGUN_MACHINGUN), icon1_1, 0);
	weapon_icons[UNCOMMON_MACHINGUN_LIGHTMACHINGUN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_MACHINGUN_LIGHTMACHINGUN), icon1_2, 0);
	weapon_icons[UNCOMMON_MACHINGUN_HEAVYMACHINGUN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_MACHINGUN_HEAVYMACHINGUN), icon1_3, 0);
	weapon_icons[RARE_MACHINGUN_KRAKEN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_MACHINGUN_KRAKEN), icon1_4, 0);
	weapon_icons[RARE_MACHINGUN_VOID] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_MACHINGUN_VOID), icon1_5, 0);
	weapon_icons[RARE_MACHINGUN_REPENTENCE] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_MACHINGUN_REPENTENCE), icon1_6, 0);
	weapon_icons[RARE_MACHINGUN_WILD] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_MACHINGUN_WILD), icon1_7, 0);
	weapon_icons[COMMON_SNIPERRIFLE_SNIPERRIFLE] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(COMMON_SNIPERRIFLE_SNIPERRIFLE), icon2_1, 0);
	weapon_icons[UNCOMMON_SNIPERRIFLE_BOLTACTION] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_SNIPERRIFLE_BOLTACTION), icon2_2, 0);
	weapon_icons[UNCOMMON_SNIPERRIFLE_SEMIAUTO] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_SNIPERRIFLE_SEMIAUTO), icon2_3, 0);
	weapon_icons[RARE_SNIPERRIFLE_RAILGUN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_SNIPERRIFLE_RAILGUN), icon2_4, 0);
	weapon_icons[RARE_SNIPERRIFLE_PIRACY] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_SNIPERRIFLE_PIRACY), icon2_5, 0);
	weapon_icons[RARE_SNIPERRIFLE_CATERPILLAR] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_SNIPERRIFLE_CATERPILLAR), icon2_6, 0);
	weapon_icons[RARE_SNIPERRIFLE_MAGICENGINEERING] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_SNIPERRIFLE_MAGICENGINEERING), icon2_7, 0);
}

void Shop::UpdateUI() {
	//main UI

}

void  Shop::UpdatePlayerBuy() {
	switch (state)
	{
	case Shop::MELEE:
		for (int i = COMMON_KATANA_KATANA; i < COMMON_MACHINGUN_MACHINGUN; i++) {
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(weapon_icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				selected_weapon = static_cast<WeaponId>(i);
			}
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(weapon_icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
				if (player->GetMoney() > std::get<2>(weapon_icons[static_cast<WeaponId>(i)]) && player->GetInventoryMeleeWeapon() != NONE_WEAPON) {
					if (static_cast<WeaponId>(i) == std::get<0>(GetCombinationtype(player->GetInventoryMeleeWeapon())) || static_cast<WeaponId>(i) == std::get<1>(GetCombinationtype(player->GetInventoryMeleeWeapon()))) {
						player->SetInventoryMeleeWeapon(static_cast<WeaponId>(i));
						player->SetMoney(player->GetMoney() - std::get<2>(weapon_icons[static_cast<WeaponId>(i)]));
					}
				}
			}
		}
		break;
	case Shop::RANGED:
		for (int i = COMMON_MACHINGUN_MACHINGUN; i < NONE_WEAPON; i++) {
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(weapon_icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				selected_weapon = static_cast<WeaponId>(i);
			}
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(weapon_icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
				if (player->GetMoney() > std::get<2>(weapon_icons[static_cast<WeaponId>(i)]) && player->GetInventoryRangedWeapon() != NONE_WEAPON) {
					if (static_cast<WeaponId>(i) == std::get<0>(GetCombinationtype(player->GetInventoryRangedWeapon())) || static_cast<WeaponId>(i) == std::get<1>(GetCombinationtype(player->GetInventoryRangedWeapon()))) {
						player->SetInventoryRangedWeapon(static_cast<WeaponId>(i));
						player->SetMoney(player->GetMoney() - std::get<2>(weapon_icons[static_cast<WeaponId>(i)]));
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
	if (CheckCollisionPointRec(GetMousePosition(), { 350, 104, 10, 14 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		state = MELEE;
	}
	if (CheckCollisionPointRec(GetMousePosition(), { 360, 104, 10, 14 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		state = RANGED;
	}
	if (CheckCollisionPointRec(GetMousePosition(), { 370, 104, 10, 14 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		state = ORB;
	}
	
}

void Shop::DrawUI() {
	//main UI
	DrawTexturePro(
		shop_sprite,
		{ WINDOW_START_WIDTH * float(state), 0,WINDOW_START_WIDTH, WINDOW_START_HEIGHT },
		{ 0,0, WINDOW_START_WIDTH , WINDOW_START_HEIGHT },
		{ 0,0 },
		0,
		WHITE
	);
}

void Shop::Draw() {
	DrawUI();
}