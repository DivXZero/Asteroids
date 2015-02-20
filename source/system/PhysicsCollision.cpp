
#include "system/PhysicsCollision.h"

void PhysicsCollision::BeginContact(b2Contact* contact)
{
	PhysicsObject* object1 = static_cast<PhysicsObject*>(contact->GetFixtureA()->GetBody()->GetUserData());
	PhysicsObject* object2 = static_cast<PhysicsObject*>(contact->GetFixtureB()->GetBody()->GetUserData());

	if (object1 && object2)
	{
		object1->startContact(object2);
		object2->startContact(object1);
	}
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