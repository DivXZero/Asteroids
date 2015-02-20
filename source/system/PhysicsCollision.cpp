
#include "system/PhysicsCollision.h"

void PhysicsCollision::BeginContact(b2Contact* contact)
{
	PhysicsObject* object = static_cast<PhysicsObject*>(contact->GetFixtureA()->GetBody()->GetUserData());
	if (object)
		object->startContact();

	object = static_cast<PhysicsObject*>(contact->GetFixtureB()->GetBody()->GetUserData());
	if (object)
		object->startContact();
}

void PhysicsCollision::EndContact(b2Contact* contact)
{
	PhysicsObject* object = static_cast<PhysicsObject*>(contact->GetFixtureA()->GetBody()->GetUserData());
	if (object)
		object->endContact();

	object = static_cast<PhysicsObject*>(contact->GetFixtureB()->GetBody()->GetUserData());
	if (object)
		object->endContact();
}