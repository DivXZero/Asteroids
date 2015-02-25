
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

#define START_DELAY 400
#define BLINK_DELAY 25

#define THUMP_DELAY 65

#define THRUST_DELAY 5

class Thruster : public RenderableObject
{
public:
	Thruster() {}
	~Thruster() {}

	void init();
	void update();
	void render();
	void cleanup();
	void destroy() {}

	void set(sf::Vector2f pos, float angle);
};

class Ship : public GameObject
{
public:
	Ship() {}
	~Ship() {}

	void init() final;
	void update();
	void render();
	void cleanup();

private:
	void handleInput();
	void checkOffscreen();
	void reset();

	int m_fireDelay;
	int m_blinkDelay;
	int m_blinkTime;
	bool m_isBlinking;
	int m_lives;
	sf::SoundBuffer m_bulletBuffer;
	sf::Sound m_bulletSound;

	sf::SoundBuffer m_thrustBuffer;
	sf::Sound m_thrustSound;

	sf::SoundBuffer m_thumpLoBuffer;
	sf::SoundBuffer m_thumpHiBuffer;
	sf::Sound m_thumpLoSound;
	sf::Sound m_thumpHiSound;
	int m_thumpTime;
	bool m_thumpSwitch;

	Thruster m_Thruster;
	bool m_thrustSwitch;
	bool m_isThrusting;
};

#endif