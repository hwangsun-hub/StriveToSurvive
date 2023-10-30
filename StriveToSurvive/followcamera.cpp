#include "library.h"

Camera2D FollowCamera::GetCamera() {
	return camera;
}

void FollowCamera::Update() {
	camera.target = GetPosition();
	if (WORLD_VIEW_DEV) {
		camera.zoom = 5;
	}
	else {
		camera.zoom = 1;
	}
}