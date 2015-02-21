
#ifndef ASTEROIDS_SCENE_H
#define ASTEROIDS_SCENE_H

#include "system/Scene.h"
#include "game/Ship.h"
#include "game/Rock.h"

#define MAX_ROCKS 500

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
	Object<Rock> m_rockObject[MAX_ROCKS];
};

#endif	// ASTEROIDS_SCENE_H