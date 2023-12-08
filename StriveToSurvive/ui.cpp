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