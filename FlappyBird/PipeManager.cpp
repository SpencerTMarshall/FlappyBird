#include "PipeManager.hpp"
#include <cstdlib>
#include <ctime>
#include "Collision.hpp"

#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 640
#endif

void Manager::restart() {
	pipeList.clear();
}

int Manager::getBot() {
	int cap = 50+Pipe::gap;
	int low = SCREEN_HEIGHT - Pipe::gap;

	return cap + (std::rand() * (int)(low - cap) / RAND_MAX);
}

Manager::Manager() {
	std::srand(std::time(nullptr));
}

void Manager::update() {
	for (Pipe* pipe : pipeList) {
		pipe->update();
	}
}

void Manager::draw() {
	for (Pipe* pipe : pipeList) {
		pipe->draw();
	}
}

void Manager::refresh() {
	std::erase_if(pipeList, 
		[=](Pipe* a) {
			return a->getX() <= -width;
		});
}

void Manager::createPipe() {
	pipeList.push_back(new Pipe(startX, getBot(), width, vel));
}

bool Manager::AABB(SDL_Rect& bird) {
	if (bird.y < 0 || bird.y > SCREEN_HEIGHT - bird.h) return true;

	if (pipeList.size() < 2) return false;

	return Collision::AABB((*pipeList[0]).topSprite.getRect(), bird) ||
		Collision::AABB((*pipeList[0]).botSprite.getRect(), bird) ||
		Collision::AABB((*pipeList[1]).topSprite.getRect(), bird) ||
		Collision::AABB((*pipeList[1]).botSprite.getRect(), bird);
}

#undef SCREEN_HEIGHT