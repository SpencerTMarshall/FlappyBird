#include "Pipe.hpp"

#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 640
#endif

Pipe::Pipe(float x, int by, int w, float v) : posX{ x }, botY{ by }, vel { v } {
	topSprite.init("assets/pipe.png", x, 0, w, botY - gap, 1);
	botSprite.init("assets/pipe.png", x, botY, w, SCREEN_HEIGHT - botY, 1);
}

Pipe::~Pipe() {
	delete& topSprite;
	delete& botSprite;
}

void Pipe::update() {
	posX += vel;

	topSprite.update(posX);
	botSprite.update(posX);
}

void Pipe::draw() {
	topSprite.draw();
	botSprite.draw();
}

#undef SCREEN_HEIGHT