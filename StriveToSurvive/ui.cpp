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
	Vector2 icon1 = {24, 28};
	Vector2 icon2 = {112, 28};
	Vector2 icon3 = {200, 28};
	DrawTexturePro(
		ingame_ui_orb_icon1,
		{ 0,0,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 0,0,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		icon1,
		0,
		WHITE
	);

	DrawTexturePro(
		ingame_ui_orb_icon2,
		{ 0,0,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 0,0,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		icon2,
		0,
		WHITE
	);

	DrawTexturePro(
		ingame_ui_orb_icon3,
		{ 0,0,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		{ 0,0,ITEM_ICON_SIZE,ITEM_ICON_SIZE },
		icon3,
		0,
		WHITE
	);


}
void Ui::DrawShopUi() {

}