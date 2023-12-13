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
			int price = std::get<2>(weapon_icons[static_cast<WeaponId>(i)]);
			if (std::get<0>(player->GetCombinationtype(static_cast<WeaponId>(i))) == player->GetWeapon()) {
				price -= std::get<2>(weapon_icons[player->GetWeapon()]);
			}
			if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<0>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<0>(player->GetInventoryOrb())]);
			}
			if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<1>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<1>(player->GetInventoryOrb())]);
			}
			if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<2>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<2>(player->GetInventoryOrb())]);
			}

			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(weapon_icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
				selected_weapon = static_cast<WeaponId>(i);
			}

			if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(weapon_icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
				if (player->GetMoney() > price && (player->GetWeapon() == NONE_WEAPON || std::get<0>(player->GetCombinationtype(static_cast<WeaponId>(i))) == player->GetWeapon())) {
					player->SetMoney((player->GetMoney() - price));
					player->SetWeapon(static_cast<WeaponId>(i));
					if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<0>(player->GetInventoryOrb())) {
						player->RemoveInventoryOrb(std::get<0>(player->GetInventoryOrb()));
					}
					if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<1>(player->GetInventoryOrb())) {
						player->RemoveInventoryOrb(std::get<1>(player->GetInventoryOrb()));
					}
					if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<2>(player->GetInventoryOrb())) {
						player->RemoveInventoryOrb(std::get<2>(player->GetInventoryOrb()));
					}
				}
			}
		}
		break;
	case Shop::RANGED:
		for (int i = COMMON_MACHINEGUN_MACHINGUN; i < NONE_WEAPON; i++) {
			{
				int price = std::get<2>(weapon_icons[static_cast<WeaponId>(i)]);
				if (std::get<0>(player->GetCombinationtype(static_cast<WeaponId>(i))) == player->GetWeapon()) {
					price -= std::get<2>(weapon_icons[player->GetWeapon()]);
				}
				if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<0>(player->GetInventoryOrb())) {
					price -= std::get<2>(orb_icons[std::get<0>(player->GetInventoryOrb())]);
				}
				if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<1>(player->GetInventoryOrb())) {
					price -= std::get<2>(orb_icons[std::get<1>(player->GetInventoryOrb())]);
				}
				if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<2>(player->GetInventoryOrb())) {
					price -= std::get<2>(orb_icons[std::get<2>(player->GetInventoryOrb())]);
				}

				if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(weapon_icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					selected_weapon = static_cast<WeaponId>(i);
				}

				if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(weapon_icons[static_cast<WeaponId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
					if (player->GetMoney() > price && (player->GetWeapon() == NONE_WEAPON || std::get<0>(player->GetCombinationtype(static_cast<WeaponId>(i))) == player->GetWeapon())) {
						player->SetMoney((player->GetMoney() - price));
						player->SetWeapon(static_cast<WeaponId>(i));
						if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<0>(player->GetInventoryOrb())) {
							player->RemoveInventoryOrb(std::get<0>(player->GetInventoryOrb()));
						}
						if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<1>(player->GetInventoryOrb())) {
							player->RemoveInventoryOrb(std::get<1>(player->GetInventoryOrb()));
						}
						if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<2>(player->GetInventoryOrb())) {
							player->RemoveInventoryOrb(std::get<2>(player->GetInventoryOrb()));
						}
					}
				}
			}
		}
		break;
	case Shop::ORB:
		for (int i = COMMON_LIFEORB; i < NONE_ORB; i++) {
			{
				{
					int price = std::get<2>(orb_icons[static_cast<OrbId>(i)]);
					if (std::get<0>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<0>(player->GetInventoryOrb())) {
						price -= std::get<2>(orb_icons[std::get<0>(player->GetInventoryOrb())]);
					}
					if (std::get<0>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<1>(player->GetInventoryOrb())) {
						price -= std::get<2>(orb_icons[std::get<1>(player->GetInventoryOrb())]);
					}
					if (std::get<0>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<2>(player->GetInventoryOrb())) {
						price -= std::get<2>(orb_icons[std::get<2>(player->GetInventoryOrb())]);
					}
					if (std::get<1>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<0>(player->GetInventoryOrb())) {
						price -= std::get<2>(orb_icons[std::get<0>(player->GetInventoryOrb())]);
					}
					if (std::get<1>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<1>(player->GetInventoryOrb())) {
						price -= std::get<2>(orb_icons[std::get<1>(player->GetInventoryOrb())]);
					}
					if (std::get<1>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<2>(player->GetInventoryOrb())) {
						price -= std::get<2>(orb_icons[std::get<2>(player->GetInventoryOrb())]);
					}

					if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(orb_icons[static_cast<OrbId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
						selected_orb = static_cast<OrbId>(i);
					}

					if (CheckCollisionPointRec(GetMousePosition(), std::get<1>(orb_icons[static_cast<OrbId>(i)])) && IsMouseButtonPressed(MOUSE_BUTTON_RIGHT)) {
						if (
							player->GetMoney() > price &&
							(
								std::get<0>(player->GetInventoryOrb()) == static_cast<OrbId>(i) ||
								std::get<1>(player->GetInventoryOrb()) == static_cast<OrbId>(i) ||
								std::get<2>(player->GetInventoryOrb()) == static_cast<OrbId>(i) ||
								std::get<0>(player->GetInventoryOrb()) == NONE_ORB ||
								std::get<1>(player->GetInventoryOrb()) == NONE_ORB ||
								std::get<2>(player->GetInventoryOrb()) == NONE_ORB
							)
							) {
							player->SetMoney((player->GetMoney() - price));
							if (std::get<0>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<0>(player->GetInventoryOrb())) {
								player->RemoveInventoryOrb(std::get<0>(player->GetInventoryOrb()));
							}
							else if (std::get<0>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<1>(player->GetInventoryOrb())) {
								player->RemoveInventoryOrb(std::get<1>(player->GetInventoryOrb()));
							}
							else if (std::get<0>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<2>(player->GetInventoryOrb())) {
								player->RemoveInventoryOrb(std::get<2>(player->GetInventoryOrb()));
							}
							if (std::get<1>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<0>(player->GetInventoryOrb())) {
								player->RemoveInventoryOrb(std::get<0>(player->GetInventoryOrb()));
							}
							else if (std::get<1>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<1>(player->GetInventoryOrb())) {
								player->RemoveInventoryOrb(std::get<1>(player->GetInventoryOrb()));
							}
							else if (std::get<1>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<2>(player->GetInventoryOrb())) {
								player->RemoveInventoryOrb(std::get<2>(player->GetInventoryOrb()));
							}
							player->SetInventoryOrb(static_cast<OrbId>(i));
						}
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
	case Shop::MELEE: {
		for (int i = COMMON_KATANA_KATANA; i < COMMON_MACHINEGUN_MACHINGUN; i++) {
			int price = std::get<2>(weapon_icons[static_cast<WeaponId>(i)]);
			if (std::get<0>(player->GetCombinationtype(static_cast<WeaponId>(i))) == player->GetWeapon()) {
				price -= std::get<2>(weapon_icons[player->GetWeapon()]);
			}
			if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<0>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<0>(player->GetInventoryOrb())]);
			}
			if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<1>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<1>(player->GetInventoryOrb())]);
			}
			if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<2>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<2>(player->GetInventoryOrb())]);
			}
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
				TextFormat("%d", price),
				std::get<1>(weapon_icons[static_cast<WeaponId>(i)]).x,
				std::get<1>(weapon_icons[static_cast<WeaponId>(i)]).y + std::get<1>(weapon_icons[static_cast<WeaponId>(i)]).height,
				18,
				BLACK
			);
		}
		int selected_weapon_price = std::get<2>(weapon_icons[selected_weapon]);
		if (std::get<0>(player->GetCombinationtype(selected_weapon)) == player->GetWeapon()) {
			selected_weapon_price -= std::get<2>(weapon_icons[player->GetWeapon()]);
		}
		if (std::get<1>(player->GetCombinationtype(selected_weapon)) == std::get<0>(player->GetInventoryOrb())) {
			selected_weapon_price -= std::get<2>(orb_icons[std::get<0>(player->GetInventoryOrb())]);
		}
		if (std::get<1>(player->GetCombinationtype(selected_weapon)) == std::get<1>(player->GetInventoryOrb())) {
			selected_weapon_price -= std::get<2>(orb_icons[std::get<1>(player->GetInventoryOrb())]);
		}
		if (std::get<1>(player->GetCombinationtype(selected_weapon)) == std::get<2>(player->GetInventoryOrb())) {
			selected_weapon_price -= std::get<2>(orb_icons[std::get<2>(player->GetInventoryOrb())]);
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
			TextFormat("%d", selected_weapon_price),
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
		DrawTexturePro(
			std::get<0>(orb_icons[std::get<1>(GetCombinationtype(selected_weapon))]),
			{ 0,0,ITEM_ICON_SIZE, ITEM_ICON_SIZE },
			{ 842, 250,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
			{ 0,0 },
			0,
			WHITE
		);
		switch (selected_weapon)
		{
		case COMMON_KATANA_KATANA:
			DrawText(TextFormat("Katana"), 678, 420, 31, BLACK);
			DrawText(TextFormat("20"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.5"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_KATANA_TAILWIND:
			DrawText(TextFormat("Tailwind"), 678, 420, 31, BLACK);
			DrawText(TextFormat("30"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.3"), 840, 456, 29, BLACK);
			DrawText(TextFormat("true damage + 10"), 675, 494, 20, BLACK);
			break;
		case UNCOMMON_KATANA_ZERO:
			DrawText(TextFormat("Zero"), 678, 420, 31, BLACK);
			DrawText(TextFormat("60"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.5"), 840, 456, 29, BLACK);
			break;
		case RARE_KATANA_STORMWIND:
			DrawText(TextFormat("Stormwind"), 678, 420, 31, BLACK);
			DrawText(TextFormat("30"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.3"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Add true damage"), 675, 494, 20, BLACK);
			DrawText(TextFormat("proportional to speed"), 675, 514, 20, BLACK);
			break;
		case RARE_KATANA_THUNDER:
			DrawText(TextFormat("Thunder"), 678, 420, 31, BLACK);
			DrawText(TextFormat("60"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.3"), 840, 456, 29, BLACK);
			DrawText(TextFormat("dodge is replaced by"), 675, 494, 20, BLACK);
			DrawText(TextFormat("Special Attack"), 675, 514, 20, BLACK);
			break;
		case RARE_KATANA_MASAMUNE:
			DrawText(TextFormat("Masamune"), 678, 420, 31, BLACK);
			DrawText(TextFormat("85"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.5"), 840, 456, 29, BLACK);
			DrawText(TextFormat("If you do not attack for"), 675, 494, 20, BLACK);
			DrawText(TextFormat("3 seconds, you can use"), 675, 514, 20, BLACK);
			DrawText(TextFormat("a charged attack"), 675, 534, 20, BLACK);
			break;
		case RARE_KATANA_MURAMASA:
			DrawText(TextFormat("Masamune"), 678, 420, 31, BLACK);
			DrawText(TextFormat("100"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.5"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Toggle: Attack speed is"), 675, 494, 20, BLACK);
			DrawText(TextFormat("greatly reduced, but"), 675, 514, 20, BLACK);
			DrawText(TextFormat("blood absorption is"), 675, 534, 20, BLACK);
			DrawText(TextFormat("greatly increased."), 675, 554, 20, BLACK);
			break;
			break;
		case COMMON_GREATSWORD_GREATSWORD:
			DrawText(TextFormat("Greatsword"), 678, 420, 31, BLACK);
			DrawText(TextFormat("50"), 715, 456, 29, BLACK);
			DrawText(TextFormat("1"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_GREATSWORD_KNIGHTLYSWORD:
			DrawText(TextFormat("Knightlysword"), 678, 420, 31, BLACK);
			DrawText(TextFormat("150"), 715, 456, 29, BLACK);
			DrawText(TextFormat("1"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_GREATSWORD_BLOODSWORD:
			DrawText(TextFormat("Bloodsword"), 678, 420, 31, BLACK);
			DrawText(TextFormat("120"), 715, 456, 29, BLACK);
			DrawText(TextFormat("1"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Recovers health every"), 675, 494, 20, BLACK);
			DrawText(TextFormat("time you kill an enemy"), 675, 514, 20, BLACK);
			break;
		case RARE_GREATSWORD_BLACKKNIGHT:
			DrawText(TextFormat("BlackKnight"), 678, 420, 31, BLACK);
			DrawText(TextFormat("175"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.75"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Gain attack power and"), 675, 494, 20, BLACK);
			DrawText(TextFormat("blood absorption in"), 675, 514, 20, BLACK);
			DrawText(TextFormat("proportion to"), 675, 534, 20, BLACK);
			DrawText(TextFormat("reduced health"), 675, 554, 20, BLACK);
			break;
		case RARE_GREATSWORD_WHITEKNIGHT:
			DrawText(TextFormat("WhiteKnight"), 678, 420, 31, BLACK);
			DrawText(TextFormat("175"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.75"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Gain damage equal to"), 675, 494, 20, BLACK);
			DrawText(TextFormat("defense power"), 675, 514, 20, BLACK);
			DrawText(TextFormat("However, it cannot"), 675, 534, 20, BLACK);
			DrawText(TextFormat("absorb blood"), 675, 554, 20, BLACK);
			break;
		case RARE_GREATSWORD_VAMPIRE:
			DrawText(TextFormat("Vampire"), 678, 420, 31, BLACK);
			DrawText(TextFormat("150"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.75"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Every time you kill"), 675, 494, 20, BLACK);
			DrawText(TextFormat("an enemy, your"), 675, 514, 20, BLACK);
			DrawText(TextFormat("blood absorption"), 675, 534, 20, BLACK);
			DrawText(TextFormat("increases"), 675, 554, 20, BLACK);
			break;
		case RARE_GREATSWORD_BERSERKER:
			DrawText(TextFormat("Berserker"), 678, 420, 31, BLACK);
			DrawText(TextFormat("150"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.75"), 840, 456, 29, BLACK);
			DrawText(TextFormat("When health falls below 50,"), 675, 494, 18, BLACK);
			DrawText(TextFormat("it fills up and roars."), 675, 514, 18, BLACK);
			DrawText(TextFormat("Damage is"), 675, 534, 18, BLACK);
			DrawText(TextFormat("permanently doubled."), 675, 554, 18, BLACK);
			break;
		case COMMON_MACHINEGUN_MACHINGUN:
			DrawText(TextFormat("Machinegun"), 678, 420, 31, BLACK);
			DrawText(TextFormat("20"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.3"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_MACHINEGUN_LIGHTMACHINEGUN:
			DrawText(TextFormat("Lightmachinegun"), 678, 420, 31, BLACK);
			DrawText(TextFormat("35"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.2"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_MACHINEGUN_HEAVYMACHINEGUN:
			DrawText(TextFormat("Heavymachinegun"), 678, 420, 31, BLACK);
			DrawText(TextFormat("50"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.3"), 840, 456, 29, BLACK);
			break;
		case RARE_MACHINEGUN_KRAKEN:
			DrawText(TextFormat("Kraken"), 678, 420, 31, BLACK);
			DrawText(TextFormat("40"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.2"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Every 50 enemies you kill"), 675, 494, 18, BLACK);
			DrawText(TextFormat("permanently increases"), 675, 514, 18, BLACK);
			DrawText(TextFormat(" your speed."), 675, 534, 18, BLACK);
			DrawText(TextFormat("Gain true damage proportional"), 675, 554, 18, BLACK);
			DrawText(TextFormat("to increased movement speed."), 675, 574, 18, BLACK);
			break;
		case RARE_MACHINEGUN_VOID:
			DrawText(TextFormat("Void"), 678, 420, 31, BLACK);
			DrawText(TextFormat("35"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.2"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Each time you take"), 675, 494, 20, BLACK);
			DrawText(TextFormat("damage, your"), 675, 514, 20, BLACK);
			DrawText(TextFormat("damage increases."), 675, 534, 20, BLACK);
			break;
		case RARE_MACHINEGUN_REPENTENCE:
			DrawText(TextFormat("Repentence"), 678, 420, 31, BLACK);
			DrawText(TextFormat("50"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.25"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Toggle: All of your"), 675, 494, 18, BLACK);
			DrawText(TextFormat("blood absorption is converted"), 675, 514, 18, BLACK);
			DrawText(TextFormat("to defense, damage"), 675, 534, 18, BLACK);
			break;
		case RARE_MACHINEGUN_WILD:
			DrawText(TextFormat("Kraken"), 678, 420, 31, BLACK);
			DrawText(TextFormat("80"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.3"), 840, 456, 29, BLACK);
			DrawText(TextFormat("roars every time"), 675, 494, 20, BLACK);
			DrawText(TextFormat("takes damage."), 675, 514, 20, BLACK);
			break;
		case COMMON_SNIPERRIFLE_SNIPERRIFLE:
			DrawText(TextFormat("Sniper rifle"), 678, 420, 31, BLACK);
			DrawText(TextFormat("40"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.6"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_SNIPERRIFLE_BOLTACTION:
			DrawText(TextFormat("Boltaction"), 678, 420, 31, BLACK);
			DrawText(TextFormat("100"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.6"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_SNIPERRIFLE_SEMIAUTO:
			DrawText(TextFormat("Semiauto"), 678, 420, 31, BLACK);
			DrawText(TextFormat("75"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.45"), 840, 456, 29, BLACK);
			break;
		case RARE_SNIPERRIFLE_RAILGUN:
			DrawText(TextFormat("Railgun"), 678, 420, 31, BLACK);
			DrawText(TextFormat("500"), 715, 456, 29, BLACK);
			DrawText(TextFormat("2"), 840, 456, 29, BLACK);
			DrawText(TextFormat("The bullet penetrates"), 675, 494, 20, BLACK);
			DrawText(TextFormat("the enemy"), 675, 514, 20, BLACK);
			break;
		case RARE_SNIPERRIFLE_PIRACY:
			DrawText(TextFormat("Piracy"), 678, 420, 31, BLACK);
			DrawText(TextFormat("200"), 715, 456, 29, BLACK);
			DrawText(TextFormat("1"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Instead of gaining damage"), 675, 494, 18, BLACK);
			DrawText(TextFormat("proportional to attack speed,"), 675, 514, 18, BLACK);
			DrawText(TextFormat("attack speed is fixed."), 675, 534, 18, BLACK);
			break;
		case RARE_SNIPERRIFLE_CATERPILLAR:
			DrawText(TextFormat("Caterpillar"), 678, 420, 31, BLACK);
			DrawText(TextFormat("80"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.4"), 840, 456, 29, BLACK);
			DrawText(TextFormat("After dodging, the next attack"), 675, 494, 18, BLACK);
			DrawText(TextFormat("gains additional damage."), 675, 514, 18, BLACK);
			break;
		case RARE_SNIPERRIFLE_MAGICENGINEERING:
			DrawText(TextFormat("Magicengineering"), 678, 420, 31, BLACK);
			DrawText(TextFormat("80"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.4"), 840, 456, 29, BLACK);
			DrawText(TextFormat("If you do not attack"), 675, 494, 18, BLACK);
			DrawText(TextFormat("for 3 seconds,"), 675, 514, 18, BLACK);
			DrawText(TextFormat("damage increases on"), 675, 534, 18, BLACK);
			DrawText(TextFormat("the next attack."), 675, 554, 18, BLACK);
			break;
		case NONE_WEAPON:
			break;
		default:
			break;
		}
	}
		
		break;
	case Shop::RANGED: {
		for (int i = COMMON_MACHINEGUN_MACHINGUN; i < NONE_WEAPON; i++) {
			int price = std::get<2>(weapon_icons[static_cast<WeaponId>(i)]);
			if (std::get<0>(player->GetCombinationtype(static_cast<WeaponId>(i))) == player->GetWeapon()) {
				price -= std::get<2>(weapon_icons[player->GetWeapon()]);
			}
			if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<0>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<0>(player->GetInventoryOrb())]);
			}
			if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<1>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<1>(player->GetInventoryOrb())]);
			}
			if (std::get<1>(player->GetCombinationtype(static_cast<WeaponId>(i))) == std::get<2>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<2>(player->GetInventoryOrb())]);
			}
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
				TextFormat("%d", price),
				std::get<1>(weapon_icons[static_cast<WeaponId>(i)]).x,
				std::get<1>(weapon_icons[static_cast<WeaponId>(i)]).y + std::get<1>(weapon_icons[static_cast<WeaponId>(i)]).height,
				18,
				BLACK
			);
		}
		int selected_weapon_price = std::get<2>(weapon_icons[selected_weapon]);
		if (std::get<0>(player->GetCombinationtype(selected_weapon)) == player->GetWeapon()) {
			selected_weapon_price -= std::get<2>(weapon_icons[player->GetWeapon()]);
		}
		if (std::get<1>(player->GetCombinationtype(selected_weapon)) == std::get<0>(player->GetInventoryOrb())) {
			selected_weapon_price -= std::get<2>(orb_icons[std::get<0>(player->GetInventoryOrb())]);
		}
		if (std::get<1>(player->GetCombinationtype(selected_weapon)) == std::get<1>(player->GetInventoryOrb())) {
			selected_weapon_price -= std::get<2>(orb_icons[std::get<1>(player->GetInventoryOrb())]);
		}
		if (std::get<1>(player->GetCombinationtype(selected_weapon)) == std::get<2>(player->GetInventoryOrb())) {
			selected_weapon_price -= std::get<2>(orb_icons[std::get<2>(player->GetInventoryOrb())]);
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
			TextFormat("%d", selected_weapon_price),
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
		DrawTexturePro(
			std::get<0>(orb_icons[std::get<1>(GetCombinationtype(selected_weapon))]),
			{ 0,0,ITEM_ICON_SIZE, ITEM_ICON_SIZE },
			{ 842, 250,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
			{ 0,0 },
			0,
			WHITE
		);
		switch (selected_weapon)
		{
		case COMMON_KATANA_KATANA:
			DrawText(TextFormat("Katana"), 678, 420, 31, BLACK);
			DrawText(TextFormat("20"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.5"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_KATANA_TAILWIND:
			DrawText(TextFormat("Tailwind"), 678, 420, 31, BLACK);
			DrawText(TextFormat("30"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.3"), 840, 456, 29, BLACK);
			DrawText(TextFormat("true damage + 10"), 675, 494, 20, BLACK);
			break;
		case UNCOMMON_KATANA_ZERO:
			DrawText(TextFormat("Zero"), 678, 420, 31, BLACK);
			DrawText(TextFormat("60"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.5"), 840, 456, 29, BLACK);
			break;
		case RARE_KATANA_STORMWIND:
			DrawText(TextFormat("Stormwind"), 678, 420, 31, BLACK);
			DrawText(TextFormat("30"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.3"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Add true damage"), 675, 494, 20, BLACK);
			DrawText(TextFormat("proportional to speed"), 675, 514, 20, BLACK);
			break;
		case RARE_KATANA_THUNDER:
			DrawText(TextFormat("Thunder"), 678, 420, 31, BLACK);
			DrawText(TextFormat("60"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.3"), 840, 456, 29, BLACK);
			DrawText(TextFormat("dodge is replaced by"), 675, 494, 20, BLACK);
			DrawText(TextFormat("Special Attack"), 675, 514, 20, BLACK);
			break;
		case RARE_KATANA_MASAMUNE:
			DrawText(TextFormat("Masamune"), 678, 420, 31, BLACK);
			DrawText(TextFormat("85"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.5"), 840, 456, 29, BLACK);
			DrawText(TextFormat("If you do not attack for"), 675, 494, 20, BLACK);
			DrawText(TextFormat("3 seconds, you can use"), 675, 514, 20, BLACK);
			DrawText(TextFormat("a charged attack"), 675, 534, 20, BLACK);
			break;
		case RARE_KATANA_MURAMASA:
			DrawText(TextFormat("Masamune"), 678, 420, 31, BLACK);
			DrawText(TextFormat("100"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.5"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Toggle: Attack speed is"), 675, 494, 20, BLACK);
			DrawText(TextFormat("greatly reduced, but"), 675, 514, 20, BLACK);
			DrawText(TextFormat("blood absorption is"), 675, 534, 20, BLACK);
			DrawText(TextFormat("greatly increased."), 675, 554, 20, BLACK);
			break;
			break;
		case COMMON_GREATSWORD_GREATSWORD:
			DrawText(TextFormat("Greatsword"), 678, 420, 31, BLACK);
			DrawText(TextFormat("50"), 715, 456, 29, BLACK);
			DrawText(TextFormat("1"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_GREATSWORD_KNIGHTLYSWORD:
			DrawText(TextFormat("Knightlysword"), 678, 420, 31, BLACK);
			DrawText(TextFormat("150"), 715, 456, 29, BLACK);
			DrawText(TextFormat("1"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_GREATSWORD_BLOODSWORD:
			DrawText(TextFormat("Bloodsword"), 678, 420, 31, BLACK);
			DrawText(TextFormat("120"), 715, 456, 29, BLACK);
			DrawText(TextFormat("1"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Recovers health every"), 675, 494, 20, BLACK);
			DrawText(TextFormat("time you kill an enemy"), 675, 514, 20, BLACK);
			break;
		case RARE_GREATSWORD_BLACKKNIGHT:
			DrawText(TextFormat("BlackKnight"), 678, 420, 31, BLACK);
			DrawText(TextFormat("175"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.75"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Gain attack power and"), 675, 494, 20, BLACK);
			DrawText(TextFormat("blood absorption in"), 675, 514, 20, BLACK);
			DrawText(TextFormat("proportion to"), 675, 534, 20, BLACK);
			DrawText(TextFormat("reduced health"), 675, 554, 20, BLACK);
			break;
		case RARE_GREATSWORD_WHITEKNIGHT:
			DrawText(TextFormat("WhiteKnight"), 678, 420, 31, BLACK);
			DrawText(TextFormat("175"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.75"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Gain damage equal to"), 675, 494, 20, BLACK);
			DrawText(TextFormat("defense power"), 675, 514, 20, BLACK);
			DrawText(TextFormat("However, it cannot"), 675, 534, 20, BLACK);
			DrawText(TextFormat("absorb blood"), 675, 554, 20, BLACK);
			break;
		case RARE_GREATSWORD_VAMPIRE:
			DrawText(TextFormat("Vampire"), 678, 420, 31, BLACK);
			DrawText(TextFormat("150"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.75"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Every time you kill"), 675, 494, 20, BLACK);
			DrawText(TextFormat("an enemy, your"), 675, 514, 20, BLACK);
			DrawText(TextFormat("blood absorption"), 675, 534, 20, BLACK);
			DrawText(TextFormat("increases"), 675, 554, 20, BLACK);
			break;
		case RARE_GREATSWORD_BERSERKER:
			DrawText(TextFormat("Berserker"), 678, 420, 31, BLACK);
			DrawText(TextFormat("150"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.75"), 840, 456, 29, BLACK);
			DrawText(TextFormat("When health falls below 50,"), 675, 494, 18, BLACK);
			DrawText(TextFormat("it fills up and roars."), 675, 514, 18, BLACK);
			DrawText(TextFormat("Damage is"), 675, 534, 18, BLACK);
			DrawText(TextFormat("permanently doubled."), 675, 554, 18, BLACK);
			break;
		case COMMON_MACHINEGUN_MACHINGUN:
			DrawText(TextFormat("Machinegun"), 678, 420, 31, BLACK);
			DrawText(TextFormat("20"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.3"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_MACHINEGUN_LIGHTMACHINEGUN:
			DrawText(TextFormat("Lightmachinegun"), 678, 420, 31, BLACK);
			DrawText(TextFormat("35"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.2"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_MACHINEGUN_HEAVYMACHINEGUN:
			DrawText(TextFormat("Heavymachinegun"), 678, 420, 31, BLACK);
			DrawText(TextFormat("50"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.3"), 840, 456, 29, BLACK);
			break;
		case RARE_MACHINEGUN_KRAKEN:
			DrawText(TextFormat("Kraken"), 678, 420, 31, BLACK);
			DrawText(TextFormat("40"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.2"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Every 50 enemies you kill"), 675, 494, 18, BLACK);
			DrawText(TextFormat("permanently increases"), 675, 514, 18, BLACK);
			DrawText(TextFormat(" your speed."), 675, 534, 18, BLACK);
			DrawText(TextFormat("Gain true damage proportional"), 675, 554, 18, BLACK);
			DrawText(TextFormat("to increased movement speed."), 675, 574, 18, BLACK);
			break;
		case RARE_MACHINEGUN_VOID:
			DrawText(TextFormat("Void"), 678, 420, 31, BLACK);
			DrawText(TextFormat("35"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.2"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Each time you take"), 675, 494, 20, BLACK);
			DrawText(TextFormat("damage, your"), 675, 514, 20, BLACK);
			DrawText(TextFormat("damage increases."), 675, 534, 20, BLACK);
			break;
		case RARE_MACHINEGUN_REPENTENCE:
			DrawText(TextFormat("Repentence"), 678, 420, 31, BLACK);
			DrawText(TextFormat("50"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.25"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Toggle: All of your"), 675, 494, 18, BLACK);
			DrawText(TextFormat("blood absorption is converted"), 675, 514, 18, BLACK);
			DrawText(TextFormat("to defense, damage"), 675, 534, 18, BLACK);
			break;
		case RARE_MACHINEGUN_WILD:
			DrawText(TextFormat("Kraken"), 678, 420, 31, BLACK);
			DrawText(TextFormat("80"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.3"), 840, 456, 29, BLACK);
			DrawText(TextFormat("roars every time"), 675, 494, 20, BLACK);
			DrawText(TextFormat("takes damage."), 675, 514, 20, BLACK);
			break;
		case COMMON_SNIPERRIFLE_SNIPERRIFLE:
			DrawText(TextFormat("Sniper rifle"), 678, 420, 31, BLACK);
			DrawText(TextFormat("40"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.6"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_SNIPERRIFLE_BOLTACTION:
			DrawText(TextFormat("Boltaction"), 678, 420, 31, BLACK);
			DrawText(TextFormat("100"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.6"), 840, 456, 29, BLACK);
			break;
		case UNCOMMON_SNIPERRIFLE_SEMIAUTO:
			DrawText(TextFormat("Semiauto"), 678, 420, 31, BLACK);
			DrawText(TextFormat("75"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.45"), 840, 456, 29, BLACK);
			break;
		case RARE_SNIPERRIFLE_RAILGUN:
			DrawText(TextFormat("Railgun"), 678, 420, 31, BLACK);
			DrawText(TextFormat("500"), 715, 456, 29, BLACK);
			DrawText(TextFormat("2"), 840, 456, 29, BLACK);
			DrawText(TextFormat("The bullet penetrates"), 675, 494, 20, BLACK);
			DrawText(TextFormat("the enemy"), 675, 514, 20, BLACK);
			break;
		case RARE_SNIPERRIFLE_PIRACY:
			DrawText(TextFormat("Piracy"), 678, 420, 31, BLACK);
			DrawText(TextFormat("200"), 715, 456, 29, BLACK);
			DrawText(TextFormat("1"), 840, 456, 29, BLACK);
			DrawText(TextFormat("Instead of gaining damage"), 675, 494, 18, BLACK);
			DrawText(TextFormat("proportional to attack speed,"), 675, 514, 18, BLACK);
			DrawText(TextFormat("attack speed is fixed."), 675, 534, 18, BLACK);
			break;
		case RARE_SNIPERRIFLE_CATERPILLAR:
			DrawText(TextFormat("Caterpillar"), 678, 420, 31, BLACK);
			DrawText(TextFormat("80"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.4"), 840, 456, 29, BLACK);
			DrawText(TextFormat("After dodging, the next attack"), 675, 494, 18, BLACK);
			DrawText(TextFormat("gains additional damage."), 675, 514, 18, BLACK);
			break;
		case RARE_SNIPERRIFLE_MAGICENGINEERING:
			DrawText(TextFormat("Magicengineering"), 678, 420, 31, BLACK);
			DrawText(TextFormat("80"), 715, 456, 29, BLACK);
			DrawText(TextFormat("0.4"), 840, 456, 29, BLACK);
			DrawText(TextFormat("If you do not attack"), 675, 494, 18, BLACK);
			DrawText(TextFormat("for 3 seconds,"), 675, 514, 18, BLACK);
			DrawText(TextFormat("damage increases on"), 675, 534, 18, BLACK);
			DrawText(TextFormat("the next attack."), 675, 554, 18, BLACK);
			break;
		case NONE_WEAPON:
			break;
		default:
			break;
		}
	}
		break;
	case Shop::ORB: {
		for (int i = COMMON_LIFEORB; i < NONE_ORB; i++) {
			int price = std::get<2>(orb_icons[static_cast<OrbId>(i)]);
			if (std::get<0>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<0>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<0>(player->GetInventoryOrb())]);
			}
			if (std::get<0>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<1>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<1>(player->GetInventoryOrb())]);
			}
			if (std::get<0>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<2>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<2>(player->GetInventoryOrb())]);
			}
			if (std::get<1>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<0>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<0>(player->GetInventoryOrb())]);
			}
			if (std::get<1>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<1>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<1>(player->GetInventoryOrb())]);
			}
			if (std::get<1>(player->GetCombinationtype(static_cast<OrbId>(i))) == std::get<2>(player->GetInventoryOrb())) {
				price -= std::get<2>(orb_icons[std::get<2>(player->GetInventoryOrb())]);
			}
			DrawTexturePro(
				std::get<0>(orb_icons[static_cast<OrbId>(i)]),
				{ 0,0,ITEM_ICON_SIZE, ITEM_ICON_SIZE },
				std::get<1>(orb_icons[static_cast<OrbId>(i)]),
				{ 0,0 },
				0,
				WHITE
			);
			DrawText(
				TextFormat("%d", price),
				std::get<1>(orb_icons[static_cast<OrbId>(i)]).x,
				std::get<1>(orb_icons[static_cast<OrbId>(i)]).y + std::get<1>(orb_icons[static_cast<OrbId>(i)]).height,
				18,
				BLACK
			);
		}
		int selected_orb_price = std::get<2>(orb_icons[selected_orb]);
		if (std::get<0>(player->GetCombinationtype(selected_orb)) == std::get<0>(player->GetInventoryOrb())) {
			selected_orb_price -= std::get<2>(orb_icons[std::get<0>(player->GetInventoryOrb())]);
		}
		if (std::get<0>(player->GetCombinationtype(selected_orb)) == std::get<1>(player->GetInventoryOrb())) {
			selected_orb_price -= std::get<2>(orb_icons[std::get<1>(player->GetInventoryOrb())]);
		}
		if (std::get<0>(player->GetCombinationtype(selected_orb)) == std::get<2>(player->GetInventoryOrb())) {
			selected_orb_price -= std::get<2>(orb_icons[std::get<2>(player->GetInventoryOrb())]);
		}
		if (std::get<1>(player->GetCombinationtype(selected_orb)) == std::get<0>(player->GetInventoryOrb())) {
			selected_orb_price -= std::get<2>(orb_icons[std::get<0>(player->GetInventoryOrb())]);
		}
		if (std::get<1>(player->GetCombinationtype(selected_orb)) == std::get<1>(player->GetInventoryOrb())) {
			selected_orb_price -= std::get<2>(orb_icons[std::get<1>(player->GetInventoryOrb())]);
		}
		if (std::get<1>(player->GetCombinationtype(selected_orb)) == std::get<2>(player->GetInventoryOrb())) {
			selected_orb_price -= std::get<2>(orb_icons[std::get<2>(player->GetInventoryOrb())]);
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
			TextFormat("%d", selected_orb_price),
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
		DrawTexturePro(
			std::get<0>(orb_icons[std::get<1>(GetCombinationtype(selected_orb))]),
			{ 0,0,ITEM_ICON_SIZE, ITEM_ICON_SIZE },
			{ 842, 250,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
			{ 0,0 },
			0,
			WHITE
		);
		switch (selected_orb)
		{
		case COMMON_LIFEORB:
			DrawText(TextFormat("LIFE ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("recovery + 1"), 678, 456, 29, BLACK);
			break;
		case COMMON_IRONORB:
			DrawText(TextFormat("IRON ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("defense + 10"), 678, 456, 29, BLACK);
			break;
		case COMMON_SPRINGORB:
			DrawText(TextFormat("SPRING ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("Knockback + 50%%"), 678, 456, 29, BLACK);
			break;
		case COMMON_ANGERORB:
			DrawText(TextFormat("ANGER ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("damage + 25%%"), 678, 456, 29, BLACK);
			break;
		case COMMON_WATERORB:
			DrawText(TextFormat("WATER ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("attack speed + 25%%"), 678, 456, 29, BLACK);
			break;
		case COMMON_BLOODORB:
			DrawText(TextFormat("BLOOD ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("drain + 2%%"), 678, 456, 29, BLACK);
			break;
		case COMMON_WINDORB:
			DrawText(TextFormat("WIND ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("speed + 25%%"), 678, 456, 29, BLACK);
			break;
		case COMMON_RANGEORB:
			DrawText(TextFormat("RANGE ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("range + 25%%"), 678, 456, 29, BLACK);
			break;
		case UNCOMMON_ARMORORB:
			DrawText(TextFormat("ARMOR ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("true defense + 2"), 678, 456, 29, BLACK);
			DrawText(TextFormat("recovery + 2"), 678, 485, 29, BLACK);
			DrawText(TextFormat("defense + 20"), 678, 514, 29, BLACK);
			break;
		case UNCOMMON_TRANSFUSIONORB:
			DrawText(TextFormat("BLOOOOD ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("recovery + 3"), 678, 456, 29, BLACK);
			DrawText(TextFormat("drain + 3%%"), 678, 485, 29, BLACK);
			break;
		case UNCOMMON_ROARORB:
			DrawText(TextFormat("ROAR ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("knockback + 50%%"), 678, 456, 29, BLACK);
			DrawText(TextFormat("range + 25%%"), 678, 485, 29, BLACK);
			break;
		case UNCOMMON_RAGEORB:
			DrawText(TextFormat("RAGE ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("damage + 30%%"), 678, 456, 29, BLACK);
			DrawText(TextFormat("defense + 10"), 678, 485, 29, BLACK);
			break;
		case UNCOMMON_SEAORB:
			DrawText(TextFormat("SEA ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("speed + 30%"), 678, 456, 29, BLACK);
			DrawText(TextFormat("attack speed + 30%%"), 678, 485, 29, BLACK);
			break;
		case UNCOMMON_HUNGERORB:
			DrawText(TextFormat("HUNGER ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("drain + 3%%"), 678, 456, 29, BLACK);
			break;
		case UNCOMMON_SWIFTNESSORB:
			DrawText(TextFormat("SWIFTNESS ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("dodge cooltime - 50%%"), 678, 456, 29, BLACK);
			DrawText(TextFormat("speed + 65%%"), 678, 485, 29, BLACK);
			break;
		case UNCOMMON_CHARGEORB:
			DrawText(TextFormat("CHARGE ORB"), 678, 420, 31, BLACK);
			DrawText(TextFormat("Can use charged attacks"), 678, 456, 20, BLACK);
			break;
		case NONE_ORB:
			break;
		default:
			break;
		}
	}
		
		break;
	default:
		break;
	}
	
}