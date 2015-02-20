
#ifndef ASTEROIDS_COLLISION_H
#define ASTEROIDS_COLLISION_H

#include <Box2D/Box2D.h>
#include "system/PhysicsObject.h"

class PhysicsCollision : public b2ContactListener
{
public:
	PhysicsCollision() {}
	~PhysicsCollision() {}

	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
};

#endif