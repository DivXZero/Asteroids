
#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H

#include "system/GameObject.h"

#define ACCELERATION 20.0f
#define ROTATION 5.0f

class Ship : public GameObject
{
public:
	Ship() {}
	~Ship() {}

	void init(SharedScene* ownerScene);
	void update();
	void render();

private:
	void handleInput();
	void checkOffscreen();
};

#endif