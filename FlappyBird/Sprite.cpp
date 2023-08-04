#include "Sprite.hpp"

void Sprite::init(const char* path, int x, int y, int w, int h, int s) {
	texture = TextureManager::Load(path);

	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = w;
	srcRect.h = h;

	destRect.x = x;
	destRect.y = y;
	destRect.w = w * s;
	destRect.h = h * s;
}

Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
}

void Sprite::setTex(const char* path) {
	SDL_DestroyTexture(texture);
	texture = TextureManager::Load(path);
}

void Sprite::draw() {
	TextureManager::Draw(texture, srcRect, destRect);
}

SDL_Rect& Sprite::update(float x, float y) {
	destRect.x = static_cast<int> (x);
	destRect.y = static_cast<int> (y);

	return destRect;
}

void Sprite::update(float x) {
	destRect.x = static_cast<int> (x);
}