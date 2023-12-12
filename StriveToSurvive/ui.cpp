#include "library.h"

Ui::Ui(Player* _player) {
	player = _player;
	ingame_ui_orb_icon1 = player->GetOrbIcon(std::get<0>(player->GetInventoryOrb()));
	ingame_ui_orb_icon2 = player->GetOrbIcon(std::get<1>(player->GetInventoryOrb()));
	ingame_ui_orb_icon3 = player->GetOrbIcon(std::get<2>(player->GetInventoryOrb()));
	ingame_ui_weapon_icon = player->GetWeaponIcon(player->GetWeapon());
}

void Ui::UpdateIngameUi() {
	ingame_ui_orb_icon1 = player->GetOrbIcon(std::get<0>(player->GetInventoryOrb()));
	ingame_ui_orb_icon2 = player->GetOrbIcon(std::get<1>(player->GetInventoryOrb()));
	ingame_ui_orb_icon3 = player->GetOrbIcon(std::get<2>(player->GetInventoryOrb()));
	ingame_ui_weapon_icon = player->GetWeaponIcon(player->GetWeapon());
}

void Ui::UpdateShopUi() {
	ingame_ui_orb_icon1 = player->GetOrbIcon(std::get<0>(player->GetInventoryOrb()));
	ingame_ui_orb_icon2 = player->GetOrbIcon(std::get<1>(player->GetInventoryOrb()));
	ingame_ui_orb_icon3 = player->GetOrbIcon(std::get<2>(player->GetInventoryOrb()));
	ingame_ui_weapon_icon = player->GetWeaponIcon(player->GetWeapon());
}

void Ui::UpdateBeforeGameUi() {
	switch (talent)
	{
	case Ui::NORMAL:
		if (CheckCollisionPointRec(GetMousePosition(), { 130, 242, 133, 201 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			talent = FORT;
		}
		if (CheckCollisionPointRec(GetMousePosition(), { 1007, 242, 133, 201 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			talent = CELE;
		}
		if (CheckCollisionPointRec(GetMousePosition(), { 557, 504, 133, 201 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			talent = RAGE;
		}
		if (CheckCollisionPointRec(GetMousePosition(), { 569, 10, 117, 120 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			player->damage_coefficient += 0.02f * rage_talent_score;
			if (rage_talent_score >= 5) {
				player->true_damage += 10;
				if (rage_talent_score >= 10) {
					player->drain_life_coefficient += 5;
					if (rage_talent_score >= 20) {
						player->range_coefficient += 1;
					}
				}
			}
			player->defense += 2 * fortification__talent_score;
			if (fortification__talent_score >= 5) {
				player->true_defense += 10;
				if (fortification__talent_score >= 10) {
					player->life_per_second += 5;
					if (fortification__talent_score >= 20) {
						player->knockback_coefficient += 1;
					}
				}
			}
			player->speed_coefficient += 0.02f * celerity__talent_score;
			if (celerity__talent_score >= 5) {
				player->dodge_cooltime_coefficient *= 0.75;
				if (celerity__talent_score >= 10) {
					player->speed_coefficient += 1;
					if (celerity__talent_score >= 20) {
						player->knockback_coefficient -= 0.25;
						player->damage_coefficient -= 0.25;
						player->attack_cooltime_coefficient += 0.5;
					}
				}
			}
			talent = WEAPON_SELECT;
		}
		break;
	case Ui::RAGE:
		if ((CheckCollisionPointRec(GetMousePosition(), { 0, 0, 300, 720 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || (CheckCollisionPointRec(GetMousePosition(), { 980, 0, 300, 720 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
			talent = NORMAL;
		}
		if ((CheckCollisionPointRec(GetMousePosition(), { 619, 633, 38, 38 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
			if (talent_score > 0) {
				if (rage_talent_score <= 20) {
					rage_talent_score++;
					talent_score--;
				}
			}
		}
		if (IsKeyPressed(KEY_R)) {
			talent_score += rage_talent_score;
			rage_talent_score = 0;
		}
		break;
	case Ui::FORT:
		if ((CheckCollisionPointRec(GetMousePosition(), { 0, 0, 300, 720 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || (CheckCollisionPointRec(GetMousePosition(), { 980, 0, 300, 720 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
			talent = NORMAL;
		}
		if ((CheckCollisionPointRec(GetMousePosition(), { 619, 633, 38, 38 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
			if (talent_score > 0) {
				if (fortification__talent_score <= 20) {
					fortification__talent_score++;
					talent_score--;
				}
			}
		}
		if (IsKeyPressed(KEY_R)) {
			talent_score += fortification__talent_score;
			fortification__talent_score = 0;
		}
		break;
	case Ui::CELE:
		if ((CheckCollisionPointRec(GetMousePosition(), { 0, 0, 300, 720 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || (CheckCollisionPointRec(GetMousePosition(), { 980, 0, 300, 720 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
			talent = NORMAL;
		}
		if ((CheckCollisionPointRec(GetMousePosition(), { 619, 633, 38, 38 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
			if (celerity__talent_score <= 20) {
				celerity__talent_score++;
				talent_score--;
			}
		}
		if (IsKeyPressed(KEY_R)) {
			talent_score += celerity__talent_score;
			celerity__talent_score = 0;
		}
		break;
	case Ui::WEAPON_SELECT:
		if ((CheckCollisionPointRec(GetMousePosition(), { 208, 444, 173, 163 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
			player->SetWeapon(COMMON_GREATSWORD_GREATSWORD);
			gamestate = GAMESTATE_INGAME;
			talent = NORMAL;
		}
		if ((CheckCollisionPointRec(GetMousePosition(), { 425, 444, 173, 163 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
			player->SetWeapon(COMMON_KATANA_KATANA);
			gamestate = GAMESTATE_INGAME;
			talent = NORMAL;
		}
		if ((CheckCollisionPointRec(GetMousePosition(), { 647, 444, 173, 163 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
			player->SetWeapon(COMMON_MACHINEGUN_MACHINGUN);
			gamestate = GAMESTATE_INGAME;
			talent = NORMAL;
		}
		if ((CheckCollisionPointRec(GetMousePosition(), { 864, 444, 173, 163 }) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))) {
			player->SetWeapon(COMMON_SNIPERRIFLE_SNIPERRIFLE);
			gamestate = GAMESTATE_INGAME;
			talent = NORMAL;
		}
		break;
	default:
		break;
	}
}

void Ui::UpdateGameoverUi() {
	if (IsKeyPressed(KEY_SPACE)) {
		gamestate = GAMESTATE_TITLE;
		talent_score += int(player->killcount / 500);
		if (talent_score >= 35) {
			talent_score = 35;
		}
		player->killcount = 0;
	}
}

void Ui::DrawIngameUi() {
	DrawTexturePro(
		ingame_ui,
		{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
		{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
		{ 0,0 },
		0,
		WHITE
	);
	DrawText(
		TextFormat("%6d", player->GetMoney()),
		1016,
		9,
		55,
		BLACK
	);
	DrawText(
		TextFormat("%6d", player->GetKillcount()),
		1016,
		84,
		55,
		BLACK
	);
	DrawTexturePro(
		ingame_ui_orb_icon1,
		{ 0,0,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 24,28,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{0,0},
		0,
		WHITE
	);

	DrawTexturePro(
		ingame_ui_orb_icon2,
		{ 0,0,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 112,28,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 0,0 },
		0,
		WHITE
	);

	DrawTexturePro(
		ingame_ui_orb_icon3,
		{ 0,0,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 200,28,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 0,0 },
		0,
		WHITE
	);
	DrawTextEx(GetFontDefault(), TextFormat("WAVE%2d", wave_level), Vector2Subtract({ WINDOW_START_WIDTH / 2, 70}, Vector2Divide(MeasureTextEx(GetFontDefault(), TextFormat("WAVE%2d", wave_level), 80, 10), { 2,2 })), 80, 10, BLACK);
	int fontsize = 45;
	if (IsKeyDown(KEY_C)) {
		DrawTexturePro(
			stat_ui,
			{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
			{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(TextFormat("%3d", (int)player->GetStat(DAMAGE)), 56, 496, fontsize, WHITE);
		DrawText(TextFormat("%0.2f", player->GetStat(ATTACK_SPEED)), 186, 496, fontsize, WHITE);
		DrawText(TextFormat("%3d", (int)player->GetStat(TRUE_DAMAGE)), 56, 551, fontsize, WHITE);
		DrawText(TextFormat("%3d", (int)player->GetStat(DRAIN)), 186, 551, fontsize, WHITE);
		DrawText(TextFormat("%3d", (int)player->GetStat(DEFENCE)), 56, 616, fontsize, WHITE);
		DrawText(TextFormat("%3d", (int)player->GetStat(HPS)), 186, 616, fontsize, WHITE);
		DrawText(TextFormat("%3d", (int)player->GetStat(RANGE)), 56, 670, fontsize, WHITE);
		DrawText(TextFormat("%3d", (int)player->GetStat(SPEED)), 186, 670, fontsize, WHITE);
	}



}
void Ui::DrawShopUi() {
	DrawTexturePro(
		shop_ui,
		{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
		{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
		{ 0,0 },
		0,
		WHITE
	);
	DrawText(
		TextFormat("%6d", player->GetMoney()),
		1016,
		9,
		55,
		BLACK
	);
	DrawText(
		TextFormat("%6d", player->GetKillcount()),
		1016,
		84,
		55,
		BLACK
	);
	DrawTexturePro(
		ingame_ui_orb_icon1,
		{ 0,0,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 24,28,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 0,0 },
		0,
		WHITE
	);

	DrawTexturePro(
		ingame_ui_orb_icon2,
		{ 0,0,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 112,28,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 0,0 },
		0,
		WHITE
	);

	DrawTexturePro(
		ingame_ui_orb_icon3,
		{ 0,0,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 200,28,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 0,0 },
		0,
		WHITE
	);
	DrawTexturePro(
		player->GetWeaponSprite(player->GetWeapon()),
		{ 0,0,WEAPON_SPRITE_SIZE,WEAPON_SPRITE_SIZE },
		{ 24,112,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{0,0},
		0,
		WHITE
	);
}

void Ui::DrawBeforeGameUi() {
	switch (talent)
	{
	case Ui::NORMAL:
		DrawTexturePro(
			lobby_ui,
			{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
			{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(TextFormat("%2d", fortification__talent_score), 168, 180, 50, WHITE);
		DrawText(TextFormat("%2d", celerity__talent_score), 1046, 180, 50, WHITE);
		DrawText(TextFormat("%2d", rage_talent_score), 596, 448, 50, WHITE);
		DrawText(TextFormat("%2d", talent_score), 585, 347, 75, BLUE);
		break;
	case Ui::RAGE:
		DrawTexturePro(
			rage_ui,
			{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
			{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(TextFormat("%2d", rage_talent_score), 619, 420, 38, BLACK);
		break;
	case Ui::FORT:
		DrawTexturePro(
			fortification_ui,
			{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
			{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(TextFormat("%2d", fortification__talent_score), 619, 420, 38, BLACK);
		break;
	case Ui::CELE:
		DrawTexturePro(
			celerity_ui,
			{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
			{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
			{ 0,0 },
			0,
			WHITE
		);
		DrawText(TextFormat("%2d", celerity__talent_score), 619, 420, 38, BLACK);
		break;
	case Ui::WEAPON_SELECT:
		DrawTexturePro(
			select_weapon_ui,
			{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
			{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
			{ 0,0 },
			0,
			WHITE
		);
		break;
	default:
		break;
	}
}

void Ui::DrawGameoverUi() {
	DrawTexturePro(
		gameover_ui,
		{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
		{ 0,0,WINDOW_START_WIDTH,WINDOW_START_HEIGHT },
		{ 0,0 },
		0,
		WHITE
	);
	//674 343 73
	DrawText(TextFormat("%d", player->killcount), 674, 343, 73, RED);
	DrawText(TextFormat("Press the space bar to restart"), 290, 652, 57, RED);
}