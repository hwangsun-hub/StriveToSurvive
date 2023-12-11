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
	if (gamestate == GAMESTATE_SHOPPING) {

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