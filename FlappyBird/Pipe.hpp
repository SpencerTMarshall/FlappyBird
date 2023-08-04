#pragma once

#include "Sprite.hpp"

class Pipe {
private:
	float posX;
	float vel;
	int botY;

public:
	Sprite topSprite;
	Sprite botSprite;

	const static int gap = 150;

	Pipe(float x, int by, int w, float v);
	~Pipe();

	int getX() { return static_cast<int>(posX); }

	void update();
	void draw();
};