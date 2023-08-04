#pragma once

#include "Game.hpp"
#include <string>
#include <iostream>

class Score {
private:
	TTF_Font* comic_shanns;
	SDL_Color White = { 255, 255, 255 };
	SDL_Rect dest;
	int score;

public:
	void init() { 
		TTF_CloseFont(comic_shanns);
		
		comic_shanns = TTF_OpenFont("assets/comic_shanns.ttf", 24);

		score = 0; 

		dest.x = 0;
		dest.y = 0;
		dest.w = 50;
		dest.h = 50;
	}

	void add(int x) { score += x; }

	void draw() {
		SDL_Surface* surface = TTF_RenderText_Solid(comic_shanns, std::to_string(score).c_str(), White);

		SDL_Texture* message = SDL_CreateTextureFromSurface(Game::renderer, surface);

		SDL_RenderCopy(Game::renderer, message, NULL, &dest);

		SDL_FreeSurface(surface);
		SDL_DestroyTexture(message);
	}

	int getScore() { return score; }
};