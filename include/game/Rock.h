
#ifndef ASTEROIDS_ROCK_H
#define ASTEROIDS_ROCK_H

#include <SFML/Audio.hpp>
#include "system/GameObject.h"

class Rock : public GameObject
{
public:
	Rock() {}
	~Rock() {}

	void init();
	void update();
	void render();
	void cleanup();

private:
	void checkOffscreen();
	int m_colorFade;
	sf::SoundBuffer m_explodeBuffer;
	sf::Sound m_explodeSound;
};

#endif