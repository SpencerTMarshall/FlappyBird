#include "Game.hpp"
#include <iostream>
#include "Bird.hpp"
#include "PipeManager.hpp"

SDL_Renderer* Game::renderer;
SDL_Event Game::events;

Bird bird;
Manager manager;

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
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	bird.init(200, 150, 1);
}

void Game::restart() {
	bird.restart(200, 150, 1);
	manager.restart();

	isDead = false;
}

void Game::handleEvents() {
	SDL_PollEvent(&events);

	switch (events.type) {
	case SDL_MOUSEBUTTONDOWN:
		if (bird.getVel() >= 0) {
			bird.addVel(-20);
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

	manager.refresh();
	isDead = manager.AABB(bird.update());

	manager.update();
}

void Game::render() {
	SDL_RenderClear(renderer);
	bird.draw();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned...\n";
}