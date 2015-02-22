
#ifndef ASTEROIDS_SCENE_H
#define ASTEROIDS_SCENE_H

#include "system/Scene.h"
#include "game/Ship.h"
#include "game/Rock.h"

class GameScene : public Scene
{
public:
	GameScene() {}
	~GameScene() {}

	void init();
	void update();
	void render();

private:
	Object<Ship> m_ship;
};

#endif	// ASTEROIDS_SCENE_H