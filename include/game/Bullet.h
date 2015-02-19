
#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H

#include "system/GameObject.h"

#define BULLET_SPEED 2000
#define BULLET_LIFETIME 1000

class Bullet : public GameObject
{
public:
	Bullet() {}
	Bullet(SharedScene* ownerScene, b2Vec2 pos, float angle) { init(ownerScene, pos, angle); }
	~Bullet();

	void init(SharedScene* ownerScene, b2Vec2 pos, float angle);
	void update();
	int getLifeTime() { return m_lifeTime; }

private:
	void checkOffscreen();
	int m_lifeTime;
};

#endif