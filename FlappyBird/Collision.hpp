#pragma once

#include "SDL.h"

class Collision {
public:
	static bool AABB(SDL_Rect& a, SDL_Rect& b) {
		return (a.x + a.w > b.x) &&
			(a.y + a.h > b.y) &&
			(b.x + b.w > a.x) &&
			(b.y + b.h > a.y);
	}
};