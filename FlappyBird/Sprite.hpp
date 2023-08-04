#pragma once

#include "SDL.h"
#include "TextureManager.hpp"

class Sprite {
private:
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	~Sprite();

	void init (const char* path, int x, int y, int w, int h, int s);

	void setTex(const char* path);

	void draw();

	SDL_Rect& getRect() { return destRect; }
	
	SDL_Rect& update(float x, float y);

	void update(float x);
};
