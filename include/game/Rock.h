
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

	void set(float scale);
	float getScale() { return m_Scale; }

private:
	void checkOffscreen();
	int m_colorFade;
	float m_Scale;

	sf::SoundBuffer m_explodeBuffer;
	sf::Sound m_explodeSound;
};

#endif