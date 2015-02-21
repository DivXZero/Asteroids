
#ifndef ASTEROIDS_SHIP_H
#define ASTEROIDS_SHIP_H

#include <SFML/Audio.hpp>
#include "game/Rock.h"
#include "game/Bullet.h"
#include "system/GameObject.h"
#include <vector>

#define ACCELERATION 20.0f
#define ROTATION 5.0f
#define FIRE_DELAY 30

class Ship : public GameObject
{
public:
	Ship() {}
	~Ship() {}

	void init();
	void update();
	void render();

private:
	void handleInput();
	void checkOffscreen();
	std::vector<Bullet*> m_Bullets;
	int m_fireDelay;
	sf::SoundBuffer m_bulletBuffer;
	sf::Sound m_bulletSound;
};

#endif