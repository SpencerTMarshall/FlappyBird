#include "Pipe.hpp"
#include <vector>

class Manager {
private:
	std::vector<Pipe*> pipeList{};
	float vel = -5.0f;
	int width = 100;
	float startX = 900.0f;

	int getBot();
	
public:
	Manager();
	void restart();

	void update();
	void draw();
	int refresh();
	void createPipe();

	bool AABB(SDL_Rect& bird);
};