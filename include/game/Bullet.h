
#ifndef ASTEROIDS_BULLET_H
#define ASTEROIDS_BULLET_H

#include <glm/glm.hpp>
#include "system/GameObject.h"

#define BULLET_SPEED 2000
#define BULLET_LIFETIME 400

class Bullet : public GameObject
{
public:
	Bullet() : m_isAlive(false) {}
	Bullet(SharedScene* ownerScene, b2Vec2 pos, float angle) { init(ownerScene, pos, angle); }
	~Bullet();

	void init(SharedScene* ownerScene, b2Vec2 pos, float angle);
	void update();
	int getLifeTime() { return m_lifeTime; }
	bool isAlive() { return m_isAlive; }
	void kill();

private:
	void checkOffscreen();
	int m_lifeTime;
	bool m_isAlive;
};

#endif