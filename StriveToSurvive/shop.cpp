#include "library.h"

Shop::Shop(Player* _player) {
	player = _player;
}

void Shop::UpdateUI() {
	//main UI

}

void  Shop::UpdatePlayerBuy() {
	for (int i = 0; i < Icons.size(); i++) {
		if (CheckCollisionPointRec(GetMousePosition(), std::get<2>(Icons[i]))) {
			if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
				if (player->GetMoney() >= std::get<3>(Icons[i])) {
					player->SetWeapon(std::get<0>(Icons[i]));
					player->SetMoney(player->GetMoney() - std::get<3>(Icons[i]));
				}
			}
		}
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