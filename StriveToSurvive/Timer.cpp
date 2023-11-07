#include "library.h"

void Timer::SetTimer(float time) {
	if (!istimerseting) {
		istimerseting = true;
		lifetime = time;
	}
}

void Timer::UpdateTimer() {
	lifetime -= GetFrameTime();
}

bool Timer::TimerDone() {
	if (istimerseting && lifetime <= 0) {
		istimerseting = false;
		return true;
	}
	else {
		return false;
	}
}

