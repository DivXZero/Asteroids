
#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H

#include "system/GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet() {}
	Bullet(SharedScene* ownerScene, b2Vec2 pos, float angle) { init(ownerScene, pos, angle); }
	~Bullet() {}

	void init(SharedScene* ownerScene, b2Vec2 pos, float angle);
	void update();

private:
	void checkOffscreen();
};

#endif