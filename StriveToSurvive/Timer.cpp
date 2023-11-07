#include "library.h"

void Timer::SetTimer(float time) {
	lifetime = time;
}

bool Timer::UpdateTimer() {
	if (lifetime == -1) {
		return false;
	}

	lifetime -= GetFrameTime();

	if (lifetime <= 0) {
		lifetime = -1;
		return true;
	}
	else {
		return false;
	}
}
