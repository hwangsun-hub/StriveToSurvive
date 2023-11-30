#include "library.h"

TileMap::TileMap(Player* _player) {
	player = _player;
}

void TileMap::Update() {
	

}

void TileMap::Draw() {
	int x_i = int((int(player->GetPosition().x - TILE_MAP_SIZE / 2) / (TILE_MAP_SIZE)));
	int y_i = int((int(player->GetPosition().y - TILE_MAP_SIZE / 2) / (TILE_MAP_SIZE)));
	DrawTextureV(map, { float(TILE_MAP_SIZE * (x_i - 1)), float(TILE_MAP_SIZE * (y_i - 1)) }, WHITE);
	DrawTextureV(map, { float(TILE_MAP_SIZE * (x_i - 1)), float(TILE_MAP_SIZE * (y_i)) }, WHITE);
	DrawTextureV(map, { float(TILE_MAP_SIZE * (x_i - 1)), float(TILE_MAP_SIZE * (y_i + 1)) }, WHITE);
	DrawTextureV(map, { float(TILE_MAP_SIZE * (x_i )), float(TILE_MAP_SIZE * (y_i - 1)) }, WHITE);
	DrawTextureV(map, { float(TILE_MAP_SIZE * (x_i )), float(TILE_MAP_SIZE * (y_i)) }, WHITE);
	DrawTextureV(map, { float(TILE_MAP_SIZE * (x_i)), float(TILE_MAP_SIZE * (y_i + 1)) }, WHITE);
	DrawTextureV(map, { float(TILE_MAP_SIZE * (x_i + 1)), float(TILE_MAP_SIZE * (y_i - 1)) }, WHITE);
	DrawTextureV(map, { float(TILE_MAP_SIZE * (x_i + 1)), float(TILE_MAP_SIZE * (y_i)) }, WHITE);
	DrawTextureV(map, { float(TILE_MAP_SIZE * (x_i + 1)), float(TILE_MAP_SIZE * (y_i + 1)) }, WHITE);
	
}