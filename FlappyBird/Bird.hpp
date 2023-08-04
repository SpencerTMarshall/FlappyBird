#pragma once

#include "Game.hpp"
#include "SDL.h"
#include "SDL_image.h"
#include "Sprite.hpp"

class Bird {
private:
	float posX;
	float posY;
	float vel = 0;
	float accel = 1;
	float terminalV = 10;

	Sprite sprite;

public:
	Bird() = default;

	void init(int x, int y, int s) {
		posX = x;
		posY = y;
		sprite.init("assets/bird/idle.png", x, y, 32, 32, s);
	}

	void restart(int x, int y, int s) {
		posX = x;
		posY = y;
		vel = 0;
		accel = 1;
	}

	SDL_Rect& update() { 
		posY += vel;
		if (vel <= terminalV) {
			vel += accel;
		}
		return sprite.update(posX, posY); 
	}
	void draw() { sprite.draw(); }

	void addVel(int v) {
		vel += v;
	}

	float getVel() {
		return vel;
	}
};