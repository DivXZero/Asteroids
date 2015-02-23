
#ifndef ASTEROIDS_SCENE_H
#define ASTEROIDS_SCENE_H

#include "system/Scene.h"
#include "game/Ship.h"
#include "game/Rock.h"

#define MAX_ROCKS 25

class GameScene : public Scene
{
public:
	GameScene() {}
	~GameScene() {}

	void init();
	void update();
	void render();
};

#endif	// ASTEROIDS_SCENE_H