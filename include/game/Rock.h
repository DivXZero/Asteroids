
#ifndef ASTEROIDS_ROCK_H
#define ASTEROIDS_ROCK_H

#include "system/GameObject.h"

class Rock : public GameObject
{
public:
	Rock() : m_Scale(1.0f) {}
	~Rock() {}

	void init();
	void update();
	void render();
	void cleanup();

	void setScale(float scale) { m_Scale = scale; setAsBox(60.0f / m_Scale, 60.0f / m_Scale); }
	float getScale() { return m_Scale; }
	void set(float scale, sf::Vector2f pos, float angle);
	void set(float scale);

private:
	void checkOffscreen();
	float m_Scale;
};

#endif