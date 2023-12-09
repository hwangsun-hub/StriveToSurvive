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
	weapon_icons[UNCOMMON_KATANA_TAILWIND] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_KATANA_TAILWIND), icon1_2, 750);
	weapon_icons[UNCOMMON_KATANA_ZERO] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_KATANA_ZERO), icon1_3, 750);
	weapon_icons[RARE_KATANA_STORMWIND] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_KATANA_STORMWIND), icon1_4, 3000);
	weapon_icons[RARE_KATANA_THUNDER] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_KATANA_THUNDER), icon1_5, 3000);
	weapon_icons[RARE_KATANA_MASAMUNE] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_KATANA_MASAMUNE), icon1_6, 3000);
	weapon_icons[RARE_KATANA_MURAMASA] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_KATANA_MURAMASA), icon1_7, 3000);
	weapon_icons[COMMON_GREATSWORD_GREATSWORD] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(COMMON_GREATSWORD_GREATSWORD), icon2_1, 100);
	weapon_icons[UNCOMMON_GREATSWORD_KNIGHTLYSWORD] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_GREATSWORD_KNIGHTLYSWORD), icon2_2, 750);
	weapon_icons[UNCOMMON_GREATSWORD_BLOODSWORD] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_GREATSWORD_BLOODSWORD), icon2_3, 750);
	weapon_icons[RARE_GREATSWORD_BLACKKNIGHT] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_GREATSWORD_BLACKKNIGHT), icon2_4, 3000);
	weapon_icons[RARE_GREATSWORD_WHITEKNIGHT] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_GREATSWORD_WHITEKNIGHT), icon2_5, 3000);
	weapon_icons[RARE_GREATSWORD_VAMPIRE] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_GREATSWORD_VAMPIRE), icon2_6, 3000);
	weapon_icons[RARE_GREATSWORD_BERSERKER] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_GREATSWORD_BERSERKER), icon2_7, 3000);
	weapon_icons[COMMON_MACHINEGUN_MACHINGUN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(COMMON_MACHINEGUN_MACHINGUN), icon1_1, 100);
	weapon_icons[UNCOMMON_MACHINEGUN_LIGHTMACHINEGUN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_MACHINEGUN_LIGHTMACHINEGUN), icon1_2, 750);
	weapon_icons[UNCOMMON_MACHINEGUN_HEAVYMACHINEGUN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_MACHINEGUN_HEAVYMACHINEGUN), icon1_3, 750);
	weapon_icons[RARE_MACHINEGUN_KRAKEN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_MACHINEGUN_KRAKEN), icon1_4, 3000);
	weapon_icons[RARE_MACHINEGUN_VOID] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_MACHINEGUN_VOID), icon1_5, 3000);
	weapon_icons[RARE_MACHINEGUN_REPENTENCE] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_MACHINEGUN_REPENTENCE), icon1_6, 3000);
	weapon_icons[RARE_MACHINEGUN_WILD] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_MACHINEGUN_WILD), icon1_7, 3000);
	weapon_icons[COMMON_SNIPERRIFLE_SNIPERRIFLE] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(COMMON_SNIPERRIFLE_SNIPERRIFLE), icon2_1, 100);
	weapon_icons[UNCOMMON_SNIPERRIFLE_BOLTACTION] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_SNIPERRIFLE_BOLTACTION), icon2_2, 750);
	weapon_icons[UNCOMMON_SNIPERRIFLE_SEMIAUTO] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(UNCOMMON_SNIPERRIFLE_SEMIAUTO), icon2_3, 750);
	weapon_icons[RARE_SNIPERRIFLE_RAILGUN] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_SNIPERRIFLE_RAILGUN), icon2_4, 3000);
	weapon_icons[RARE_SNIPERRIFLE_PIRACY] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_SNIPERRIFLE_PIRACY), icon2_5, 3000);
	weapon_icons[RARE_SNIPERRIFLE_CATERPILLAR] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_SNIPERRIFLE_CATERPILLAR), icon2_6, 3000);
	weapon_icons[RARE_SNIPERRIFLE_MAGICENGINEERING] = std::tuple<Texture, Rectangle, int>(GetWeaponIcon(RARE_SNIPERRIFLE_MAGICENGINEERING), icon2_7, 3000);


	orb_icons[OrbId::COMMON_LIFEORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(COMMON_LIFEORB), icon3_1, 500);
	orb_icons[OrbId::COMMON_IRONORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(COMMON_IRONORB), icon1_1, 500);
	orb_icons[OrbId::COMMON_SPRINGORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(COMMON_SPRINGORB), icon1_2, 500);
	orb_icons[OrbId::COMMON_ANGERORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(COMMON_ANGERORB), icon1_3, 500);
	orb_icons[OrbId::COMMON_WATERORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(COMMON_WATERORB), icon1_4, 500);
	orb_icons[OrbId::COMMON_BLOODORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(COMMON_BLOODORB), icon1_5, 500);
	orb_icons[OrbId::COMMON_WINDORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(COMMON_WINDORB), icon1_6, 500);
	orb_icons[OrbId::COMMON_RANGEORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(COMMON_RANGEORB), icon1_7, 500);
	orb_icons[OrbId::UNCOMMON_ARMORORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(UNCOMMON_ARMORORB), icon4_1, 1500);
	orb_icons[OrbId::UNCOMMON_TRANSFUSIONORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(UNCOMMON_TRANSFUSIONORB), icon2_1, 1500);
	orb_icons[OrbId::UNCOMMON_ROARORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(UNCOMMON_ROARORB), icon2_2, 1500);
	orb_icons[OrbId::UNCOMMON_RAGEORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(UNCOMMON_RAGEORB), icon2_3, 1500);
	orb_icons[OrbId::UNCOMMON_SEAORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(UNCOMMON_SEAORB), icon2_4, 1500);
	orb_icons[OrbId::UNCOMMON_HUNGERORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(UNCOMMON_HUNGERORB), icon2_5, 1500);
	orb_icons[OrbId::UNCOMMON_SWIFTNESSORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(UNCOMMON_SWIFTNESSORB), icon2_6, 1500);
	orb_icons[OrbId::UNCOMMON_CHARGEORB] = std::tuple<Texture, Rectangle, int>(GetOrbIcon(UNCOMMON_CHARGEORB), icon2_7, 1500);
}

void Shop::UpdateUI() {
	//main UI

}

void  Shop::UpdatePlayerBuy() {
	switch (state)
	{
	case Shop::MELEE:
		for (int i = COMMON_KATANA_KATANA; i < COMMON_MACHINEGUN_MACHINGUN; i++) {
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(weapon_icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				selected_weapon = static_cast<WeaponId>(i);
			}
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(weapon_icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
				if (player->GetMoney() > std::get<2>(weapon_icons[static_cast<WeaponId>(i)])) {
					if (std::get<0>(GetCombinationtype(static_cast<WeaponId>(i))) == player->GetWeapon() || player->GetWeapon() == WeaponId::NONE_WEAPON) {
						player->SetWeapon(static_cast<WeaponId>(i));
						player->SetMoney(player->GetMoney() - std::get<2>(weapon_icons[static_cast<WeaponId>(i)]));
					}
				}
			}
		}
		break;
	case Shop::RANGED:
		for (int i = COMMON_MACHINEGUN_MACHINGUN; i < NONE_WEAPON; i++) {
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(weapon_icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				selected_weapon = static_cast<WeaponId>(i);
			}
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(weapon_icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
				if (player->GetMoney() > std::get<2>(weapon_icons[static_cast<WeaponId>(i)])) {
					if (std::get<0>(GetCombinationtype(static_cast<WeaponId>(i))) == player->GetWeapon() || player->GetWeapon() == WeaponId::NONE_WEAPON) {
						player->SetWeapon(static_cast<WeaponId>(i));
						player->SetMoney(player->GetMoney() - std::get<2>(weapon_icons[static_cast<WeaponId>(i)]));
					}
				}
			}
		}
		break;
	case Shop::ORB:
		for (int i = COMMON_LIFEORB; i < NONE_ORB; i++) {
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(orb_icons[static_cast<OrbId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				selected_orb = static_cast<OrbId>(i);
			}
			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(orb_icons[static_cast<OrbId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
				if (player->GetMoney() > std::get<2>(orb_icons[static_cast<OrbId>(i)]) && player->GetWeapon() != NONE_WEAPON) {
					if (static_cast<WeaponId>(i) == std::get<0>(GetCombinationtype(player->GetWeapon())) || static_cast<OrbId>(i) == std::get<1>(GetCombinationtype(player->GetWeapon()))) {
						player->SetInventoryOrb(static_cast<OrbId>(i));
						player->SetMoney(player->GetMoney() - std::get<2>(orb_icons[static_cast<OrbId>(i)]));
					}
				}
			}
		}
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
	UpdatePlayerBuy();
	if (CheckCollisionPointRec(GetMousePosition(), { 1151, 638, 128, 80 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		gamestate = GAMESTATE_INGAME;
		wave_level++;
		camera.zoom = 0.75;
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
	switch (state)
	{
	case Shop::MELEE:
		for (int i = COMMON_KATANA_KATANA; i < COMMON_MACHINEGUN_MACHINGUN; i++) {
			DrawTexturePro(
				std::get<0>(weapon_icons[static_cast<WeaponId>(i)]),
				{ 0,0,WEAPON_SPRITE_SIZE, WEAPON_SPRITE_SIZE },
				std::get<1>(weapon_icons[static_cast<WeaponId>(i)]),
				{ 0,0 },
				0,
				WHITE
			);
			if (static_cast<WeaponId>(i) == player->GetWeapon()) {
				DrawRectangleRec(std::get<1>(weapon_icons[static_cast<WeaponId>(i)]), { 0,0,0,128 });
			}
			DrawText(
				TextFormat("%d", std::get<2>(weapon_icons[static_cast<WeaponId>(i)])),
				std::get<1>(weapon_icons[static_cast<WeaponId>(i)]).x,
				std::get<1>(weapon_icons[static_cast<WeaponId>(i)]).y + std::get<1>(weapon_icons[static_cast<WeaponId>(i)]).height,
				18,
				BLACK
			);
		}
		DrawTexturePro(
			std::get<0>(weapon_icons[selected_weapon]),
			{ 0,0,WEAPON_SPRITE_SIZE, WEAPON_SPRITE_SIZE },
			{ 764, 128,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(
			TextFormat("%d", std::get<2>(weapon_icons[selected_weapon])),
			764,
			128 + ITEM_ICON_SIZE,
			18,
			BLACK
		);
		DrawTexturePro(
			std::get<0>(weapon_icons[std::get<0>(GetCombinationtype(selected_weapon))]),
			{ 0,0,WEAPON_SPRITE_SIZE, WEAPON_SPRITE_SIZE },
			{ 686, 250,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(
			TextFormat("%d", std::get<2>(weapon_icons[std::get<0>(GetCombinationtype(selected_weapon))])),
			686,
			250 + ITEM_ICON_SIZE,
			18,
			BLACK
		);
		DrawTexturePro(
			std::get<0>(orb_icons[std::get<1>(GetCombinationtype(selected_weapon))]),
			{ 0,0,ITEM_ICON_SIZE, ITEM_ICON_SIZE },
			{ 842, 250,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(
			TextFormat("%d", std::get<2>(orb_icons[std::get<1>(GetCombinationtype(selected_weapon))])),
			842,
			250 + ITEM_ICON_SIZE,
			18,
			BLACK
		);
		
		break;
	case Shop::RANGED:
		for (int i = COMMON_MACHINEGUN_MACHINGUN; i < NONE_WEAPON; i++) {
			DrawTexturePro(
				std::get<0>(weapon_icons[static_cast<WeaponId>(i)]),
				{ 0,0,WEAPON_SPRITE_SIZE, WEAPON_SPRITE_SIZE },
				std::get<1>(weapon_icons[static_cast<WeaponId>(i)]),
				{ 0,0 },
				0,
				WHITE
			);
			if (static_cast<WeaponId>(i) == player->GetWeapon()) {
				DrawRectangleRec(std::get<1>(weapon_icons[static_cast<WeaponId>(i)]), { 0,0,0,128 });
			}
			DrawText(
				TextFormat("%d", std::get<2>(weapon_icons[static_cast<WeaponId>(i)])),
				std::get<1>(weapon_icons[static_cast<WeaponId>(i)]).x,
				std::get<1>(weapon_icons[static_cast<WeaponId>(i)]).y + std::get<1>(weapon_icons[static_cast<WeaponId>(i)]).height,
				18,
				BLACK
			);
		}
		DrawTexturePro(
			std::get<0>(weapon_icons[selected_weapon]),
			{ 0,0,WEAPON_SPRITE_SIZE, WEAPON_SPRITE_SIZE },
			{ 764, 128,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(
			TextFormat("%d", std::get<2>(weapon_icons[selected_weapon])),
			764,
			128 + ITEM_ICON_SIZE,
			18,
			BLACK
		);
		DrawTexturePro(
			std::get<0>(weapon_icons[std::get<0>(GetCombinationtype(selected_weapon))]),
			{ 0,0,WEAPON_SPRITE_SIZE, WEAPON_SPRITE_SIZE },
			{ 686, 250,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(
			TextFormat("%d", std::get<2>(weapon_icons[std::get<0>(GetCombinationtype(selected_weapon))])),
			686,
			250 + ITEM_ICON_SIZE,
			18,
			BLACK
		);
		DrawTexturePro(
			std::get<0>(orb_icons[std::get<1>(GetCombinationtype(selected_weapon))]),
			{ 0,0,ITEM_ICON_SIZE, ITEM_ICON_SIZE },
			{ 842, 250,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(
			TextFormat("%d", std::get<2>(orb_icons[std::get<1>(GetCombinationtype(selected_weapon))])),
			842,
			250 + ITEM_ICON_SIZE,
			18,
			BLACK
		);
		break;
	case Shop::ORB:
		for (int i = COMMON_LIFEORB; i < NONE_ORB; i++) {
			DrawTexturePro(
				std::get<0>(orb_icons[static_cast<OrbId>(i)]),
				{ 0,0,ITEM_ICON_SIZE, ITEM_ICON_SIZE },
				std::get<1>(orb_icons[static_cast<OrbId>(i)]),
				{ 0,0 },
				0,
				WHITE
			);
			DrawText(
				TextFormat("%d", std::get<2>(orb_icons[static_cast<OrbId>(i)])),
				std::get<1>(orb_icons[static_cast<OrbId>(i)]).x,
				std::get<1>(orb_icons[static_cast<OrbId>(i)]).y + std::get<1>(orb_icons[static_cast<OrbId>(i)]).height,
				18,
				BLACK
			);
		}
		DrawTexturePro(
			std::get<0>(orb_icons[selected_orb]),
			{ 0,0,ITEM_ICON_SIZE, ITEM_ICON_SIZE },
			{ 764, 128,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(
			TextFormat("%d", std::get<2>(orb_icons[selected_orb])),
			764,
			128 + ITEM_ICON_SIZE,
			18,
			BLACK
		);
		DrawTexturePro(
			std::get<0>(orb_icons[std::get<0>(GetCombinationtype(selected_orb))]),
			{ 0,0,ITEM_ICON_SIZE, ITEM_ICON_SIZE },
			{ 686, 250,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(
			TextFormat("%d", std::get<2>(orb_icons[std::get<0>(GetCombinationtype(selected_orb))])),
			686,
			250 + ITEM_ICON_SIZE,
			18,
			BLACK
		);
		DrawTexturePro(
			std::get<0>(orb_icons[std::get<1>(GetCombinationtype(selected_orb))]),
			{ 0,0,ITEM_ICON_SIZE, ITEM_ICON_SIZE },
			{ 842, 250,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(
			TextFormat("%d", std::get<2>(orb_icons[std::get<1>(GetCombinationtype(selected_orb))])),
			842,
			250 + ITEM_ICON_SIZE,
			18,
			BLACK
		);
		
		break;
	default:
		break;
	}
	
}