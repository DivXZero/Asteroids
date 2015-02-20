
#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H

#include "system/Game.h"
#include "GameScene.h"

class Asteroids : public Game
{
public:
	Asteroids() {}
	~Asteroids() {}

	bool init();
};

#endif	// ASTEROIDS_GAME_H