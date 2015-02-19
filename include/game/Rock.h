
#ifndef ASTEROIDS_ROCK_H
#define ASTEROIDS_ROCK_H

#include "system/GameObject.h"

class Rock : public GameObject
{
public:
	Rock() {}
	~Rock() {}

	void init(SharedScene* ownerScene);
	void update();
	void render();

private:
	void checkOffscreen();
};

#endif