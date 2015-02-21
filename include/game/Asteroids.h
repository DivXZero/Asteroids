
#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H

#include "system/Game.h"
#include "game/GameScene.h"

class Asteroids : public Game
{
public:
	Asteroids() {}
	~Asteroids() {}

	bool init();

private:
	GameScene m_mainScene;
};

#endif	// ASTEROIDS_GAME_H