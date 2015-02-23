
#ifndef ASTEROIDS_SCENE_H
#define ASTEROIDS_SCENE_H

#include "system/Scene.h"
#include "game/Ship.h"
#include "game/Rock.h"

#define MAX_ROCKS 200

class GameScene : public Scene
{
public:
	GameScene() {}
	~GameScene() {}

	void init();
	void update();
	void render();

private:
	sf::SoundBuffer m_explodeBuffer1;
	sf::SoundBuffer m_explodeBuffer2;
	sf::SoundBuffer m_explodeBuffer3;
	sf::Sound m_explodeSound1;
	sf::Sound m_explodeSound2;
	sf::Sound m_explodeSound3;
};

#endif	// ASTEROIDS_SCENE_H