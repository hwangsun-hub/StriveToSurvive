#include "library.h"


Camera2D FollowCamera::GetCamera() {
	return camera;
}

void FollowCamera::Update() {

	camera.target = player->GetPosition();
}