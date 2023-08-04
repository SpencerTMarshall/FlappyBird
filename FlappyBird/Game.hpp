#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <vector>

class Game {
private:
	int cnt = 0;
	bool isRunning;

public:
	void init(const char* title, int xpos, int ypos, int width, int height);
	void restart();


	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() { return isRunning; }

	static SDL_Renderer* renderer;
	SDL_Window* window;
	static SDL_Event events;

	bool isDead;
};
