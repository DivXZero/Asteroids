
#ifndef ASTEROIDS_PHYSICS_H
#define ASTEROIDS_PHYSICS_H

#include <Box2D/Box2D.h>
#include "system/PhysicsCollision.h"

class Physics
{
public:
	Physics();
	~Physics();

	b2World* world() { return m_World; }

	static const float Scale;

private:
	b2World* m_World;
	b2Vec2 m_Gravity;
	PhysicsCollision m_CollisionListener;
};

#endif	// ASTEROIDS_PHYSICS_H