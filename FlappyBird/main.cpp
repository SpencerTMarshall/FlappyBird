#include <cstdint>
#include "SDL.h"
#include "Game.hpp"

int main(int argc, char* argv[]) {
	const float FRAMEDELAY = 1000 / 60;

	uint32_t frameStart;
	uint32_t frameTime;

	Game* game = new Game();
	game->init("FlappyBird", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640);

	firstScreen:
	while (game->running()) {
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (FRAMEDELAY > frameTime) {
			SDL_Delay(FRAMEDELAY - frameTime);
		}

		if (game->isDead) {
			game->restart();
			goto firstScreen;
		}
	}

	game->clean();

	return 0;
}