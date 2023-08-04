#include "Game.hpp"
#include <iostream>
#include "Bird.hpp"
#include "PipeManager.hpp"
#include "Score.hpp"
#include <string>
#include <iostream>

SDL_Renderer* Game::renderer;
SDL_Event Game::events;

Bird bird;
Manager manager;
Score score;

void Game::startMenu() {
	TTF_Font* comic_shanns = TTF_OpenFont("assets/comic_shanns.ttf", 24);
	SDL_Color White = { 255, 255, 255 };

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(comic_shanns, "Press space to start!", White);
	SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

	SDL_Rect messageRect;
	messageRect.x = 150;
	messageRect.y = 200;
	messageRect.w = 500;
	messageRect.h = 100;

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, Message, NULL, &messageRect);
	SDL_RenderPresent(renderer);

	SDL_PollEvent(&events);

	while (events.key.keysym.sym != ' ') {
		if (events.type == SDL_QUIT) {
			isRunning = false;
			break;
		}
		SDL_PollEvent(&events);
	}

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
	TTF_CloseFont(comic_shanns);
}

void Game::init(const char* title, int xpos, int ypos, int width, int height) {
	isDead = false;
	
	if (SDL_Init(SDL_INIT_EVERYTHING) != NULL) {
		std::cout << "Subsystems failed to initialize...\n";
		isRunning = false;
		return;
	}
	
	if (SDL_CreateWindowAndRenderer(width, height, NULL, &window, &renderer) != NULL) {
		std::cout << "Error creating window and renderer...\n";
	}
	
	isRunning = true;
	TTF_Init();
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	bird.init(200, 150, 1);
	score.init();
}

void Game::restart() {
	std::cout << "You scored: " << std::to_string(score.getScore()) << "\n";
	bird.restart(200, 150, 1);
	manager.restart();
	score.init();

	isDead = false;
}

void Game::handleEvents() {
	SDL_PollEvent(&events);

	switch (events.type) {
	case SDL_MOUSEBUTTONDOWN:
		if (bird.getVel() >= 0) {
			bird.setVel(-10);
		}
		break;
	case SDL_QUIT:
		isRunning = false;
		break;
	}
}

int seconds_to_spawn = 1;

int count = seconds_to_spawn * 60;
void Game::update() {
	if (count == 0) {
		manager.createPipe();
		count = seconds_to_spawn * 60;
	}
	else {
		count--;
	}

	score.add(manager.refresh());
	isDead = manager.AABB(bird.update());

	manager.update();
}

void Game::render() {
	SDL_RenderClear(renderer);
	bird.draw();
	manager.draw();
	score.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned...\n";
}