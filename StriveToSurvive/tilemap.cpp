#include "library.h"

TileMap::TileMap(Player* _player) {
	player = _player;
}

void TileMap::Update() {
	

}

void TileMap::Draw() {
	DrawTextureV(map, { -TILE_MAP_SIZE, -TILE_MAP_SIZE }, WHITE);
	DrawTextureV(map, { 0, -TILE_MAP_SIZE }, WHITE);
	DrawTextureV(map, { -TILE_MAP_SIZE, 0 }, WHITE);
	DrawTextureV(map, { 0, 0 }, WHITE);
}