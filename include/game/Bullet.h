
#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H

#include "system/GameObject.h"

#define BULLET_SPEED 2000
#define BULLET_LIFETIME 400

class Bullet : public GameObject
{
public:
	Bullet() {}
	~Bullet() {}

	void init();
	void set(b2Vec2 pos, float angle);
	void update();
	void render();
	void cleanup();
	int getLifeTime() { return m_lifeTime; }

private:
	void checkOffscreen();
	int m_lifeTime;
};

#endif