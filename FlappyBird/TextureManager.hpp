#pragma once
#include "Game.hpp"
#include <iostream>


struct TextureManager {
	static SDL_Texture* Load(const char* fileName) {
		SDL_Surface* tempSurface = IMG_Load(fileName);
		SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);

		SDL_FreeSurface(tempSurface);

		return tex;
	}

	static void Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
		int x = SDL_RenderCopy(Game::renderer, tex, &src, &dest);
	}
};